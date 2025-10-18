#include "raylib.h"
#include "projectile.h"

void projectile_move(entity_t *p, float dt);

void projectile_update(entity_t *p, float dt) {
    
    projectile_move(p, dt);
}

void projectile_move(entity_t *p, float dt) {
    p->rect.x += p->speed * p->direction.x * dt;
    p->rect.y += p->speed * p->direction.y * dt;
}

entity_t projectile_init(Vector2 position, Texture2D texture) {
    
    Rectangle rect = { position.x, position.y, texture.width, texture.height };
    
    // Create Projectile    
    entity_t new_projectile = {
        .texture = texture,
        .speed = 200,
        .direction = { 0, -1 },
        .rect = rect,
    };
    
    return new_projectile;
}
