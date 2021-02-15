#include "main_app_C.h"
#include "paLib/service/display/_RgbScreen/R61408/R61408.h"
#include "paLib/drv/pa_BaseDrv/pa_BaseDrv.h"
// #include "tusb.h"
//#include "paLib/drv/pa_USB/teenyUSB/inc/teeny_usb.h"
#include "cmsis_os.h"
#include <ctype.h>
#include "paLib/drv/pa_USB/STM32_USB_Device_Library/Core/usb_device.h"

#include "paLib/service/graphic/lvgl/pa_Lvgl/pa_Lvgl.h"
#include "paLib/service/graphic/lvgl/lvgl.h"

#include "paLib/service/input/GT911/GT911.h"

#include "paLib/util/pa_DataProcessor/pa_DataProcessor.h"
void basicInit()
{
  // startMainApp();
  // MX_USB_DEVICE_Init();
  // tusb_init();

  // while (1)
  // {
  //   tud_task(); // tinyusb device task
  //   cdc_task();
  // }
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
  //USB
  MX_USB_DEVICE_Init();
  pa_delayMs(1000);
  //SDRAM
  SDRAM::init();
  SDRAM::test();
  // //    SDRAM::test();
  //RGBscreen
  auto screen = R61408::getInstance(); //获取屏幕单例
  Ltdc_init(screen->getRGBConfig());   //启动ltdc
  screen->LCD_init();
  //iic
  pa_IIC_init(GT911_iic_id);
  //GT911 touchpad
  {
    GT911::GT911_Config_t gtconfig;
    gtconfig.Number_Of_Touch_Support = 1;
    gtconfig.ReverseX = false;
    gtconfig.ReverseY = false;
    gtconfig.SoftwareNoiseReduction = false;
    gtconfig.SwithX2Y = false;
    gtconfig.X_Resolution = 100;
    gtconfig.Y_Resolution = 100;

    auto status = GT911::GT911_Init(gtconfig);
    char buf[30];

    pa_snprintf(buf, 30, "gt911 init status:%d\r\n", status);
    Output::pa_print(buf);
  }

  lv_init();

  pa_Lvgl_init();
  lv_obj_t *menuPage;
  menuPage = lv_page_create(lv_scr_act(), NULL);
  lv_obj_set_size(menuPage, 165, 310);
  lv_obj_set_pos(menuPage, 70, 5); /*Set its position*/

  lv_obj_t *btn = lv_btn_create(lv_scr_act(), NULL); /*Add a button the current screen*/
  lv_obj_set_pos(btn, 5, 5);                         /*Set its position*/
  lv_obj_set_size(btn, 60, 20);                      /*Set its size*/
  // lv_obj_set_event_cb(btn, btn_event_cb);                 /*Assign a callback to the button*/
  // lv_obj_set_event_cb(btn, menuBtn_event_handler);
  lv_obj_t *label = lv_label_create(btn, NULL); /*Add a label to the button*/
  lv_label_set_text(label, "menu");
  // //    Gpio_setMode(GPIOI, GPIO_PIN_4, GpioMode_Output_PP, GpioSpeed_Medium);
  // //    Gpio_write(GPIOI, GPIO_PIN_4, 1);

  while (1)
  {
    // SDRAM::test();
    lv_task_handler();
    // Output::pa_print("loop\r\n");
    {
      TouchCordinate_t cord;
      uint8_t num = 1;
      unsigned char status = GT911::GT911_ReadTouch(&cord, &num);
      char buf[30];

      pa_snprintf(buf, 30, "%d %d %d\r\n", status, cord.x, cord.y);
      Output::pa_print(buf);
    }
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
