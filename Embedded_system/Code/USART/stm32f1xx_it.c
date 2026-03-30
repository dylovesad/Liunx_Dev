/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void USER_UART_IRQHandler(UART_HandleTypeDef *huart);
/* USER CODE END PFP */
/**
* @brief This function handles USART1 global interrupt.
*/
void USART1_IRQHandler(void)
{
/* USER CODE BEGIN USART1_IRQn 0 */
/* USER CODE END USART1_IRQn 0 */
HAL_UART_IRQHandler(&huart1);
/* USER CODE BEGIN USART1_IRQn 1 */
USER_UART_IRQHandler(&huart1);
/* USER CODE END USART1_IRQn 1 */
}
/* USER CODE BEGIN 1 */
// DMA 接收到一半的中断
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart)
{
if(huart->Instance == USART1)
{
uint8_t Length = DMA_BUF_SIZE/2 - RX1_Offset ;
//printf("HLength=%d\n",Length);
HAL_UART_Transmit(huart,RX1_Buf+RX1_Offset,Length,HAL_MAX_DELAY);
RX1_Offset += Length;
}
}
// DMA传输完成中断 , 就是接收满了的时候 触发中断
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
if(huart->Instance == USART1)
{
uint8_t Length = DMA_BUF_SIZE - RX1_Offset ;
HAL_UART_Transmit(huart,RX1_Buf+RX1_Offset,Length,HAL_MAX_DELAY);
//printf("CLength=%d\n",Length);
RX1_Offset = 0 ; // 清空dma 位置基准值
}
}
// 用户自定义的函数 ， 处理串口空闲中断
void USER_UART_IRQHandler(UART_HandleTypeDef *huart)
{
if(huart->Instance == USART1) //判断是否是串口1
{
if(__HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE) != RESET ) //判断是否是空闲中断
{
__HAL_UART_CLEAR_IDLEFLAG(huart); //清除空闲中断标志（否则会一直不断进入中断）
//计算接收到的数据长度 : BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart1_rx)
uint8_t Length = DMA_BUF_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart1_rx) - RX1_Offset;
HAL_UART_Transmit(huart,RX1_Buf+RX1_Offset,Length,HAL_MAX_DELAY);
RX1_Offset += Length;
//printf("ILength=%d\n",Length);
}
}
}
/* USER CODE END 1 */
