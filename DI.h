#ifndef __DI_H
#define __DI_H

#include "GPIO.h"

#define TEST


typedef enum {
	DI_OK = 0x00U,
	DI_ERR = 0x01U
} DI_StatusTypedef;


typedef enum {
	DI_HIGH, DI_LOW
} DI_pinState;


typedef DI_pinState (*DI_Function)(GPIO_PORT port, GPIO_Pin_Number pin);


typedef struct{

	GPIO;
	//DI_StatusTypedef (*init)(DI *, GPIO_initTypedef * );
	#ifdef TEST
        DI_Function digitalRead;
	#else
		DI_StatusTypedef (*digitalRead)(GPIO_PORT *, GPIO_Pin_Number);
	#endif


} DI;

DI DI_new(GPIO_initTypedef * inistruct);
DI_StatusTypedef DI_init(DI * this , GPIO_initTypedef * initstruct);

#ifdef TEST
    DI_pinState DI_digitalRead(GPIO_PORT port, GPIO_Pin_Number pin);
#else
	DI_pinState DI_digitalRead(GPIO_PORT * port, GPIO_Pin_Number pin);
#endif





#endif /* __DI_H */
