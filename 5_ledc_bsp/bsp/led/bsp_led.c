#include "bsp_led.h"

/* 初始化LED */
void led_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER3_GPIO5_IO03, 0);  /* 复用为GPIO1-IO03 */
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER3_GPIO5_IO03,0x10b0);  /* 设置GPIO1-IO03电气属性 */

    /* GPIO初始化 */
    GPIO5 -> GDIR = 0x8;
    GPIO5 -> DR = 0x0;
}

void led_on(void)
{
    GPIO5->DR &= ~(1<<3);
}

void led_off(void)
{
    GPIO5->DR |= (1<<3);
}

/* LED灯控制函数 */
void led_switch(int led, int status)
{
    switch(status)
    {
        case LED0:
            if(status == ON)
                GPIO5->DR &= ~(1<<3);
            else if (status == OFF)
                GPIO5->DR |= (1<<3);
            break;
        default:break;
    }
}