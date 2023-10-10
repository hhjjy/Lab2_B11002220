#ifndef BRICK_H
#define BRICK_H
#include "stm32746g_discovery_lcd.h"
#include "stm32f746xx.h"
#include "Ball.h"
#define BRICK_ARR_START_AT_X 4
#define BRICK_ARR_START_AT_Y 40
#define BRICK_ARR_WIDTH 8
#define BRICK_WIDTH 56
#define BRICK_HEIGHT 10
#define BRICK_NUM 24 
#define BRICK_SPACE 4

typedef struct {
    uint16_t x;// 左上角座標 
    uint16_t y;
    uint8_t lives;//預設是2,1,0 刪除  
    uint32_t color;// 預設是2(白),1(紅),0（黑）
} Brick;

void Brick_Init(Brick* brick, uint16_t x, uint16_t y, uint8_t lives, uint32_t color);
void Brick_Draw(Brick* brick);
void Brick_Erase(Brick* brick);
// int Ball_touch_brick(Ball *ball,Brick *brick) ; 

#endif /* BRICK_H */
