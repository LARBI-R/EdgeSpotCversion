#ifndef __DO_H
#define __DO_H

#include "GPIO.h"

#define TEST


typedef enum {
	DO_OK = 0x00U,
	DO_ERR = 0x01U
} DO_StatusTypedef;


typedef enum {
	DO_LOW, DO_HIGH
} DO_pinState;


typedef DO_StatusTypedef (*DO_Function)(GPIO_PORT port, GPIO_Pin_Number pin);

typedef struct{

	GPIO;
	//DO_StatusTypedef (*init)(DO *, GPIO_initTypedef * );

	#ifdef TEST
		//DO_StatusTypedef (*setPin)(GPIO_PORT, GPIO_Pin_Number);
		//DO_StatusTypedef (*resetPin)(GPIO_PORT, GPIO_Pin_Number);
		//DO_StatusTypedef (*togglePin)(GPIO_PORT, GPIO_Pin_Number);
		DO_Function setPin;
		DO_Function resetPin;
		DO_Function togglePin;
	#else
		DO_StatusTypedef (*setPin)(GPIO_PORT *, GPIO_Pin_Number);
		DO_StatusTypedef (*resetPin)(GPIO_PORT *, GPIO_Pin_Number);
		DO_StatusTypedef (*togglePin)(GPIO_PORT *, GPIO_Pin_Number);
	#endif



} DO;


DO DO_new(GPIO_initTypedef * inistruct);
DO_StatusTypedef DO_init(DO * this , GPIO_initTypedef * initstruct);

#ifdef TEST
DO_StatusTypedef DO_setPin(GPIO_PORT port, GPIO_Pin_Number pin);
DO_StatusTypedef DO_resetPin(GPIO_PORT port, GPIO_Pin_Number pin);
DO_StatusTypedef DO_TogglePin(GPIO_PORT port, GPIO_Pin_Number pin);
#else
DO_StatusTypedef DO_setPin(GPIO_PORT * port, GPIO_Pin_Number pin);
DO_StatusTypedef DO_resetPin(GPIO_PORT * port, GPIO_Pin_Number pin);
DO_StatusTypedef togglePin(GPIO_PORT * port, GPIO_Pin_Number pin);
#endif



#endif /* __DI_H */
