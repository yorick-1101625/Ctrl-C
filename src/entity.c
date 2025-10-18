#include "raylib.h"
#include "entity.h"

void entity_draw(entity_t *e) {
    DrawTexture(e->texture, e->rect.x, e->rect.y, WHITE);
}