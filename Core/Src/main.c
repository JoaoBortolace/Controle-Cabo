/*
 * main.c
 *
 *  Created on: Jun 27, 2024
 *      Author: borto
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Defines -------------------------------------------------------------------*/
#define TIMEOUT_MAX 25000000

/* Variáveis globais externas ------------------------------------------------*/
int16_t passo = 0;
int16_t cont = 0;
bool andar = false;
DIR_BOBINA dir = IMOVEL;

extern int32_t bobina_voltas = 0;
extern int32_t carro_transversal_voltas = 0;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Program_Init(void);

static void Home(void);

/* Main ----------------------------------------------------------------------*/
int main(void)
{
	/* MCU Configuration */
	HAL_Init();

	/* Configura o Clock */
	SystemClock_Config();

	/* Configura os periféricos */
	BSP_Init();
	Program_Init();

	/* Leva o carro transveral para a direita */
	Home();

	DIR_BOBINA dir_prev = dir;
	MOTOR_DIR motor_dir = PARADO;

  	/* Infinite loop */
  	while (true)
  	{
  		bool fim_curso_1 = BSP_GPIO_ReadPin(FIM_CURSO_1_Port, FIM_CURSO_1_Pin);
  		bool fim_curso_2 = BSP_GPIO_ReadPin(FIM_CURSO_2_Port, FIM_CURSO_2_Pin);

  		if (fim_curso_1 && fim_curso_2) /* Ambos fins de cursos acionados */
  		{
			  Motor_Transversal_Ctrl(PARADO);
  		}
  		else
  		{
  	  		if (andar)
  	  		{
  	  			if (dir_prev != dir)
  	  			{
  	  				dir_prev = dir;

  	  				if (motor_dir == HORARIO)
  	  				{
  	  					motor_dir = ANTI_HORARIO;
  	  				}
  	  				else
  	  				{
  	  					motor_dir = HORARIO;
  	  				}
  	  			}

  	  			if (fim_curso_1)
  	  	  	  	{
  					motor_dir = ANTI_HORARIO;
  	  	  	  	}

  	  	  	  	if (fim_curso_2)
  	  	  	  	{
  					motor_dir = HORARIO;
  	  	  	  	}

  	  	  	  	Motor_Transversal_Ctrl(motor_dir);

  	  		}
  		  	else // Imovel
  		  	{
  			  	Motor_Transversal_Ctrl(FREIO);
  		  	}
  		}
  	}
}

static void Home(void)
{
	uint32_t timeout = 0;

	while(!BSP_GPIO_ReadPin(FIM_CURSO_2_Port, FIM_CURSO_2_Pin) && timeout < TIMEOUT_MAX)
	{
		Motor_Transversal_Ctrl(ANTI_HORARIO);
		timeout++;
	}

	Motor_Transversal_Ctrl(PARADO);
}

static void Program_Init(void)
{
	Motor_Bobina_Init();
	Motor_Transversal_Init();
	OPTO_Init();

	/* Configura os pinos dos fins de curso */
	GPIO_Config pinConfig = {0};
	pinConfig.modo = ENTRADA_NoPull;
  	BSP_GPIO_Init(FIM_CURSO_1_Port, FIM_CURSO_1_Pin, &pinConfig);
  	BSP_GPIO_Init(FIM_CURSO_2_Port, FIM_CURSO_2_Pin, &pinConfig);

  	/* Seta o pinos de saída do ENAOUT03 */
  	BSP_GPIO_SetPin(ENAOUT03_Port, ENAOUT03_Pin); /* Habilitas as saídas digitais 0 -> 3 */
  	/* Seta o pinos de saída do ENAOUT04 */
  	BSP_GPIO_SetPin(ENAOUT04_Port, ENAOUT04_Pin); /* Habilitas as saídas digitais 4 -> 7 */

#ifdef DEBUG
  	BSP_GPIO_ResetPin(LED2_Port, LED2_Pin);
#endif
}

/* Configura o CPU para 90MHz usando o HSE pelo PLL */
void SystemClock_Config(void)
{
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 15;
	RCC_OscInitStruct.PLL.PLLN = 108;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 4;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		BSP_Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
	                             |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		BSP_Error_Handler();
	}
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
