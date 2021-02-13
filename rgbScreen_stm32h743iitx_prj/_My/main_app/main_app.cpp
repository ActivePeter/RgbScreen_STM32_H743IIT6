#include "main_app_C.h"
#include "paLib/service/display/_RgbScreen/R61408/R61408.h"
#include "paLib/drv/pa_BaseDrv/pa_BaseDrv.h"
// #include "tusb.h"
//#include "paLib/drv/pa_USB/teenyUSB/inc/teeny_usb.h"
#include "cmsis_os.h"
#include <ctype.h>

void usbTask(void const *argument);
static void cdc_task(void);
void basicInit()
{
  // cdc_init();

  // while (1)
  // {
  //   tud_task(); // tinyusb device task
  //   cdc_task();
  // }
  //    osThreadDef(usbTask, usbTask, osPriorityNormal, 0, 6000);
  //    osThreadCreate(osThread(usbTask), NULL);
}

void startMainApp()
{
  while (1)
  {
    //        SDRAM::test();
//    if (tud_cdc_connected())
//    {
//      tud_cdc_write_str("He\r\n");
//      tud_cdc_write_flush();
//    }
    pa_delayMs(1000);
    //        tud_task();
  }
  // SDRAM::init();
  // SDRAM::test();
  // //    SDRAM::test();
  // auto screen = R61408::getInstance(); //获取屏幕单例
  // Ltdc_init(screen->getRGBConfig());   //启动ltdc
  // screen->LCD_init();

  // //    Gpio_setMode(GPIOI, GPIO_PIN_4, GpioMode_Output_PP, GpioSpeed_Medium);
  // //    Gpio_write(GPIOI, GPIO_PIN_4, 1);
  // while (1)
  // {
  //     SDRAM::test();
  //     // if (tud_cdc_connected())
  //     // {
  //     //     tud_cdc_write_str("Hello World\r\n");
  //     //     tud_cdc_write_flush();
  //     // }

  //     // tud_task();
  //     //        if (tud_cdc_connected())
  //     //        {
  //     //            tud_cdc_write_str("Hello World\r\n");
  //     //            tud_cdc_write_flush();
  //     //        }
  //     //
  //     //        tud_task();
  //     // SDRAM::test();
  //     pa_delayMs(1);
  // }
}
