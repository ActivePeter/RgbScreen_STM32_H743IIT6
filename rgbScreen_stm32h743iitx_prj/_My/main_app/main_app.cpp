#include "main_app_C.h"
#include "paLib/service/display/_RgbScreen/R61408/R61408.h"
#include "paLib/drv/pa_BaseDrv/pa_BaseDrv.h"
//#include "tusb.h"
//#include "paLib/drv/pa_USB/teenyUSB/inc/teeny_usb.h"
#include "cmsis_os.h"
#include <ctype.h>
#include "paLib/drv/pa_USB/USB_DEVICE/App/usb_device.h"

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
// echo to either Serial0 or Serial1
// with Serial0 as all lower case, Serial1 as all upper case
//static void echo_serial_port(uint8_t itf, uint8_t buf[], uint32_t count)
//{
//  for (uint32_t i = 0; i < count; i++)
//  {
//    if (itf == 0)
//    {
//      // echo back 1st port as lower case
//      if (isupper(buf[i]))
//        buf[i] += 'a' - 'A';
//    }
//    else
//    {
//      // echo back additional ports as upper case
//      if (islower(buf[i]))
//        buf[i] -= 'a' - 'A';
//    }
//
//    tud_cdc_n_write_char(itf, buf[i]);
//
//    if (buf[i] == '\r')
//      tud_cdc_n_write_char(itf, '\n');
//  }
//  tud_cdc_n_write_flush(itf);
//}
//
////--------------------------------------------------------------------+
//// USB CDC
////--------------------------------------------------------------------+
//static void cdc_task(void)
//{
//  uint8_t itf;
//
//  for (itf = 0; itf < CFG_TUD_CDC; itf++)
//  {
//    // connected() check for DTR bit
//    // Most but not all terminal client set this when making connection
//    if (tud_cdc_n_connected(itf))
//    {
//      if (tud_cdc_n_available(itf))
//      {
//        uint8_t buf[64];
//
//        uint32_t count = tud_cdc_n_read(itf, buf, sizeof(buf));
//
//        // echo back to both serial ports
//        echo_serial_port(0, buf, count);
//        echo_serial_port(1, buf, count);
//      }
//    }
//  }
//}
void startMainApp()
{
  MX_USB_DEVICE_Init();
  SDRAM::init();
  SDRAM::test();
  // //    SDRAM::test();
  auto screen = R61408::getInstance(); //获取屏幕单例
  Ltdc_init(screen->getRGBConfig());   //启动ltdc
  screen->LCD_init();

  // //    Gpio_setMode(GPIOI, GPIO_PIN_4, GpioMode_Output_PP, GpioSpeed_Medium);
  // //    Gpio_write(GPIOI, GPIO_PIN_4, 1);
  while (1)
  {
    SDRAM::test();
    // if (tud_cdc_connected())
    // {
    //     tud_cdc_write_str("Hello World\r\n");
    //     tud_cdc_write_flush();
    // }

    // tud_task();
    //        if (tud_cdc_connected())
    //        {
    //            tud_cdc_write_str("Hello World\r\n");
    //            tud_cdc_write_flush();
    //        }
    //
    //        tud_task();
    // SDRAM::test();
    pa_delayMs(1);
  }
}
