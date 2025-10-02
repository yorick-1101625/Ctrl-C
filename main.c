#include "raylib.h"
#include "player.h"
#include <stdio.h>
#include "constants.h"

int main() {    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ctrl-C");
    
    // Player Image
    Image player_image = LoadImage("assets/Varken.png");
    ImageResize(&player_image, 200, 200);
    Texture2D player_texture = LoadTextureFromImage(player_image);
    
    player_t player = {
        .position = { 0, 0 },
        .size = { 50, 50 },
        .direction = { 0, 0 },
        .speed = 200.0f,
        .texture = player_texture
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