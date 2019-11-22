#include "bsp_beep.h"

void beep_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_UART1_RTS_B_GPIO1_IO19, 0);  /* 复用为GPIO1-IO19 */
    IOMUXC_SetPinConfig(IOMUXC_UART1_RTS_B_GPIO1_IO19,0x10b0);

    /* GPIO初始化 */
    GPIO1->GDIR |= (1<<19);
    GPIO1->DR &= ~(1<<19);
}

void beep_on(void)
{
    GPIO1->DR |= (1<<19);
}

void beep_off(void)
{
    GPIO1->DR &= ~(1<<19);
}