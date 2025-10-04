#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    Vector2 position;
    Vector2 size;
    Vector2 direction;
    int speed;
    Texture2D texture;
} player_t;

void player_update(player_t *p, float dt);
void player_draw(player_t *p);
player_t player_init(Vector2 position, Vector2 size, Texture2D texture);

#endif