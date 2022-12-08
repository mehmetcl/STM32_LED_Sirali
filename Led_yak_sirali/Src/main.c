

#include <stdint.h>
#include "stm32f407xx_gpio.h"
#include"stm32f407xx.h"
#include<stdio.h>
#include <stdlib.h>

//#define   	SECOND_1 	        2000000
//#define   	DELAY_MS(x) 		((x)*(SECOND_1))
void delay()
{
	for(int i=0;i<300000;++i)
		;
}



int isprime(int xrandom){

    xrandom=2+rand()%50;
	int kalan = 0;

	  for(int i=2; i<=xrandom/2; i++)
	  {
	     if(xrandom%i == 0)
	     {
	       kalan=1;
	       break;
	     }
	  }

	  if(xrandom == 1) kalan = 1;

	  return kalan;



}



int main(void)
{

    int xrandom,res=0;
	GPIO_Handle_t gpioled12={GPIOD,{GPIO_PIN_0,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_PD,GPIO_OTYPE_PP}};
	              gpio_init(&gpioled12);
	GPIO_Handle_t gpioled14={GPIOD,{GPIO_PIN_2,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_PD,GPIO_OTYPE_PP}};
			      gpio_init(&gpioled14);
	GPIO_Handle_t gpioled16={GPIOD,{GPIO_PIN_4,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_PD,GPIO_OTYPE_PP}};
				  gpio_init(&gpioled16);
    GPIO_Handle_t gpioled18={GPIOD,{GPIO_PIN_6,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_PD,GPIO_OTYPE_PP}};
	        	  gpio_init(&gpioled18);

	GPIO_Handle_t gpioled13={GPIOD,{GPIO_PIN_1,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_PD,GPIO_OTYPE_PP}};
	        	  gpio_init(&gpioled13);
	GPIO_Handle_t gpioled15={GPIOD,{GPIO_PIN_3,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_PD,GPIO_OTYPE_PP}};
	        	  gpio_init(&gpioled15);
	GPIO_Handle_t gpioled17={GPIOD,{GPIO_PIN_5,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_PD,GPIO_OTYPE_PP}};
	        	  gpio_init(&gpioled17);

	GPIO_Handle_t gpioled19={GPIOD,{GPIO_PIN_7,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_PD,GPIO_OTYPE_PP}};
	        	  gpio_init(&gpioled19);






while(1){
	res=isprime(xrandom);
	if (res == 0 ) {

		gpio_pin_reset(GPIOD, GPIO_PIN_7, RESET);
	    delay();
	    gpio_pin_reset(GPIOD, GPIO_PIN_6, RESET);
	    delay();
		gpio_pin_reset(GPIOD, GPIO_PIN_5, RESET);
		delay();
		gpio_pin_reset(GPIOD, GPIO_PIN_4, RESET);
		delay();
	    gpio_pin_reset(GPIOD, GPIO_PIN_3, RESET);
	    delay();
	    gpio_pin_reset(GPIOD, GPIO_PIN_2, RESET);
	    delay();
	    gpio_pin_reset(GPIOD, GPIO_PIN_1, RESET);
	    delay();
	    gpio_pin_reset(GPIOD, GPIO_PIN_0, RESET);
	    delay();


}
	else if (res == 1 ){
		gpio_pin_reset(GPIOD, GPIO_PIN_7, RESET);
			    delay();
			    gpio_pin_reset(GPIOD, GPIO_PIN_6, RESET);
			    delay();
				gpio_pin_reset(GPIOD, GPIO_PIN_5, RESET);
				delay();
				gpio_pin_reset(GPIOD, GPIO_PIN_4, RESET);
				delay();
			    gpio_pin_reset(GPIOD, GPIO_PIN_3, RESET);
			    delay();
			    gpio_pin_reset(GPIOD, GPIO_PIN_2, RESET);
			    delay();
			    gpio_pin_reset(GPIOD, GPIO_PIN_1, RESET);
			    delay();
			    gpio_pin_reset(GPIOD, GPIO_PIN_0, RESET);
			    delay();


		  gpio_pin_set(GPIOD, GPIO_PIN_1, SET);//2led
		    delay();
		  gpio_pin_set(GPIOD, GPIO_PIN_3, SET);//4led
		    delay();
		  gpio_pin_set(GPIOD, GPIO_PIN_5, SET);//6led
		    delay();
		  gpio_pin_set(GPIOD, GPIO_PIN_7, SET);//8led
		    delay();

		  gpio_pin_set(GPIOD, GPIO_PIN_0, SET);//1led
		    delay();
		  gpio_pin_set(GPIOD, GPIO_PIN_2, SET);//3led
		    delay();
		  gpio_pin_set(GPIOD, GPIO_PIN_4, SET);//5led
		    delay();
		  gpio_pin_set(GPIOD, GPIO_PIN_6, SET);//7led
		    delay();



                      }






	}

}

