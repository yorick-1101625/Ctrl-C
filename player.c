#include "raylib.h"
#include "player.h"
#include "constants.h"
#include <stdio.h>

void player_move(player_t *p, float dt);
void player_check_input(player_t *p);

player_t player_init(Vector2 position, Vector2 size, Texture2D texture) {
    Rectangle rect = { position.x, position.y, size.x, size.y };
    
    player_t new_player = {
        .texture = texture,
        .speed = 200,
        .direction = { 0, 0 },
        .rect = rect,
    };
    
    return new_player;
}

void player_update(player_t *p, float dt) {
    
    player_check_input(p);
    player_move(p, dt);
}

void player_draw(player_t *p) {
    DrawTexture(p->texture, p->rect.x, p->rect.y, WHITE);
    DrawRectangleRec(p->rect, RED);
}

void player_move(player_t *p, float dt) {
    p->rect.x += p->speed * p->direction.x * dt;
    p->rect.y += p->speed * p->direction.y * dt;  
    //printf("%f", p->rect.x);
    
    // Set movement boundaries
    // TODO: Ignore transparent pixels
    if (p->rect.x > SCREEN_WIDTH) {
        p->rect.x = SCREEN_WIDTH;
    }
    else if (p->rect.x < 0) {
        p->rect.x = 0;
    }
    if (p->rect.y > SCREEN_HEIGHT) {
        p->rect.y = SCREEN_HEIGHT;
    }
    else if (p->rect.y < 0) {
        p->rect.y = 0;
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