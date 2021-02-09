#include "main_app_C.h"
#include "paLib/service/display/_RgbScreen/R61408/R61408.h"
#include "paLib/drv/pa_BaseDrv/pa_BaseDrv.h"

void startMainApp()
{
    auto screen = R61408::getInstance(); //获取屏幕单例
    Ltdc_init(screen->getRGBConfig());   //启动ltdc
    screen->LCD_init();
    //    Gpio_setMode(GPIOI, GPIO_PIN_4, GpioMode_Output_PP, GpioSpeed_Medium);
    //    Gpio_write(GPIOI, GPIO_PIN_4, 1);
    while (1)
    {

        pa_delayMs(1);
    }
}
