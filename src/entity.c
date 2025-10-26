#include "raylib.h"
#include "entity.h"
#include "stdlib.h"

void entity_draw(entity_t *e) {
    DrawTexture(e->texture, e->rect.x, e->rect.y, WHITE);
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

entity_t *add_entity(entity_t *array, entity_t new_entity, int number_of_elements) {
    
    int new_size = sizeof(entity_t) * number_of_elements;
    
    entity_t *tmp = realloc(array, new_size);
    if (tmp == NULL) {
        return NULL;
    }
    
    tmp[new_size / sizeof(entity_t) - 1] = new_entity;
    
    return tmp;
}

entity_t *remove_entity(entity_t *array, int index, int number_of_elements) {
    // Move elements
    for (int i = index; i < number_of_elements - 1; i++) {
        array[i] = array[i + 1];
    }
    
    int new_size = sizeof(entity_t) * (number_of_elements - 1);
    
    entity_t *tmp = realloc(array, new_size);
    if (tmp == NULL) {
       return NULL;
    }
    
    return tmp;
}