#include "raylib.h"
#include "player.h"
#include "constants.h"
#include "entity.h"
#include "projectile.h"

int main() {    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ctrl-C");
    
    // Player
    Vector2 player_position = { 0, 0 };
    Vector2 player_size = { 150, 150 };
    // Player image
    Image player_image = LoadImage("assets/Varken.png"); // Original size: 100x100, 1:1
    ImageResize(&player_image, player_size.x, player_size.y);
    Texture2D player_texture = LoadTextureFromImage(player_image);
    // Create Player
    entity_t player = entity_init(player_position, player_size, player_texture);
    
    // Projectile
    Vector2 projectile_position = { 500, 500 };
    Vector2 projectile_size = { 70, 46 };
    // Projectile image
    Image projectile_image = LoadImage("assets/gas.png"); // Original size: 2000x1358, 3:2
    ImageResize(&projectile_image, projectile_size.x, projectile_size.y);
    ImageRotateCCW(&projectile_image);
    Texture2D projectile_texture = LoadTextureFromImage(projectile_image);
    // Create Projectile
    entity_t projectile_1 = entity_init(projectile_position, projectile_size, projectile_texture);
    projectile_1.direction.y = -1;
    
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
    
    CloseWindow();
    
    return 0;
}