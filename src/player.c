#include "raylib.h"
#include "player.h"
#include "constants.h"
#include "projectile.h"

void player_move(entity_t *p, float dt);
void player_check_input(entity_t *p);

void player_update(entity_t *p, float dt) {
    
    player_check_input(p);
    player_move(p, dt);
}

void player_move(entity_t *p, float dt) {
    p->rect.x += p->speed * p->direction.x * dt;
    p->rect.y += p->speed * p->direction.y * dt;
    
    // Set movement boundaries
    if (p->rect.x + p->rect.width > SCREEN_WIDTH) {
        p->rect.x = SCREEN_WIDTH - p->rect.width;
    }
    else if (p->rect.x < 0) {
        p->rect.x = 0;
    }
    if (p->rect.y + p->rect.height > SCREEN_HEIGHT) {
        p->rect.y = SCREEN_HEIGHT - p->rect.height;
    }
    else if (p->rect.y < 0) {
        p->rect.y = 0;
    }
}

void player_check_input(entity_t *p) {
    
    p->direction.x = 0;
    p->direction.y = 0;
    
    // Horizontal
    if (IsKeyDown('D')) {
        p->direction.x += 1;
    }
    if (IsKeyDown('A')) {
        p->direction.x -= 1;
    }
    
    // Vertical
    if (IsKeyDown('W')) {
        p->direction.y -= 1;
    }
    if (IsKeyDown('S')) {
        p->direction.y += 1;
    }
    
    // Shoot projectile
    if (IsKeyDown('SPACE')) {
        
    }
}

entity_t player_init() {
    
    Vector2 position = { 0, 0 };
    Vector2 size = { 150, 150 };
    Rectangle rect = { position.x, position.y, size.x, size.y };
    // Image
    Image image = LoadImage("assets/Varken.png"); // Original size: 100x100, 1:1
    ImageResize(&image, size.x, size.y);
    Texture2D texture = LoadTextureFromImage(image);
    // Create Player    
    entity_t new_player = {
        .texture = texture,
        .speed = 200,
        .direction = { 0, 0 },
        .rect = rect,
    };
    
    return new_player;
}