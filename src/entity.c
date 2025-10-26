#include "raylib.h"
#include "entity.h"
#include "stdlib.h"

void entity_draw(entity_t *e) {
    DrawTexture(e->texture, e->rect.x, e->rect.y, WHITE);
}
// remove?
entity_t *init_entity_array() {
    entity_t *array = malloc(sizeof(entity_t));
    if (array == NULL) {
        return NULL;
    }
    
    return array;
}

entity_t *add_entity(entity_t *array, entity_t new_entity, int total_number_of_entities) {
    
    int new_size = sizeof(entity_t) * total_number_of_entities;
    
    array = realloc(array, new_size);
    if (array == NULL) {
        return NULL;
    }
    
    array[new_size / sizeof(entity_t) - 1] = new_entity;
    
    return array;
}

entity_t entity_init(Vector2 position, Texture2D texture, Vector2 direction, int speed) {
    Rectangle rect = { position.x, position.y, texture.width, texture.height };
    
    // Create Entity    
    entity_t new_entity = {
        .texture = texture,
        .speed = speed,
        .direction = direction,
        .rect = rect,
    };
    
    return new_entity;
}