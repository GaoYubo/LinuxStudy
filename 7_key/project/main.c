#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"


int main(void)
{
    int keyValue = KEY_NONE;

    clk_enable();  /* 使能外设时钟 */
    led_init();   /* 初始化LED */
    beep_init();  /* 初始化BEEP */
    key_init();  /* 初始化按键 */

    /* 设置LED闪烁*/
    while(1)
    {
        led_on();
        delay(100);
        led_off();
        delay(100);

        keyValue = key_getValue();

        if(keyValue)
        {
            beep_on();
        }
        else
        {
            beep_off();
        }
        
    }
    
    return 0;
}