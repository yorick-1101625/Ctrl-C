#include "raylib.h"
#include "apple.h"

void apple_move(entity_t *a, float dt);

void apple_update(entity_t *a, float dt) {
    
    apple_move(a, dt);
}

void apple_move(entity_t *a, float dt) {
    a->rect.x += a->speed * a->direction.x * dt;
    a->rect.y += a->speed * a->direction.y * dt;
}

entity_t apple_init(Vector2 position, Texture2D texture) {
    
    Vector2 direction = { 0, 1 };
    int speed = 200;
    return entity_init(position, texture, direction, speed);
}
