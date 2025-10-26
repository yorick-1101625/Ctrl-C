#ifndef ENTITY_H
#define ENTITY_H

typedef struct {
    Vector2 direction;
    int speed;
    Texture2D texture;
    Rectangle rect;
} entity_t;

void entity_draw(entity_t *e);
entity_t entity_init(Vector2 position, Texture2D texture, Vector2 direction, int speed);
entity_t *init_entity_array();

// Arrays
entity_t *add_entity(entity_t *array, entity_t new_entity, int number_of_elements);
entity_t *remove_entity(entity_t *array, int index, int number_of_elements);

#endif