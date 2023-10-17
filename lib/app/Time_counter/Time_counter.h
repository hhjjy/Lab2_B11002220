// 倒數計時的功能
#pragma once
#include "stm32f746xx.h"

#define INIT_TIME 0 
#define GAME_START 1  
#define GAME_START 0  
int game_start = 0 ; 
int sec_counter = INIT_TIME ;


int get_game_stat()
{
    return game_start ;
}
int get_time_now()
{
    return sec_counter ; 
}
// 如果按鈕按下 就執行這個 
void time_init()
{
    sec_counter = INIT_TIME ; 
    game_start = 0 ;
} 
void game_set_to_start()
{
    game_start=  1 ; 
}
void game_over() 
{
    game_start = 0 ;
}
//function:減1秒 
void time_increase(void)
{
    if(game_start)
    {
        
            sec_counter += 1 ; 
    
        
    }

}
