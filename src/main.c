#include "raylib.h"
#include "player.h"
#include <stdio.h>
#include "constants.h"

int main() {    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ctrl-C");
    
    // Player
    Image player_image = LoadImage("assets/Varken.png");
    ImageResize(&player_image, 200, 200);
    Texture2D player_texture = LoadTextureFromImage(player_image);
    Vector2 player_position = { 0, 0 };
    Vector2 player_size = { 50, 50 };
    // Create Player
    player_t player = player_init(player_position, player_size, player_texture);
    
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