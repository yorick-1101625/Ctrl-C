#include "raylib.h"
#include "player.h"
#include "constants.h"

void player_move(player_t *p, float dt);
void player_check_input(player_t *p);

player_t player_init(Vector2 position, Vector2 size, Texture2D texture) {
    
    player_t new_player = {
        .position = position,
        .size = size,
        .texture = texture,
        .speed = 200,
        .direction = { 0, 0 },
    };
    
    return new_player;
}

void player_update(player_t *p, float dt) {
    
    player_check_input(p);
    player_move(p, dt);
}

void player_draw(player_t *p) {
    DrawTextureV(p->texture, p->position, WHITE);
}

void player_move(player_t *p, float dt) {
    
    p->position.x += p->speed * p->direction.x * dt;
    p->position.y += p->speed * p->direction.y * dt;  
    
    // Set movement boundaries
    // TODO: Ignore transparent pixels
    if (p->position.x > SCREEN_WIDTH) {
        p->position.x = SCREEN_WIDTH;
    }
    else if (p->position.x < 0) {
        p->position.x = 0;
    }
    if (p->position.y > SCREEN_HEIGHT) {
        p->position.y = SCREEN_HEIGHT;
    }
    else if (p->position.y < 0) {
        p->position.y = 0;
    }
}

void player_check_input(player_t *p) {
    
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
}