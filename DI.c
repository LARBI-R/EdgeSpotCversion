#include "DI.h"

#define TEST


DI DI_new(GPIO_initTypedef * inistruct)
{
	DI temp;
    DI_init(&temp, inistruct);
    return temp;
}


DI_StatusTypedef DI_init(DI * this, GPIO_initTypedef * initstruct)
{

	//this->init = DI_init;

	this->digitalRead = DI_digitalRead;

	GPIO_init((GPIO*)this, initstruct);

	#ifdef TEST
	printf("DI init OK\n");
	#endif

	return DI_OK;
}

#ifdef TEST
DI_pinState DI_digitalRead(GPIO_PORT port, GPIO_Pin_Number pin)
{
		int test;
		printf("wait for push button 1/0\n");
		scanf("%d",&test);

		if ( test == 1)
		{
			printf("port %c , pin %d = %d\n", port, pin, test);
			return DI_HIGH;
		}
		else
		{
			printf("port %c , pin %d = %d\n", port, pin, test);
			return DI_LOW;
		}

}

#else
DI_pinState DI_digitalRead(GPIO_PORT * port, GPIO_Pin_Number pin)
{
		if ( HAL_GPIO_ReadPin((GPIO*)this->GPIOPORT, (GPIO*)this->Pin) == GPIO_PIN_SET)
		{
			return DI_HIGH;
		}
		else
		{
			return DI_LOW;
		}
}

#endif
