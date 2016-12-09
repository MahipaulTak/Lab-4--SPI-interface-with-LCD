/*
 * Flash_LED6CPP.cpp
 *
  *   *  Created on: Nov 20, 2016
 *      Author: Mahipaul Tak and Alex Minifie
 */

#include <uTTCOSg2016/uTTCOSg.h>
#include <GPIO2016/ADSP_GPIO_Interface.h>

#if 1
#include <GPIO2016/ADSP_GPIO_Interface.h>
#include "Lab0_Library.h"

#define BEGIN_STATE case
#define END_STATE break;
// led 1 starting condition

// led 6 starting conditions



	enum bitwise_LED1_State {LED1_JUST_STARTED, LED1_IS_OFF, LED1_IS_ON};
		static bitwise_LED1_State currentState_LED1 = LED1_JUST_STARTED;
	enum bitwise_LED2_State {LED2_JUST_STARTED, LED2_IS_OFF, LED2_IS_ON};
		static bitwise_LED2_State currentState_LED2 = LED2_JUST_STARTED;
	enum bitwise_LED3_State {LED3_JUST_STARTED, LED3_IS_OFF, LED3_IS_ON};
		static bitwise_LED3_State currentState_LED3 = LED3_JUST_STARTED;
	enum bitwise_LED4_State {LED4_JUST_STARTED, LED4_IS_OFF, LED4_IS_ON};
		static bitwise_LED4_State currentState_LED4 = LED4_JUST_STARTED;
	enum bitwise_LED5_State {LED5_JUST_STARTED, LED5_IS_OFF, LED5_IS_ON};
		static bitwise_LED5_State currentState_LED5 = LED5_JUST_STARTED;

		enum bitwise_LED6_State {LED6_JUST_STARTED, LED6_IS_OFF, LED6_IS_ON};
			static bitwise_LED6_State currentState_LED6 = LED6_JUST_STARTED;

#endif
void Flash_Led6(void )
{

#if 1
	bitwise_LED6_State nextStateToDo = currentState_LED6;
	unsigned char gpioinput;
	unsigned char gpiooutput;
	switch (currentState_LED6)
	{
		BEGIN_STATE LED6_JUST_STARTED:
			gpioinput = Read_LED_GPIOInterface();
			gpiooutput = (gpioinput & (~0x20)); // turn led off
			Write_LED_GPIOInterface(gpiooutput);
			nextStateToDo = LED6_IS_OFF;
		END_STATE

		BEGIN_STATE LED6_IS_OFF:
			gpioinput = Read_LED_GPIOInterface();
			gpiooutput = (gpioinput | (0x20)); // turn led ON
			Write_LED_GPIOInterface(gpiooutput);
			nextStateToDo = LED6_IS_ON;
		END_STATE

		BEGIN_STATE LED6_IS_ON:
			gpioinput = Read_LED_GPIOInterface();
			gpiooutput = (gpioinput & (~0x20)); // turn led off
			Write_LED_GPIOInterface(gpiooutput);
			nextStateToDo = LED6_IS_OFF;
		END_STATE

	}
	currentState_LED6 = nextStateToDo;
#else

	static int state1 = 0;
	if (state1) Write_LED_GPIOInterface(0xF); else Write_LED_GPIOInterface(0x0);
	state1 = 1 - state1;
#endif
}

#if 1
void Flash_LED1(void )
{

	bitwise_LED1_State nextStateToDo = currentState_LED1;
	unsigned char gpioinput;
	unsigned char gpiooutput;
	switch (currentState_LED1)
	{
		BEGIN_STATE LED1_JUST_STARTED:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput & (~0x01)); // turn led off
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED1_IS_OFF;
		END_STATE

		BEGIN_STATE LED1_IS_OFF:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput | (0x01)); // turn led ON
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED1_IS_ON;
		END_STATE

		BEGIN_STATE LED1_IS_ON:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput & (~0x01)); // turn led off
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED1_IS_OFF;
		END_STATE

	}
	currentState_LED1 = nextStateToDo;
}


void Flash_LED2(void )
{

	bitwise_LED2_State nextStateToDo = currentState_LED2;
	unsigned char gpioinput;
	unsigned char gpiooutput;
	switch (currentState_LED2)
	{
		BEGIN_STATE LED2_JUST_STARTED:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput & (~0x02)); // turn led off
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED2_IS_OFF;
		END_STATE

		BEGIN_STATE LED2_IS_OFF:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput | (0x02)); // turn led ON
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED2_IS_ON;
		END_STATE

		BEGIN_STATE LED2_IS_ON:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput & (~0x02)); // turn led off
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED2_IS_OFF;
		END_STATE

	}
	currentState_LED2 = nextStateToDo;
}


void Flash_LED3(void )
{

	bitwise_LED3_State nextStateToDo = currentState_LED3;
	unsigned char gpioinput;
	unsigned char gpiooutput;
	switch (currentState_LED3)
	{
		BEGIN_STATE LED3_JUST_STARTED:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput & (~0x04)); // turn led off
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED3_IS_OFF;
		END_STATE

		BEGIN_STATE LED3_IS_OFF:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput | (0x04)); // turn led ON
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED3_IS_ON;
		END_STATE

		BEGIN_STATE LED3_IS_ON:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput & (~0x04)); // turn led off
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED3_IS_OFF;
		END_STATE

	}
	currentState_LED3 = nextStateToDo;
}



void Goldilocks_wandcrtl(void )
{

	bitwise_LED4_State nextStateToDo = currentState_LED4;
	unsigned char gpioinput;
	unsigned char gpiooutput;
	switch (currentState_LED4)
	{
		BEGIN_STATE LED4_JUST_STARTED:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput & (~0x08)); // turn led off
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED4_IS_OFF;
		END_STATE

		BEGIN_STATE LED4_IS_OFF:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput | (0x08)); // turn led ON
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED4_IS_ON;
		END_STATE

		BEGIN_STATE LED4_IS_ON:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput & (~0x08)); // turn led off
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED4_IS_OFF;
		END_STATE

	}
	currentState_LED4 = nextStateToDo;
}

void Christineledthreadflasher(void )
{

	bitwise_LED5_State nextStateToDo = currentState_LED5;
	unsigned char gpioinput;
	unsigned char gpiooutput;
	switch (currentState_LED5)
	{
		BEGIN_STATE LED5_JUST_STARTED:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput & (~0x10)); // turn led off
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED5_IS_OFF;
		END_STATE

		BEGIN_STATE LED5_IS_OFF:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput | (0x10)); // turn led ON
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED5_IS_ON;
		END_STATE

		BEGIN_STATE LED5_IS_ON:
		gpioinput = Read_LED_GPIOInterface();
		gpiooutput = (gpioinput & (~0x10)); // turn led off
		Write_LED_GPIOInterface(gpiooutput);
		nextStateToDo = LED5_IS_OFF;
		END_STATE

	}
	currentState_LED5 = nextStateToDo;
}




void Reset_Flash_LED6_StateMachine(void)
{
	unsigned char x = Read_LED_GPIOInterface();
		 x &=  ~ (0x20);
		 Write_LED_GPIOInterface(x);
}
#endif
