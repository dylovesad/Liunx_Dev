/* usart.h

/* USER CODE BEGIN Private defines */
#define DMA_BUF_SIZE 256
extern uint8_t RX1_Offset ; // 计算偏移量 , 用来计算接收数据长度的
extern uint8_t RX1_Buf[]; // 接收数据存放的数组
/* USER CODE END Private defines */

/* usart.c

/* USER CODE BEGIN 0 */
#include <stdio.h>
uint8_t RX1_Offset = 0 ; // 计算偏移量 , 用来计算接收数据长度的
uint8_t RX1_Buf[DMA_BUF_SIZE]; // 接收数据存放的数组
/* USER CODE END 0 */
