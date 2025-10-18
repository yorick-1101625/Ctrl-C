#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "entity.h"

entity_t projectile_init();
void projectile_update(entity_t *p, float dt);

#endif