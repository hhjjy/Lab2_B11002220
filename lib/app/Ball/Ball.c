#include "Ball.h"
void Ball_Clear(Ball *ball) 
{
    // int x, y , w,h ; 
    // x = ball->x -BALL_RADIUS; 
    // y = ball->y -BALL_RADIUS;
    
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_FillCircle(ball->x, ball->y, BALL_RADIUS);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
}
void Ball_get_random_direction(Ball *ball)
{
    int r = rand() % 4;
    switch (r) {
        // case 0: // UP
        //     ball->vx = 0 ; 
        //     ball->vy = -1 ; 
        //     return ;
        // case 1: // DOWN
        //     ball->vx = 0 ; 
        //     ball->vy = 1 ; 
        //     return ;
        case 0: // UP_LEFT
            ball->vx = -1 ; 
            ball->vy = -1 ; 
            return ;
        case 1: // UP_RIGHT
            ball->vx = 1 ; 
            ball->vy = -1 ; 
            return ;
        case 2: // DOWN_LEFT
            ball->vx = -1 ; 
            ball->vy = 1 ; 
            return ;
        case 3: // DOWN_RIGHT
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
    BSP_LCD_DrawPixel(ball->x-BALL_RADIUS, ball->y, LCD_COLOR_RED) ; 
    BSP_LCD_DrawPixel(ball->x+BALL_RADIUS, ball->y, LCD_COLOR_RED) ; 
    BSP_LCD_DrawPixel(ball->x, ball->y-BALL_RADIUS, LCD_COLOR_RED) ; 
    BSP_LCD_DrawPixel(ball->x, ball->y+BALL_RADIUS, LCD_COLOR_RED) ; 

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
int Ball_get_vx(Ball *ball) 
{

    return ball->vx ;

}
int Ball_get_vy(Ball *ball) 
{
    return ball->vy;

}