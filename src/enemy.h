#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"

entity_t enemy_init(Vector2 position, Texture2D texture);
void enemy_update(entity_t *e, float dt);

#endif