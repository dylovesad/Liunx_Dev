void Delay_us(uint32_t us){
	HAL_TIM_Base_Start(&htim4);
	//__HAL_TIM_SET_COUNTER(&htim4,0);
	htim4.Instance->CNT = 0;
	//__HAL_TIM_GET_COUNTER(&htim4);
	while(htim4.Instance->CNT< us){
	}
	HAL_TIM_Base_Stop(&htim4);
}
