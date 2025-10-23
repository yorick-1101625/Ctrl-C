#ifndef APPLE_H
#define APPLE_H
#include "entity.h"

entity_t apple_init(Vector2 position, Texture2D texture);
void apple_update(entity_t *a, float dt);

#endif