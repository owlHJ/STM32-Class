/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
typedef struct ServoInfo
{
	GPIO_PinState 	enumPinServo;

	uint32_t 		iTIM1ARR;
	uint32_t 		iServoCCR;
	uint32_t 		iServoDuty;
}ServoInfo;

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t iDuty = 0;
ServoInfo gServoInfo = {0,0,0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void SetServoDuty(const uint32_t iDuty)
{
	// 2024-10-28 hjkim, Calculate the new CCR value and set it for TIM1 Channel 1
	uint32_t newCCR = (iDuty * gServoInfo.iTIM1ARR) / 100;

    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, newCCR);

	// 2024-10-28 hjkim, Update Servo Information
    gServoInfo.iServoCCR = __HAL_TIM_GET_COMPARE(&htim1, TIM_CHANNEL_1);
	gServoInfo.iTIM1ARR = __HAL_TIM_GET_AUTORELOAD(&htim1);
    gServoInfo.iServoDuty = iDuty;

	// 2024-10-28 hjkim, Handle case where duty is 0 (reset pin to Low)
    gServoInfo.enumPinServo = (iDuty == 0) ? GPIO_PIN_RESET : gServoInfo.enumPinServo;

    // 2024-10-28 hjkim, Set GPIO A5 pin based on duty cycle (Low if duty is 0, otherwise keep current state)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, gServoInfo.enumPinServo);

	// 2024-10-28 hjkim, Retrieve duty cycle using HAL macros, this method is recommended
	//gServoInfo.iServoCCR 	= __HAL_TIM_GET_COMPARE(&htim1, TIM_CHANNEL_1);
	//gServoInfo.iTIM1ARR 	= __HAL_TIM_GET_AUTORELOAD(&htim1);
	//gServoInfo.iServoDuty 	= (ccr_value * 100) / arr_value;

	// 2024-10-28 hjkim, Retrieve duty cycle directly from register
	//uint32_t duty_cycle2	= (TIM1->CCR1 *100) / TIM1->ARR;

	return;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  // 2024-10-28 hjkim, For HAL_TIM_PWM_PulseFinishedCallback: Start the base timer interrupt
  HAL_TIM_Base_Start_IT(&htim1);
  // 2024-10-28 hjkim, For HAL_TIM_PeriodElapsedCallback: Start the PWM interrupt for TIM1 Channel 1
  HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	SetServoDuty(iDuty);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}
/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    // 2024-10-28 hjkim, Select Timer
    if (htim->Instance == TIM1)
    {
        // 2024-10-28 hjkim, Toggle GPIO pin A5 for Channel 1
        gServoInfo.enumPinServo = GPIO_PIN_SET;
    }
    else if (htim->Instance == TIM2)
    {
        // 2024-10-28 hjkim, Error: TIM2 is not used
        __NOP();
    }
    else if (htim->Instance == TIM3)
    {
        // 2024-10-28 hjkim, Error: TIM3 is not used
        __NOP();
    }
    else if (htim->Instance == TIM4)
    {
        // 2024-10-28 hjkim, Error: TIM4 is not used
        __NOP();
    }
    else
    {
        // 2024-10-28 hjkim, Error: Invalid channel
        __NOP();
    }

    return;
}
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	// 2024-10-28 hjkim, Select Timer & Channel
	    if(htim->Instance == TIM1)
	    {
	        switch (htim->Channel)
	        {
	            case HAL_TIM_ACTIVE_CHANNEL_1:
	            	gServoInfo.enumPinServo = GPIO_PIN_RESET;
	                break;
	            case HAL_TIM_ACTIVE_CHANNEL_2:
	                // 2024-10-28 hjkim, Error: Channel 2 is not used
	                __NOP();
	                break;
	            case HAL_TIM_ACTIVE_CHANNEL_3:
	                // 2024-10-28 hjkim, Error: Channel 3 is not used
	                __NOP();
	                break;
	            case HAL_TIM_ACTIVE_CHANNEL_4:
	                // 2024-10-28 hjkim, Error: Channel 4 is not used
	                __NOP();
	                break;
	            default:
	                // 2024-10-28 hjkim, Error: Invalid channel
	                __NOP();
	                break;
	        }
	    }
}
/* USER CODE END 4 */
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
