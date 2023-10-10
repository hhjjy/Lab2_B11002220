#ifndef PADDLE_H
#define PADDLE_H

#include "stm32f746xx.h"
#include "stm32746g_discovery_lcd.h"
#define PADDLE_WIDTH 60
#define PADDLE_HEIGHT 5
#define PADDLE_INIT_START_Y 242

typedef struct {
    uint16_t x;
    uint16_t y;
    // uint32_t color;
} Paddle;

void Paddle_Init(Paddle* paddle, uint16_t x, uint16_t y);
void Paddle_Draw(Paddle* paddle);
void Paddle_Erase(Paddle* paddle);
void Paddle_Move(int x , int y );

#endif /* PADDLE_H */
