int main(void)
{
/* Initialize all configured peripherals */
MX_GPIO_Init();
MX_DMA_Init();
MX_TIM3_Init();
MX_USART1_UART_Init();
/* USER CODE BEGIN 2 */
printf("Uart1 init is ok");
__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE); //使能串UART1 IDLE(空闲)中断
HAL_UART_Receive_DMA(&huart1, RX1_Buf, DMA_BUF_SIZE); //设置DMA传输，将uart1的数据搬运到RX1_Buf中
/* USER CODE END 2 */
/* Infinite loop */
/* USER CODE BEGIN WHILE */
while (1)
{
/* USER CODE END WHILE */
/* USER CODE BEGIN 3 */
}
/* USER CODE END 3 */
