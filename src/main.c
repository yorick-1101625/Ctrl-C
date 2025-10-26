#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "constants.h"
#include "entity.h"
#include "projectile.h"
#include <stdio.h>
#include "apple.h"
#include "enemy.h"
#include "raymath.h"

Texture2D *load_textures();
void cleanup(
    Texture2D *textures, 
    entity_t *all_projectiles,
    entity_t *all_apples, 
    entity_t *all_enemies
);
bool timer(float last_time, float cooldown);

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ctrl-C");
    
    Texture2D *textures = load_textures();
    if (textures == NULL) {
        CloseWindow();
        return 1;
    }
    
    entity_t *all_projectiles = NULL;
    int projectile_count = 0;
    
    entity_t *all_apples = NULL;
    int apple_count = 0;
    float apple_spawn_cooldown = 3.0;
    float last_apple_spawn_time = 0.0;
    
    entity_t *all_enemies = NULL;
    int enemy_count = 0;
    float enemy_spawn_cooldown = 2.0;
    float last_enemy_spawn_time = 0.0;
    

    entity_t player = player_init((Vector2){SCREEN_WIDTH / 2,SCREEN_HEIGHT}, textures[0]);
    int player_lives = 3;
            
    bool is_running = true;
    
    while(is_running) {
        is_running = !WindowShouldClose();
        float dt = GetFrameTime();
        
        if (IsKeyReleased('K')) {
            Vector2 projectile_position = { player.rect.x, player.rect.y + player.texture.height / 2 };
            entity_t new_projectile = projectile_init(projectile_position, textures[1]);
            
            projectile_count += 1;
            all_projectiles = add_entity(all_projectiles, new_projectile, projectile_count);
            if (all_projectiles == NULL) {
                cleanup(textures, all_projectiles, all_apples, all_enemies);
                return 1;
            }
            // extract to function and give function to player_update as argument?
        }
        
        // Enemy Spawning
        if (timer(last_enemy_spawn_time, enemy_spawn_cooldown)) {
            last_enemy_spawn_time = GetTime();
            
            entity_t new_enemy = enemy_init((Vector2){SCREEN_WIDTH / 2, 100}, textures[3]);
            enemy_count += 1;
            all_enemies = add_entity(all_enemies, new_enemy, enemy_count);
            if (all_enemies == NULL) {
                cleanup(textures, all_projectiles, all_apples, all_enemies);
                return 1;
            }
        }
        
        // Apple spawning
        if (timer(last_apple_spawn_time, apple_spawn_cooldown)) {
            last_apple_spawn_time = GetTime();
            if (apple_spawn_cooldown > 0.5) {
                apple_spawn_cooldown -= 0.1;
            }
            
            // Spawn an apple on each enemy
            for (int i = 0; i < enemy_count; i++) {
                Vector2 enemy_position = {all_enemies[i].rect.x, all_enemies[i].rect.y};
                entity_t new_apple = apple_init(enemy_position, textures[2]);
                apple_count += 1;
                all_apples = add_entity(all_apples, new_apple, apple_count);
                if (all_apples == NULL) {
                    cleanup(textures, all_projectiles, all_apples, all_enemies);
                    return 1;
                }
            }
        }
        
        // Collisions
        // Player Projectile / Enemy
        for (int i = 0; i < projectile_count; i++) {
            for (int j = 0; j < enemy_count; j++) {
                bool collision = CheckCollisionRecs(all_projectiles[i].rect, all_enemies[j].rect);
                if (collision) {
                    // Kill enemy 
                    all_enemies = remove_entity(all_enemies, j, enemy_count);
                    if (all_enemies == NULL && enemy_count > 1) {
                        cleanup(textures, all_projectiles, all_apples, all_enemies);
                        return 1;
                    }
                    enemy_count -= 1;
                    
                    // Kill projectile
                    all_projectiles = remove_entity(all_projectiles, i, projectile_count);
                    if (all_projectiles == NULL && projectile_count > 1) {
                        cleanup(textures, all_projectiles, all_apples, all_enemies);
                        return 1;
                    }
                    projectile_count -= 1;
                }
            }
        }
        // Player / Apples
        for (int i = 0; i < apple_count; i++) {
            bool collision = CheckCollisionRecs(player.rect, all_apples[i].rect);
            if (collision) {
                // Kill apple
                all_apples = remove_entity(all_apples, i, apple_count);
                if (all_apples == NULL && apple_count > 1) {
                    cleanup(textures, all_projectiles, all_apples, all_enemies);
                    return 1;
                }
                apple_count -= 1;
                
                player_lives -= 1;
                if (player_lives <= 0) {
                    is_running = false;
                }
            }
        }
        
        
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        // Player
        player_update(&player, dt);
        entity_draw(&player);
        
        // Projectiles
        for (int i = 0;  i < projectile_count; i++) {
            projectile_update(&all_projectiles[i], dt);
            entity_draw(&all_projectiles[i]);
        }
        
        // Apples
        for (int i = 0;  i < apple_count; i++) {
            apple_update(&all_apples[i], dt);
            entity_draw(&all_apples[i]);
        }
        
        // Enemy
        for (int i = 0;  i < enemy_count; i++) {
            enemy_update(&all_enemies[i], dt);
            entity_draw(&all_enemies[i]);
        }
        
        
        char *lives_text = "Lives: 0"; 
        if (player_lives == 3) lives_text = "Lives: 3";
        if (player_lives == 2) lives_text = "Lives: 2";
        if (player_lives == 1) lives_text = "Lives: 1";
        
        // HUD
        DrawText(lives_text, 50, 50, 28, player_lives > 1 ? BLACK : RED);
        
        EndDrawing();
    }
    
    cleanup(textures, all_projectiles, all_apples, all_enemies);
    
    return 0;
}

Texture2D *load_textures() {
    int number_of_textures = 4;
    
    Texture2D *textures = malloc(sizeof(Texture2D) * number_of_textures);
    if (textures == NULL) {
        return NULL;
    }
    
    // Player texture
    Image player_image = LoadImage("assets/Varken.png");
    ImageResize(&player_image, player_image.width * 1.5, player_image.height * 1.5);
    textures[0] = LoadTextureFromImage(player_image);
    
    // Gas texture
    Image projectile_image = LoadImage("assets/gas.png");
    ImageResize(&projectile_image, projectile_image.width / 20, projectile_image.height / 20);
    ImageRotateCCW(&projectile_image);
    textures[1] = LoadTextureFromImage(projectile_image);
    
    // Apple texture
    Image apple_image = LoadImage("assets/appel.png");
    ImageResize(&apple_image, apple_image.width * 0.2, apple_image.height * 0.2);
    textures[2] = LoadTextureFromImage(apple_image);
    
    // Enemy texture
    Image enemy_image = LoadImage("assets/boer.png");
    ImageResize(&enemy_image, enemy_image.width * 1.7, enemy_image.height * 1.7);
    textures[3] = LoadTextureFromImage(enemy_image);
    
    return textures;
}

void cleanup(
    Texture2D *textures, 
    entity_t *all_projectiles,
    entity_t *all_apples, 
    entity_t *all_enemies
) {
    free(textures);
    free(all_projectiles);
    free(all_apples);
    free(all_enemies);
    CloseWindow();
}

bool timer(float last_time, float cooldown) {
    float time_between = GetTime() - last_time;
    return time_between > cooldown;
}