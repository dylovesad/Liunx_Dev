void Delay_us(uint32_t us){
	HAL_TIM_Base_Start(&htim4);
	//__HAL_TIM_SET_COUNTER(&htim4,0);
	htim4.Instance->CNT = 0;
	//__HAL_TIM_GET_COUNTER(&htim4);
	while(htim4.Instance->CNT< us){
	}
	HAL_TIM_Base_Stop(&htim4);
}

void Delay_ms(uint32_t us){
	for(uint32_t i=0;i<ms;++i){
		Delay_us(1000);
	}
}
