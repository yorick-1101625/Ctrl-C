#ifndef ENTITY_H
#define ENTITY_H

typedef struct {
    Vector2 direction;
    int speed;
    Texture2D texture;
    Rectangle rect;
} entity_t;

void entity_draw(entity_t *e);
entity_t entity_init(Vector2 position, Vector2 size, Texture2D texture);
entity_t *init_entity_array();
entity_t *add_entity(entity_t *array, entity_t new_entity, int total_number_of_entities);

#endif