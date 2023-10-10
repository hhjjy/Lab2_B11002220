#include "Time_counter.h"
#include "Brick.h"
#include "Paddle.h"
#include "Move.h"
#include "Ball.h"


Ball ball ; 
Brick brick[BRICK_NUM];
Paddle paddle ; 
// 磚頭初始化
void app_brick_init(void)
{
    for (int i = 0 ; i < BRICK_NUM ; i ++)
    {
        if (i%BRICK_ARR_WIDTH == 0 )
        {
            brick[i].x = BRICK_ARR_START_AT_X ; 
            brick[i].y = BRICK_ARR_START_AT_Y + (i/BRICK_ARR_WIDTH) * (BRICK_HEIGHT + BRICK_SPACE);
            brick[i].color = 2;//白
            brick[i].lives = 2; //兩命
            
        }
        else 
        {
            brick[i].x = BRICK_ARR_START_AT_X + (i%BRICK_ARR_WIDTH) * (BRICK_WIDTH + BRICK_SPACE); 
            brick[i].y = BRICK_ARR_START_AT_Y + (i/BRICK_ARR_WIDTH) * (BRICK_HEIGHT + BRICK_SPACE);
            brick[i].color = 2;//白
            brick[i].lives = 2; //兩命
        }
        Brick_Draw(&brick[i]); 
    }

}
void app_ball_init()
{
    Ball_Init(&ball,BALL_INIT_X,BALL_INIT_Y,Ball_get_random_direction());
    Ball_Draw(&ball);
}
void app_paddle_init()
{
    Paddle_Init(&paddle,240,PADDLE_INIT_START_Y);
    Paddle_Draw(&paddle);
}
void Brick_test()
{
    Brick_Erase(&brick[0]); 
}



touch_item Ball_touch_item()
{
    touch_item item = NONE; 
    // brick 
    for (int i = 0 ; i < BRICK_NUM ; i ++)
    {

        // if (Ball_touch_brick(&brick[i]))
        // {
        //     item = BRICK; 
        //     break; 
        // }

    }

        



    return item ; 
}