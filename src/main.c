#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "constants.h"
#include "entity.h"
#include "projectile.h"
#include <stdio.h>

Texture2D *load_textures();

int main() {    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ctrl-C");
    
    Texture2D *textures = load_textures();
    if (textures == NULL) {
        CloseWindow();
        return 1;
    }
    
    entity_t *all_projectiles = NULL;
    int projectile_count = 0;
    

    entity_t player = player_init((Vector2){SCREEN_WIDTH / 2,SCREEN_HEIGHT}, textures[0]);
    
    
    while(!WindowShouldClose()) {
        float dt = GetFrameTime();
        
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        
        
        if (IsKeyReleased('K')) {
            Vector2 projectile_position = { player.rect.x, player.rect.y + player.texture.height / 2 };
            entity_t new_projectile = projectile_init(projectile_position, textures[1]);
            
            projectile_count += 1;
            all_projectiles = add_entity(all_projectiles, new_projectile, projectile_count);
            if (all_projectiles == NULL) {
                free(textures);
                CloseWindow();
                return 1;
            }
            
        }
        
        // Player
        player_update(&player, dt);
        entity_draw(&player);
        
        // Projectiles
        for (int i = 0;  i < projectile_count; i++) {
            projectile_update(&all_projectiles[i], dt);
            entity_draw(&all_projectiles[i]);
        }
        EndDrawing();
    }
    
    free(textures);
    free(all_projectiles);
    CloseWindow();
    
    return 0;
}

Texture2D *load_textures() {
    Texture2D *textures = malloc(sizeof(Texture2D) * 2);
    if (textures == NULL) {
        return NULL;
    }
    
    // Player texture
    Image player_image = LoadImage("assets/Varken.png");
    ImageResize(&player_image, player_image.width * 2, player_image.height * 2);
    textures[0] = LoadTextureFromImage(player_image);
    
    // Projectile texture
    Image projectile_image = LoadImage("assets/gas.png");
    ImageResize(&projectile_image, projectile_image.width / 20, projectile_image.height / 20);
    ImageRotateCCW(&projectile_image);
    textures[1] = LoadTextureFromImage(projectile_image);
    
    return textures;
}
