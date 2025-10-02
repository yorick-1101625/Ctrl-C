#include "raylib.h"
#include "player.h"

void player_move(player_t *p, float dt);

void player_update(player_t *p, float dt) {
    
    player_move(p, dt);
}

void player_draw(player_t *p) {
    DrawRectangleV(p->position, p->size, RED);
}

void player_move(player_t *p, float dt) {
    
    p->position.x += p->speed * p->direction.x * dt ;
    p->position.y += p->speed * p->direction.y * dt;   
}