#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"

entity_t player_init(Vector2 position, Texture2D texture);
void player_update(entity_t *p, float dt);

#endif