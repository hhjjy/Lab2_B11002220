#include "Paddle.h"
void Paddle_Init(Paddle* paddle, uint16_t x, uint16_t y)
{
    paddle->x = x;
    paddle->y = y;
    Paddle_Draw(paddle); 
}
void Paddle_X_limit(Paddle *paddle)
{

    if(paddle->x-PADDLE_WIDTH/2 <= 0)
    {
        paddle->x = PADDLE_WIDTH/2;
    }
    else if (paddle->x+PADDLE_WIDTH/2 >= 480)
    {
        paddle->x = 480-PADDLE_WIDTH/2-1;
    }
}

void Paddle_Draw(Paddle* paddle)
{
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE); 
    Paddle_X_limit(paddle) ; 
    BSP_LCD_DrawRect(paddle->x-PADDLE_WIDTH/2, PADDLE_INIT_START_Y, PADDLE_WIDTH, PADDLE_HEIGHT);
}
void Paddle_Erase(Paddle* paddle)
{
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK); 
    Paddle_X_limit(paddle) ; 
    BSP_LCD_DrawRect(paddle->x-PADDLE_WIDTH/2, PADDLE_INIT_START_Y, PADDLE_WIDTH, PADDLE_HEIGHT);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE); 

}
int is_touch_X_Y_in_Paddle(Paddle *paddle,int touchx,int touchy)
{
    // limited center of x 
    Paddle_X_limit(paddle) ;

    // Calulate 
    if (paddle->x- PADDLE_WIDTH/2 <= touchx && touchx <= paddle->x+ PADDLE_WIDTH/2)
        
        return 1 ; 
    else 
        return 0 ; 
}
void Paddle_Move(Paddle *paddle,int x , int y )
{
    // todo 先把paddle 清掉才能動！
    if (is_touch_X_Y_in_Paddle(paddle,x,y))
    {
        Paddle_Erase(paddle);
        paddle->x = x ; 
        Paddle_Draw(paddle);
    }
}