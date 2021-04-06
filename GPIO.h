#ifndef __GPIO_H
#define __GPIO_H



#define TEST


#ifdef TEST
	#include <stdio.h>
	#define uint32_t   unsigned long
	#define uint16_t   unsigned short
	#define uint8_t    unsigned char
#else
	#include "stm32l4xx_hal.h"
#endif


typedef enum {
			GPIO_NOPULL,
			GPIO_PULLUP,
			GPIO_PULLDOWN

} GPIO_PullTypedef;

#ifdef TEST

typedef enum {
	GPA = 'A', GPB = 'B', GPC = 'C', GPD = 'D'
} GPIO_PORT;



typedef enum {

		GPIO_Pin_0, GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_3, GPIO_Pin_4, GPIO_Pin_5, GPIO_Pin_6, GPIO_Pin_7, GPIO_Pin_8, GPIO_Pin_9, GPIO_Pin_10, GPIO_Pin_11, GPIO_Pin_12, GPIO_Pin_13

} GPIO_Pin_Number;

#else

typedef enum {
	GPA = GPIOA, GPB = GPIOB, GPC = GPIOC, GPD = GPIOD
} GPIO_PORT;


typedef enum {

	GPIO_Pin_0,
	GPIO_Pin_1,
	GPIO_Pin_2,
	GPIO_Pin_3,
	GPIO_Pin_4,
	GPIO_Pin_5,
	GPIO_Pin_6,
	GPIO_Pin_7,

} GPIO_Pin_Number;
#endif



typedef enum {
			GPIO_FREQ_LOW,
		    GPIO_FREQ_MEDIUM,
		    GPIO_FREQ_HIGH,
		    GPIO_FREQ_VERY_HIGH
} GPIO_SpeedTypedef;

//EDGS

typedef enum {
	GPIO_OK = 0x00U,
	GPIO_ERR = 0x01U
} GPIO_StatusTypedef;


typedef enum {
	GPIO_LOW, GPIO_HIGH
} GPIO_pinState;

typedef enum {
  GPIO_FLOATINPUT,
  GPIO_OUTPUT_PP,
  GPIO_OUTPUT_OD
} GPIO_Mode;


typedef struct
{
	uint16_t Pin;
	#ifdef TEST
	char GPIOPORT;
	#else
	GPIO_TypeDef * GPIOPORT;
	#endif
	uint32_t Mode;
	uint32_t Pull;
	uint32_t Speed;
	uint32_t Alternate;
	/*GPIO_StatusTypedef (*init) ( GPIO *, GPIO_initTypedef *);
	GPIO_StatusTypedef (*deinit)(GPIO *);*/

} GPIO;


typedef struct {
	uint16_t Pin;
	#ifdef TEST
	char GPIOPORT;
	#else
	GPIO_TypeDef * GPIOPORT;
	#endif
	uint32_t Mode;
	uint32_t Pull;
	uint32_t Speed;
	uint32_t Alternate;

}GPIO_initTypedef;


GPIO GPIO_new(GPIO_initTypedef * initStruct);
GPIO_StatusTypedef GPIO_init(GPIO * this, GPIO_initTypedef * initStruct);
GPIO_StatusTypedef GPIO_deinit(GPIO * this);


#endif /* __GPIO_H */
