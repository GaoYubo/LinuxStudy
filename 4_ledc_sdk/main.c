#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

/* 使能外设时钟 */
void clk_enable(void)
{
    CCM->CCGR0 = 0xffffffff;
    CCM->CCGR1 = 0xffffffff;
    CCM->CCGR2 = 0xffffffff;
    CCM->CCGR3 = 0xffffffff;
    CCM->CCGR4 = 0xffffffff;
    CCM->CCGR5 = 0xffffffff;
    CCM->CCGR6 = 0xffffffff;
}

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
        delay(1000);

        led_on();
        delay(1000);
    }
    
    return 0;
}