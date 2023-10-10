#include "Brick.h"

void Brick_Init(Brick *brick, uint16_t x, uint16_t y, uint8_t lives, uint32_t color)
{
    brick->x = x;
    brick->y = y;
    brick->lives = lives;
    brick->color = color;
}
void Brick_Draw(Brick *brick)
{

    if (brick->lives == 2)
    {
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    }
    else if (brick->lives == 1)
    {
        BSP_LCD_SetTextColor(LCD_COLOR_RED);
    }
    else
    {
        BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    }
    BSP_LCD_FillRect(brick->x, brick->y, BRICK_WIDTH, BRICK_HEIGHT);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
}
void Brick_Erase(Brick *brick)
{
    brick->lives -= 1 ; 
    Brick_Draw(brick) ; 
}
//用測試檢驗
// // 如果有碰到就回1
