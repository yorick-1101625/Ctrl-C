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

entity_t projectile_init() {
    // Projectile
    Vector2 position = { 500, 500 };
    Vector2 size = { 70, 46 };
    Rectangle rect = { position.x, position.y, size.x, size.y };
    // Projectile image
    Image image = LoadImage("assets/gas.png"); // Original size: 2000x1358, 3:2
    ImageResize(&image, size.x, size.y);
    ImageRotateCCW(&image);
    Texture2D texture = LoadTextureFromImage(image);
    // Create Projectile    
    entity_t new_projectile = {
        .texture = texture,
        .speed = 200,
        .direction = { 0, -1 },
        .rect = rect,
    };
    
    return new_projectile;
}