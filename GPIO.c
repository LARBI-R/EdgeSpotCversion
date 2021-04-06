#include "GPIO.h"


#define TEST

GPIO GPIO_new(GPIO_initTypedef * initStruct)
{
	GPIO temp;
    GPIO_init(&temp, initStruct);
    return temp;
}
GPIO_StatusTypedef GPIO_init(GPIO * this, GPIO_initTypedef * initstruct)
{
    switch(initstruct->Pin)
    {
        case GPIO_Pin_0 :
            this->Pin = GPIO_PIN_0;
            break;
        case GPIO_Pin_1 :
            this->Pin = GPIO_PIN_1;
            break;
        case GPIO_Pin_2 :
            this->Pin = GPIO_PIN_2;
            break;
        case GPIO_Pin_3 :
            this->Pin = GPIO_PIN_3;
            break;
        case GPIO_Pin_4 :
            this->Pin = GPIO_PIN_4;
            break;
        case GPIO_Pin_5 :
            this->Pin = GPIO_PIN_5;
            break;
        case GPIO_Pin_6 :
            this->Pin = GPIO_PIN_6;
            break;
        case GPIO_Pin_7 :
            this->Pin = GPIO_PIN_7;
            break;
        case GPIO_Pin_8 :
            this->Pin = GPIO_PIN_8;
            break;
        case GPIO_Pin_9 :
            this->Pin = GPIO_PIN_9;
            break;
        case GPIO_Pin_10 :
            this->Pin = GPIO_PIN_10;
            break;
        case GPIO_Pin_11 :
            this->Pin = GPIO_PIN_11;
            break;
        case GPIO_Pin_12 :
            this->Pin = GPIO_PIN_12;
            break;
        case GPIO_Pin_13 :
            this->Pin = GPIO_PIN_13;
            break;
    }

    switch(initstruct->Mode)
    {
        case GPIO_FLOATINPUT :
            this->Mode = GPIO_MODE_INPUT;
            break;
        case GPIO_OUTPUT_PP :
            this->Moode = GPIO_MODE_OUTPUT_PP ;
            break;
        case GPIO_OUTPUT_OD:
            this->Mode = GPIO_MODE_OUTPUT_OD;
            break;
    }
    this->Mode = initstruct->Mode;

	this->GPIOPORT = initstruct->GPIOPORT;
	this->Pull = initstruct->Pull;
	this->Speed = initstruct->Speed;
	this->Alternate = initstruct->Alternate;
	/*this->init = GPIO_init;
	this->deinit = GPIO_deinit;*/

	#ifdef TEST
	switch(this->GPIOPORT)
	{
		case 'A' :
			printf("activation clock GPIOA\n");
			break;
		case 'B' :
			printf("activation clock GPIOB\n");
			break;
		case 'C' :
			printf("activation clock GPIOC\n");
			break;
		case 'D' :
			printf("activation clock GPIOD\n");
		break;
	}

	printf("initialisation du port %c pin num %d\n", this->GPIOPORT, this->Pin);

	#else

	switch(this->GPIOPORT)
	{
		case GPIOA :
			__HAL_RCC_GPIOA_ENABLE();
			break;
		case GPIOB :
			__HAL_RCC_GPIOB_ENABLE();
			break;
		case GPIOC :
			__HAL_RCC_GPIOC_ENABLE();
			break;
		case GPIOD :
			__HAL_RCC_GPIOD_ENABLE();
			break;
	}

	HAL_GPIO_Init(this->GPIOPORT, initStruct);

	#endif

	return GPIO_OK;
}

GPIO_StatusTypedef GPIO_deinit(GPIO * this)
{
	#ifdef TEST
		printf("remise a zero port %c\n", this->GPIOPORT);
		this->Pin = 0;
		this->Mode = 0;
		this->GPIOPORT = '\0';
		this->Pull = 0;
		this->Speed = 0;
		this->Alternate = 0;

	#else
		this->Pin = 0;
		this->Mode = 0;
		this->GPIOPORT = NULL;
		this->Pull = 0;
		this->Speed = 0;
		this->Alternate = 0;
	#endif

	return GPIO_OK;
}
