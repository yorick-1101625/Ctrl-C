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

entity_t *add_entity(entity_t *array, entity_t new_entity) {
    
    int new_size = sizeof(array) + sizeof(entity_t);
    
    array = realloc(array, new_size);
    if (array == NULL) {
        return NULL;
    }
    
    array[new_size / sizeof(entity_t) - 1] = new_entity;
    
    return array;
}