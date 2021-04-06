//#include "GPIO.h"
#include "DI.h"
#include "DO.h"


#define TEST

int main()
{
#ifdef TEST

int flag;




// ------------------------------- PORT init ----------------------------------------//


    // LED init
	GPIO_initTypedef initstruct = {0};


	initstruct.Pin = GPIO_Pin_5;
	initstruct.GPIOPORT = GPA;
	initstruct.Mode = GPIO_OUTPUT_PP;
	initstruct.Pull = GPIO_NOPULL;
	initstruct.Speed = GPIO_FREQ_LOW;

	DO builtinLED = DO_new(&initstruct);


	// Button init
	GPIO_initTypedef initstruct2 = {0};


	initstruct2.Pin = GPIO_Pin_6;
	initstruct2.GPIOPORT = GPB;
	initstruct2.Mode = GPIO_FLOATINPUT;
	initstruct2.Pull = GPIO_NOPULL;

	DI userButton = DI_new(&initstruct2);



// ------------------------------- Application ----------------------------------------//

    while (1)
    {

        if (userButton.digitalRead(GPB, GPIO_Pin_6) == DI_HIGH) //read button
        {
            printf("*-*-*-*-*-*Button pressed*-*-*-*-*-*\n");
            flag = !flag;
        }

        if (flag == 1)
        {
            printf("*-*-*-*-*-*Alumer LED *-*-*-*-*-*\n");
            builtinLED.setPin(GPA, GPIO_Pin_5); // LED set
            flag = 0;
        }
        else
        {
            printf("*-*-*-*-*-*Eteindre LED *-*-*-*-*-*\n");
            builtinLED.resetPin(GPA, GPIO_Pin_5); // LED set
        }
    }



#else

	GPIO_initTypedef initstruct = {0};


	initstruct.Pin = GPIO_PIN_5;
	initstruct.GPIOPORT = GPIOA;
	initstruct.Mode = GPIO_OUTPUT_PP;
	initstruct.Pull = GPIO_NOPULL;
	initstruct.Speed = GPIO_FREQ_LOW;

	DO builtinLED = DO_new(&initstruct);

	while(1)
	{

		builtinLED.setPin(&DO);
		HAL_Delay(200);
		builtinLED.resetPin(&DO);
		HAL_Delay(200);
	}


#endif

	return 0;
}
