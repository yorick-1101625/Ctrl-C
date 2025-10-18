#include "raylib.h"
#include "player.h"
#include "constants.h"
#include "entity.h"
#include "projectile.h"

int main() {    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ctrl-C");
    
    entity_t player = player_init();
    
    entity_t projectile_1 = projectile_init();
    
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