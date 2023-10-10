#include "Ball.h"
void Ball_Clear(Ball *ball) 
{
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_FillCircle(ball->x, ball->y, BALL_RADIUS);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
}

direction Ball_get_random_direction()
{
    int r = rand() % 6;
    switch (r) {
        case 0: return UP;
        case 1: return DOWN;
        case 2: return UP_LEFT;
        case 3: return UP_RIGHT;
        case 4: return DOWN_LEFT;
        case 5: return DOWN_RIGHT;
        default: return UP;
    }
}

void Ball_Init(Ball* ball, uint16_t x, uint16_t y, direction dir)
{
    ball->x = x; 
    ball->y = y ; 
    ball->dir = dir;
}

void Ball_Draw(Ball* ball)
{
    // BSP_LCD_FillCircle
    BSP_LCD_FillCircle(ball->x, ball->y, BALL_RADIUS);
}
// void Ball_Erase(Ball* ball);
void Ball_Move(Ball* ball)
{
    switch (ball->dir)
    {
    case UP:
        /* code */
        break;
    case DOWN:
        /* code */
        break;
    case UP_RIGHT:
        /* code */
        break;
    case UP_LEFT:
        /* code */
        break;
    case DOWN_LEFT:
        /* code */
        break;
    case DOWN_RIGHT:
        /* code */
        break;
    default:
        break;
    }


}