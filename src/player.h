#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"

entity_t player_init();
void player_update(entity_t *p, float dt);

#endif