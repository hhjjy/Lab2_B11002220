#ifndef BALL_H
#define BALL_H
#include "stm32f746xx.h"
#include <stdlib.h>
#include <time.h>
#include "stm32746g_discovery_lcd.h"
#include "stm32f746xx.h"
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272 
#define BALL_RADIUS 5
#define BALL_INIT_X 240 
#define BALL_INIT_Y 136

// #define BALL_INIT_X 200 
// #define BALL_INIT_Y 200
typedef struct aaa{
    uint16_t x;
    uint16_t y;
    int vx ; 
    int vy ; 
    // uint32_t color;
} Ball;
void Ball_get_random_direction(Ball *ball);
int Ball_touch_wall() ; 
// int Ball_touch_paddle(Paddle *paddle) ;
void Ball_Clear(Ball *ball) ; 
void Ball_Init(Ball* ball, uint16_t x, uint16_t y);
void Ball_Draw(Ball* ball);
void Ball_Erase(Ball* ball);
void Ball_Move(Ball* ball);
int Ball_get_vx(Ball *ball) ; 
int Ball_get_vy(Ball *ball) ; 
#endif /* BALL_H */
