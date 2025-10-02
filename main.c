#include "raylib.h"
#include "player.h"
#include <stdio.h>
#include "constants.h"

int main() {
       
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ctrl-C");
    
    player_t player = {
        .position = { 0, 0 },
        .size = { 50, 50 },
        .direction = { 0, 0 },
        .speed = 80.0f
    };
    
    while(!WindowShouldClose()) {
        float dt = GetFrameTime();
        
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        player_update(&player, dt);
        player_draw(&player);
        
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}