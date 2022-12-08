/*
 * stm32f407xx_gpio.c
 *
 *  Created on: Mar 12, 2022
 *      Author: samet
 */
#include "stm32f407xx_gpio.h"
#include "stm32f407xx.h"

 static void gpio_clock_en_di(GPIO_RegDef_t *pGPIOx ,BOOL state);

void gpio_clock_en_di(GPIO_RegDef_t *pGPIOx ,BOOL state)
{
	if(state == ENABLE)
	{
		if(pGPIOx == GPIOA)
			GPIOA_CLOCK_EN();
		else if(pGPIOx == GPIOB)
			GPIOB_CLOCK_EN();
		else if(pGPIOx == GPIOC)
			GPIOC_CLOCK_EN();
		else if(pGPIOx == GPIOD)
			GPIOD_CLOCK_EN();
		else if(pGPIOx == GPIOE)
			GPIOE_CLOCK_EN();
		else if(pGPIOx == GPIOF)
			GPIOF_CLOCK_EN();
		else if(pGPIOx == GPIOG)
			GPIOG_CLOCK_EN();
		else if(pGPIOx == GPIOH)
			 GPIOH_CLOCK_EN();
		else if(pGPIOx == GPIOI)
			GPIOI_CLOCK_EN();
	}
	if(state == DISABLE)
		;
}

void gpio_init(GPIO_Handle_t *pgpio_handle)
{
	uint32_t temp=0;

	gpio_clock_en_di(pgpio_handle->pGPIOx ,ENABLE);

	// 24 ve 25.bite 01 yazmak lazım
	//1.mode seçimi yapılacak
	temp = (pgpio_handle->gpio_pin_config.pin_mode <<(2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->MODER &= ~(0b11<<(2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->MODER |=temp;
	//2. otype
	temp  = (pgpio_handle->gpio_pin_config.pin_otype << (pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->OTYPER &= ~(1u<<(2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->OTYPER |= temp;
	//3.speed
	temp  = (pgpio_handle->gpio_pin_config.pin_speed << (2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->OSPEEDR &= ~(0b11<<(2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->OSPEEDR |= temp;

	//4.pupd
	temp  = (pgpio_handle->gpio_pin_config.pin_pu_pd << (2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->PUPDR &= ~(0b11<<(2*pgpio_handle->gpio_pin_config.pin_number));
	pgpio_handle->pGPIOx->PUPDR |= temp;

	//5.alternate
}


void gpio_write_out_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no,BOOL val)
{
	if ( val == SET)
		pgpiox->ODR |= (1u<<pin_no);  // 1000
	else
		pgpiox->ODR &= ~(1u<<pin_no);
}

BOOL gpio_read_input_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no)
{
	uint8_t res =(uint8_t)((pgpiox->IDR)& (1 << pin_no));
	return res;
}

void gpio_toggle_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no)
{
	pgpiox->ODR ^= (1u<<pin_no);
}
void gpio_pin_reset(GPIO_RegDef_t *pgpiox,uint8_t pin_no)
{
	if ( val == SET)
		pgpiox->ODR |= (1u<<pin_no);  // 1000
	else
		pgpiox->ODR &= ~(1u<<pin_no);
}
