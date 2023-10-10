#include "Paddle.h"



void Paddle_Init(Paddle* paddle, uint16_t x, uint16_t y)
{
    paddle->x = x;
    paddle->y = y;
    Paddle_Draw(paddle); 
}
void Paddle_Draw(Paddle* paddle)
{
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE); 
    if(paddle->x-PADDLE_WIDTH/2 <= 0)
    {
        BSP_LCD_DrawRect(0, PADDLE_START_Y, PADDLE_WIDTH, PADDLE_HEIGHT);
    }
    else if (paddle->x+PADDLE_WIDTH/2 > 480)
    {
        BSP_LCD_FI(480-PADDLE_WIDTH, PADDLE_START_Y, PADDLE_WIDTH, PADDLE_HEIGHT);
    }
    else 
        BSP_LCD_DrawRect(paddle->x-PADDLE_WIDTH/2, PADDLE_START_Y, PADDLE_WIDTH, PADDLE_HEIGHT);


}
void Paddle_Erase(Paddle* paddle)
{



}
void Paddle_Move(int x , int y )
{
    // todo 先把paddle 清掉才能動！




}