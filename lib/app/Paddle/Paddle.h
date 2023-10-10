#ifndef PADDLE_H
#define PADDLE_H

#include "stm32f746xx.h"
#include "stm32746g_discovery_lcd.h"
#define PADDLE_WIDTH 60
#define PADDLE_HEIGHT 5
#define PADDLE_INIT_START_Y 242
// x means center of rect 
typedef struct {
    uint16_t x;
    uint16_t y;
    // uint32_t color;
} Paddle;

void Paddle_Init(Paddle* paddle, uint16_t x, uint16_t y);
void Paddle_Draw(Paddle* paddle);
void Paddle_Erase(Paddle* paddle);
void Paddle_Move(Paddle *paddle,int x , int y );
int is_touch_X_Y_in_Paddle(Paddle *paddle,int x,int y);
void Paddle_X_limit(Paddle *paddle);
#endif /* PADDLE_H */
