#include "raylib.h"

int main() {
    
    typedef struct {
        Vector2 position;
        Vector2 size;
        float speed;
    } player_t;
    
    
    InitWindow(800, 450, "Ctrl-C");
    
    player_t player = {
        .position = { 0, 0 },
        .size = { 50, 50 },
        .speed = 30.0f
    };
    
    Vector2 position = { 0, 0 };
    Vector2 size = { 50, 50 };
    
    while(!WindowShouldClose()) {
        float dt = GetFrameTime();
        
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        if (IsKeyDown('D')) {
            player.position.x += player.speed * dt;
        }
        
        DrawRectangleV(player.position, player.size, RED);
        
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}