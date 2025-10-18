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