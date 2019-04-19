/**
  ******************************************************************************
  * File Name          : H1BR7_DMA.c
  * Description        : This file provides code for the configuration
  *                      of the DMA instances.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
	
/*
		MODIFIED by Hexabitz for BitzOS (BOS) V0.1.5 - Copyright (C) 2017-2018 Hexabitz
    All rights reserved
*/

/* Includes ------------------------------------------------------------------*/
#include "BOS.h"



/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/


/* Variables ---------------------------------------------------------*/

DMA_HandleTypeDef portMemDMA1;
DMA_HandleTypeDef portMemDMA2;
DMA_HandleTypeDef portMemDMA3;
DMA_HandleTypeDef portPortDMA1;
DMA_HandleTypeDef portPortDMA2;
DMA_HandleTypeDef portPortDMA3;
DMA_HandleTypeDef portPortDMA4;

UART_HandleTypeDef* dmaStreamDst[4] = {0};

uint32_t DMAStream1count = 0, DMAStream2count = 0, DMAStream3count = 0, DMAStream4count = 0;
uint32_t DMAStream1total = 0, DMAStream2total = 0, DMAStream3total = 0, DMAStream4total = 0;

/* Private function prototypes -----------------------------------------------*/
void PortMemDMA1_Init(void);
void PortMemDMA2_Init(void);
void PortMemDMA3_Init(void);
void PortPortDMA1_Init(void);
void PortPortDMA2_Init(void);
void PortPortDMA3_Init(void);
void PortPortDMA4_Init(void);

/*-----------------------------------------------------------*/

/** 
  * Enable DMA controller clock
  */
void MX_DMA_Init(void) 
{
	/* DMA controller clock enable */
	__DMA1_CLK_ENABLE();	
	PortMemDMA1_Init();
	PortPortDMA1_Init();
	PortPortDMA2_Init();
}

/*-----------------------------------------------------------*/

/* Messaging DMA 1 (port-to-memory) initialization */
void PortMemDMA1_Init(void)
{

}

/*-----------------------------------------------------------*/

/* Messaging DMA 1 (port-to-memory) setup */
void PortMemDMA1_Setup(UART_HandleTypeDef* huart, uint8_t num)
{	
		
}

/*-----------------------------------------------------------*/

/* Streaming DMA 1 (port-to-port) initialization */
void PortPortDMA1_Init(void)
{

}

/*-----------------------------------------------------------*/

/* Streaming DMA 1 (port-to-port) setup */
void PortPortDMA1_Setup(UART_HandleTypeDef* huartSrc, UART_HandleTypeDef* huartDst, uint8_t num)
{		

}

/*-----------------------------------------------------------*/

/* Streaming DMA 2 (port-to-port) initialization */
void PortPortDMA2_Init(void)
{

}

/*-----------------------------------------------------------*/

/* Streaming DMA 2 (port-to-port) setup */
void PortPortDMA2_Setup(UART_HandleTypeDef* huartSrc, UART_HandleTypeDef* huartDst, uint8_t num)
{		

}

/*-----------------------------------------------------------*/

/* --- Stop port-to-port DMA 1 --- 
*/
void StopPortPortDMA1(void)
{
	HAL_DMA_Abort(&portPortDMA1);
	portPortDMA1.Instance->CNDTR = 0;
	DMAStream1count = 0;
	DMAStream1total = 0;
	portStatus[GetPort(portPortDMA1.Parent)] = FREE; 
	portStatus[GetPort(dmaStreamDst[0])] = FREE;
	/* Read these ports again */
	HAL_UART_Receive_IT(portPortDMA1.Parent, (uint8_t *)&cRxedChar, 1);
	HAL_UART_Receive_IT(dmaStreamDst[0], (uint8_t *)&cRxedChar, 1);
	dmaStreamDst[0] = 0;
}

/*-----------------------------------------------------------*/

/* --- Stop port-to-port DMA 2 --- 
*/
void StopPortPortDMA2(void)
{
	HAL_DMA_Abort(&portPortDMA2);
	portPortDMA2.Instance->CNDTR = 0;
	DMAStream2count = 0;
	DMAStream2total = 0;
	portStatus[GetPort(portPortDMA2.Parent)] = FREE; 
	portStatus[GetPort(dmaStreamDst[1])] = FREE;	
	/* Read these ports again */
	HAL_UART_Receive_IT(portPortDMA2.Parent, (uint8_t *)&cRxedChar, 1);
	HAL_UART_Receive_IT(dmaStreamDst[1], (uint8_t *)&cRxedChar, 1);
	dmaStreamDst[1] = 0;	
}

/*-----------------------------------------------------------*/


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
