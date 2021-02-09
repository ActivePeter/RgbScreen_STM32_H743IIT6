/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define stepperMs1_Pin GPIO_PIN_2
#define stepperMs1_GPIO_Port GPIOE
#define LCD_CLK_Pin GPIO_PIN_3
#define LCD_CLK_GPIO_Port GPIOE
#define stepperMs3_Pin GPIO_PIN_4
#define stepperMs3_GPIO_Port GPIOE
#define leftArmLimit_Pin GPIO_PIN_5
#define leftArmLimit_GPIO_Port GPIOE
#define rightArmLimit_Pin GPIO_PIN_6
#define rightArmLimit_GPIO_Port GPIOE
#define arm_En2_Pin GPIO_PIN_12
#define arm_En2_GPIO_Port GPIOC
#define arm_step2_Pin GPIO_PIN_2
#define arm_step2_GPIO_Port GPIOD
#define arm_dir0_Pin GPIO_PIN_3
#define arm_dir0_GPIO_Port GPIOD
#define arm_dir1_Pin GPIO_PIN_4
#define arm_dir1_GPIO_Port GPIOD
#define arm_dir2_Pin GPIO_PIN_5
#define arm_dir2_GPIO_Port GPIOD
#define arm_En0_Pin GPIO_PIN_6
#define arm_En0_GPIO_Port GPIOD
#define arm_En1_Pin GPIO_PIN_7
#define arm_En1_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
