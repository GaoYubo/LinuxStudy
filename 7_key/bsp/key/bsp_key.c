#include "bsp_key.h"
#include "bsp_delay.h"
/**
 * 初始化按键
 * 返回值：0 未按下， 1 按下
 */
void key_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0);/* 复用为GPIO5_01*/
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0xf080);

    /* GPIO初始化 */
    GPIO5->GDIR &= ~(1<<1);
}

/**
 * 读取按键值
 */
int read_key(void)
{
    int ret = 0;

    ret = ((GPIO5->DR)>>1 &0x01);

    return ret;
}

int key_getValue(void)
{
    int ret = 0;
    static unsigned char release = 1; /* 为1表示按键释放 */
    
    if((release==1) && (read_key()==1)) /* 按键按下 */
    {
        delay(10);
        release = 0;
        if(read_key()==1)
        {
            ret = KEY0_VALUE;
        }
    }
    else if(read_key() == 0)
    {
        ret = KEY_NONE;
        release = 1;
    }

    return ret;    
}