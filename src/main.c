#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "constants.h"
#include "entity.h"
#include "projectile.h"

Texture2D *load_textures();

int main() {    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ctrl-C");
    
    Texture2D *textures = load_textures();
    if (textures == NULL) {
        CloseWindow();
        return 1;
    }
    
    
    entity_t player = player_init((Vector2){0,0}, textures[0]);
    
    entity_t projectile_1 = projectile_init((Vector2){500,500}, textures[1]);
    
    while(!WindowShouldClose()) {
        float dt = GetFrameTime();
        
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        player_update(&player, dt);
        projectile_update(&projectile_1, dt);
        
        entity_draw(&player);
        entity_draw(&projectile_1);
        
        EndDrawing();
    }
    
    free(textures);
    CloseWindow();
    
    return 0;
}

Texture2D *load_textures() {
    Texture2D *textures = malloc(sizeof(Texture2D) * 2);
    if (textures == NULL) {
        return NULL;
    }
    
    // Player texture
    Image player_image = LoadImage("assets/Varken.png"); // Original size: 100x100, 1:1
    ImageResize(&player_image, 150, 150);
    textures[0] = LoadTextureFromImage(player_image);
    
    // Projectile texture
    Image projectile_image = LoadImage("assets/gas.png"); // Original size: 2000x1358, 3:2
    ImageResize(&projectile_image, 70, 46);
    ImageRotateCCW(&projectile_image);
    textures[1] = LoadTextureFromImage(projectile_image);
    
    return textures;
}


void shoot_projectile() {
    //projectile_init(projectile_texture);
}