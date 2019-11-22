#include "main.h"

/* 使能外设时钟 */
void clk_enable(void)
{
    CCM_CCGR0 = 0xffffffff;
    CCM_CCGR1 = 0xffffffff;
    CCM_CCGR2 = 0xffffffff;
    CCM_CCGR3 = 0xffffffff;
    CCM_CCGR4 = 0xffffffff;
    CCM_CCGR5 = 0xffffffff;
    CCM_CCGR6 = 0xffffffff;
}

/* 初始化LED */
void led_init(void)
{
    // SW_MUX_GPIO1_IO03 = 0x05;  /* 复用为GPIO1-IO03 */
    // SW_PAD_GPIO1_IO03 = 0x10b0;  /* 设置GPIO1-IO03电气属性 */

    // /* GPIO初始化 */
    // GPIO1_GDIR = 0x8;  /* 设置为输出 */
    // GPIO1_DR = 0x0;   /* 打开LED灯 */

    SW_MUX_GPIO5_IO03 = 0x05;  /* 复用为GPIO5-IO03 */
    SW_PAD_GPIO5_IO03 = 0x10b0;  /* 设置GPIO5-IO03电气属性 */
    /* GPIO初始化 */
    GPIO5_GDIR = 0x8;  /* 设置为输出 */
    GPIO5_DR = 0x0;  /* 打开LED灯 */
}

void led_on(void)
{
    //GPIO1_DR &= ~(1<<3);
    GPIO5_DR &= ~(1<<3);
}

void led_off(void)
{
    //GPIO1_DR |= (1<<3);
    GPIO5_DR |= (1<<3);
}

void delay_short(volatile unsigned int n)
{
    while (n--)
    {
        
    }    
}

void delay(volatile unsigned int n)
{
    while (n--)
    {
        delay_short(0x7ff);
    }
}

int main(void)
{
    clk_enable();  /* 使能外设时钟 */
    led_init();   /* 初始化LED */

    /* 设置LED闪烁*/
    while(1)
    {
        led_off();
        delay(500);

        led_on();
        delay(500);
    }
    
    return 0;
}