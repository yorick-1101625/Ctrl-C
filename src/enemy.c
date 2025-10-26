#include "raylib.h"
#include "enemy.h"
#include "constants.h"

void enemy_move(entity_t *e, float dt);

void enemy_update(entity_t *e, float dt) {
    
    enemy_move(e, dt);
}

void enemy_move(entity_t *e, float dt) {
    e->rect.x += e->speed * e->direction.x * dt;
    e->rect.y += e->speed * e->direction.y * dt;
    
    // Set movement boundaries
    if (e->rect.x + e->rect.width > SCREEN_WIDTH) {
        e->direction.x = -1;
    }
    else if (e->rect.x < 0) {
        e->direction.x = 1;
    }
}

entity_t enemy_init(Vector2 position, Texture2D texture) {
    int rand_value = GetRandomValue(0, 1);
    int x_direction = rand_value > 0.5 ? 1 : -1;
    Vector2 direction = { x_direction, 0 };
    
    rand_value = GetRandomValue(1, 4);
    int speed = 50 + rand_value * 100;
    return entity_init(position, texture, direction, speed);
}