#include "Time_counter.h"
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Move.h"

#define WALL_WIDTH 480
#define WALL_HEIGHT 272

Ball ball;
Brick brick[BRICK_NUM];
Paddle paddle;
// 磚頭初始化
void app_brick_init(void)
{
    for (int i = 0; i < BRICK_NUM; i++)
    {
        if (i % BRICK_ARR_WIDTH == 0)
        {
            brick[i].x = BRICK_ARR_START_AT_X;
            brick[i].y = BRICK_ARR_START_AT_Y + (i / BRICK_ARR_WIDTH) * (BRICK_HEIGHT + BRICK_SPACE);
            brick[i].color = 2; // 白
            brick[i].lives = 2; // 兩命
        }
        else
        {
            brick[i].x = BRICK_ARR_START_AT_X + (i % BRICK_ARR_WIDTH) * (BRICK_WIDTH + BRICK_SPACE);
            brick[i].y = BRICK_ARR_START_AT_Y + (i / BRICK_ARR_WIDTH) * (BRICK_HEIGHT + BRICK_SPACE);
            brick[i].color = 2; // 白
            brick[i].lives = 2; // 兩命
        }
        Brick_Draw(&brick[i]);
    }
}
void app_ball_init()
{
    Ball_Init(&ball, BALL_INIT_X, BALL_INIT_Y);
    Ball_Draw(&ball);
}
void app_paddle_init()
{
    Paddle_Init(&paddle, 240, PADDLE_INIT_START_Y);
    Paddle_Draw(&paddle);
}
void Brick_test()
{
    Brick_Erase(&brick[0]);
}

int Ball_touch_brick(Ball *ball, Brick *brick)
{
    // up detected point
    if (ball->x <= brick->x + BRICK_WIDTH && ball->x >= brick->x &&
        (ball->y - BALL_RADIUS) <= brick->y + BRICK_HEIGHT && (ball->y - BALL_RADIUS) >= brick->y)
    {
        return 1;
    }
    // down detected point
    if (ball->x <= brick->x + BRICK_WIDTH && ball->x >= brick->x &&
        (ball->y + BALL_RADIUS) <= brick->y + BRICK_HEIGHT && (ball->y + BALL_RADIUS) >= brick->y)
    {
        return 1;
    }
    // left detected point
    if ((ball->x - BALL_RADIUS) <= brick->x + BRICK_WIDTH && (ball->x - BALL_RADIUS) >= brick->x &&
        ball->y <= brick->y + BRICK_HEIGHT && ball->y >= brick->y)
    {
        return 1;
    }
    // right detected point
    if ((ball->x + BALL_RADIUS) <= brick->x + BRICK_WIDTH && (ball->x + BALL_RADIUS) >= brick->x &&
        ball->y <= brick->y + BRICK_HEIGHT && ball->y >= brick->y)
    {
        return 1;
    }
    return 0;
}

int Ball_touch_paddle(Ball *ball, Paddle *paddle)
{
    if (ball->y + BALL_RADIUS >= paddle->y && ball->y - BALL_RADIUS <= paddle->y + PADDLE_HEIGHT && ball->x >= paddle->x - PADDLE_WIDTH / 2 && ball->x <= paddle->x + PADDLE_WIDTH / 2)
    {
        float temp = (ball->x - (paddle->x - PADDLE_WIDTH / 2)) / PADDLE_WIDTH;
        // Left part
        if (temp <= 0.33)
        {
            ball->vx = -1;
            ball->vy = -1;
        }
        else if (temp <= 0.66) // middle
        {
            ball->vx = 0;
            ball->vy = -1;
        }
        else if (temp <= 1) // RIGTH
        {
            ball->vx = 1;
            ball->vy = -1;
        }
        return 1;
    }
    return 0;
}

int Ball_touch_wall(Ball *ball)
{
    if (ball->x + BALL_RADIUS >= WALL_WIDTH || ball->x - BALL_RADIUS <= 0)
    {
        // 球撞到了左右牆壁
        ball->vx = -ball->vx;
        return 1;
    }
    if (ball->y + BALL_RADIUS >= WALL_HEIGHT)
    {
        // 球撞到了上牆
        ball->vx = -ball->vx;
        ball->vy = -ball->vy;
        return 1;
    }
    if (ball->y - BALL_RADIUS <= 0)
        return -1;
    return 0;
}
void Ball_touch_item()
{
    // brick
    for (int i = 0; i < BRICK_NUM; i++)
    {

        if (Ball_touch_brick(&ball, &brick[i]))
        {
            Brick_Erase(&brick[i]);
        }
    }
    // touch wall
    if (Ball_touch_wall(&ball) == -1)
    {
        game_over();
        BSP_LCD_DisplayStringAt(0, 272/2, (uint8_t *)"Game Over", CENTER_MODE);
        return;
    }
    // touch paddle
    if (Ball_touch_paddle(&ball, &paddle))
    {
        BSP_LCD_DisplayStringAt(0, 0, (uint8_t *)"touch_paddle", LEFT_MODE);
    }
    // return item ;
}
void game_init()
{
    time_init();
    app_ball_init() ; 
    app_brick_init(); 
    app_paddle_init() ; 
}
// should run every 10ms 
void app_gameLoop()
{
    if(get_game_stat()== GAME_START)
    {
        Ball_touch_item();
        Ball_Move(&ball);
    }
}
void app_paddleMove(int x , int y )
{
    Paddle_Move(&paddle, x, y);
}
int app_get_game_win_or_lose()
{
    int win = 1; 
    for (int i = 0; i < BRICK_NUM; i++)
    {
        if(brick[i].lives != 0)
            win = 0 ; 
    }
    return win ;
}
