#include "DO.h"

#define TEST


DO DO_new(GPIO_initTypedef * inistruct)
{
	DO temp;
    DO_init(&temp, inistruct);
    return temp;
}


DO_StatusTypedef DO_init(DO * this , GPIO_initTypedef * initstruct)
{
	//this->init = DO_init;
	this->setPin = DO_setPin;
	this->resetPin = DO_resetPin;
	this->togglePin = DO_TogglePin;


	GPIO_init((GPIO*)this, initstruct);

	#ifdef TEST
	printf("DO init OK\n");
	#endif

	return DO_OK;
}


#ifdef TEST

DO_StatusTypedef DO_setPin(GPIO_PORT port, GPIO_Pin_Number pin)
{

	printf("set port %c , pin %d\n", port, pin);

	return DO_OK;
}

#else

DO_StatusTypedef DO_setPin(GPIO_PORT * port, GPIO_Pin_Number pin);
{
	HAL_GPIO_WritePin((GPIO*)this->GPIOPORT, (GPIO*)this->Pin, GPIO_PIN_SET);

	return DO_OK;
}

#endif


#ifdef TEST

DO_StatusTypedef DO_resetPin(GPIO_PORT port, GPIO_Pin_Number pin)
{

	printf("reset port %c , pin %d\n", port, pin);

	return DO_OK;
}

#else

DO_StatusTypedef DO_resetPin(GPIO_PORT * port, GPIO_Pin_Number pin)
{
	HAL_GPIO_WritePin((GPIO*)this->GPIOPORT, (GPIO*)this->Pin, GPIO_PIN_SET);

	return DO_OK;
}

#endif



DO_StatusTypedef DO_TogglePin(GPIO_PORT port, GPIO_Pin_Number pin)
{
#ifdef TEST
	printf("toggle port %c , pin %d\n", port, pin);
#else
HAL_GPIO_WritePin((GPIO*)this->GPIOPORT, (GPIO*)this->Pin, GPIO_PIN_SET);
#endif
	return DO_OK;

}

