#include "Ball.h"
void Ball_Clear(Ball *ball) 
{
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_FillCircle(ball->x, ball->y, BALL_RADIUS);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
}
void Ball_get_random_direction(Ball *ball)
{
    int r = rand() % 6;
    switch (r) {
        case 0: // UP
            ball->vx = 0 ; 
            ball->vy = -1 ; 
            return ;
        case 1: // DOWN
            ball->vx = 0 ; 
            ball->vy = 1 ; 
            return ;
        case 2: // UP_LEFT
            ball->vx = -1 ; 
            ball->vy = -1 ; 
            return ;
        case 3: // UP_RIGHT
            ball->vx = 1 ; 
            ball->vy = -1 ; 
            return ;
        case 4: // DOWN_LEFT
            ball->vx = -1 ; 
            ball->vy = 1 ; 
            return ;
        case 5: // DOWN_RIGHT
            ball->vx = 1 ; 
            ball->vy = 1 ; 
            return ;
        default: 
            ball->vx = 0 ; 
            ball->vy = -1 ; 
            return ;
    }
}

void Ball_Init(Ball* ball, uint16_t x, uint16_t y)
{
    ball->x = x; 
    ball->y = y ; 
    ball->vx = 0;
    ball->vx = 0;
    Ball_get_random_direction(ball); 

}
void Ball_Draw(Ball* ball)
{
    // BSP_LCD_FillCircle
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillCircle(ball->x, ball->y, BALL_RADIUS);
}
void Ball_Erase(Ball* ball)
{
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_FillCircle(ball->x, ball->y, BALL_RADIUS);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
}

void Ball_Move(Ball* ball)
{
    Ball_Erase(ball); 
    // move 
    ball ->x += ball->vx ;
    ball ->y += ball->vy ;
    // draw 
    Ball_Draw(ball); 
}