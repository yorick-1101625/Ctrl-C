#include "raylib.h"
#include "entity.h"

entity_t entity_init(Vector2 position, Vector2 size, Texture2D texture) {
    Rectangle rect = { position.x, position.y, size.x, size.y };
    
    entity_t new_entity = {
        .texture = texture,
        .speed = 200,
        .direction = { 0, 0 },
        .rect = rect,
    };
    
    return new_entity;
}

void entity_draw(entity_t *e) {
    DrawTexture(e->texture, e->rect.x, e->rect.y, WHITE);
}