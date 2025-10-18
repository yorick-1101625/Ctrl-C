#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "entity.h"

entity_t projectile_init(Vector2 position, Texture2D texture);
void projectile_update(entity_t *p, float dt);

#endif