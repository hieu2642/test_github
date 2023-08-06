__HAL_RCC_GPIOD_CLK_ENABLE();
  	  GPIO_InitTypeDef led; //struct
  	  led.Pin = GPIO_PIN_0;
  	  led.Mode = GPIO_MODE_OUTPUT_PP;
  	  led.Pull = GPIO_NOPULL;// ko dùng điện trơr pullup( nếu dùng thì PULLUP)
  	  led.Speed = GPIO_SPEED_FREQ_LOW;

  	  HAL_GPIO_Init(GPIOD, &led);


	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET){

	      	HAL_Delay(100);
	      	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET){

	      			HAL_GPIO_WritePin(GPIOD,num0|num1|num2|num3|num4|num5|num6|num7|num8|num9,GPIO_PIN_SET );
	      	    	HAL_GPIO_TogglePin(GPIOD, num[i]);
	      	    	i = (i + 1)%10;
	      	}
	      }