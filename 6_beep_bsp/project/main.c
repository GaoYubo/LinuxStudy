#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"


int main(void)
{
    clk_enable();  /* 使能外设时钟 */
    led_init();   /* 初始化LED */
    beep_init();  /* 初始化BEEP */

    /* 设置LED闪烁*/
    while(1)
    {
        led_off();
        beep_off();
        delay(1000);

        led_on();
        beep_on();
        delay(1000);
    }
    
    return 0;
}