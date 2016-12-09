#include "Lab4.h"
#include "blackfin.h"
#include <stdio.h>
#include <string.h>
#include <uTTCOSg2016/uTTCOSg.h>
#include <stdio.h>

#define BEGIN_STATE case
#define END_STATE break;
volatile unsigned int threadID = 0;
extern bool commandStringBeingSent=0;
extern bool commandStringToSend=0;
extern bool commandStringIsInstruction=0;
extern bool waiting  =0;
//extern char SPI_MessageBuffer[256]= [];
char message[100] = " HELOOOO";
unsigned long int initval[4] = {0x0f, 0x1, 0x2, 0x7};
int initcounter = 0;
int counter = 0;


void init_SPI(void){
	*pSPI_CTL = 0x0400; // trun off spi interface
	ssync();
	//*pSPI_STAT = *pSPI_STAT|0x56;
	ssync();
	*pSPI_BAUD = 0x6000;
	ssync();
	*pSPI_FLG = 0x20;
	ssync();
	//*pSPI_TDBR = 0x0000;
	ssync();
	*pSPI_CTL = 0x5101;
	ssync();

	//threadID = uTTCOSg_AddThread(inint_LCD, ONE_TICK, EXECUTE_EVERY_SECOND);
}

enum initLCD {highmessagee, lowmessagee, doshighmessagee};
static initLCD currentState_LCDd = highmessagee;

void inint_LCD(){

	if(initcounter < 4){
		initLCD nextStateToDoo = currentState_LCDd;
		unsigned char gpioinput;
		unsigned char gpiooutput;
		switch (currentState_LCDd){

		BEGIN_STATE highmessagee:
		if (!waiting) {
			*pSPI_TDBR = (initval[initcounter] | 0x100);
			waiting = 1;
		}
		if((*pSPI_STAT & 1) == 1){
			waiting = 0;
			nextStateToDoo = lowmessagee;
		}
		END_STATE

		BEGIN_STATE lowmessagee:
		if (!waiting) {
			*pSPI_TDBR = initval[initcounter] ;
			waiting = 1;
		}
		if((*pSPI_STAT & 1) == 1){
			waiting = 0;
			nextStateToDoo = doshighmessagee;
		}
		END_STATE

		BEGIN_STATE doshighmessagee:
		if (!waiting) {
			*pSPI_TDBR = (initval[initcounter] | 0x100);
			waiting = 1;
		}
		if((*pSPI_STAT & 1) == 1){
			waiting = 0;
			nextStateToDoo = highmessagee;
			counter++;
			if(counter == 4 ){
				waiting = 1;
				uTTCOSg_AddThread(print_LCD, ONE_TICK, EXECUTE_EVERY_SECOND);
			}
		}
		END_STATE

		}
		currentState_LCDd = nextStateToDoo;
	}
}



void init_LCD(void){




	*pSPI_TDBR = 0x10f;
	ssync();
	//while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
	for (int var = 0; var < 0xaaaaa; ++var) {}
	*pSPI_TDBR = 0x00f;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
	//while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
	*pSPI_TDBR = 0x10f;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
//	while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
	*pSPI_TDBR = 0x101;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
//	while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
	*pSPI_TDBR = 0x001;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
//	while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
	*pSPI_TDBR = 0x101;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
//	while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}

	*pSPI_TDBR = 0x107;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
//	while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
	*pSPI_TDBR = 0x007;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
//	while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
	*pSPI_TDBR = 0x107;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
//	while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
/*
	*pSPI_TDBR = 0x11c;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
	//while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
	*pSPI_TDBR = 0x01c;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
	//while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
	*pSPI_TDBR = 0x11c;
	ssync();
	for (int var = 0; var < 0xaaaaa; ++var) {}
	//while(1){if(*pSPI_STAT&0x1 == 0x1){break;}}
*/
//	uTTCOSg_AddThread(print_LCD, ONE_TICK, EXECUTE_EVERY_SECOND);
}

enum printLCD {highmessage, lowmessage, doshighmessage};
static printLCD currentState_LCD = highmessage;

void print_LCD(){


	printLCD nextStateToDo = currentState_LCD;
	unsigned char gpioinput;
	unsigned char gpiooutput;
	switch (currentState_LCD){

	BEGIN_STATE highmessage:
	//if(initcounter == 4){uTTCOSg_DeleteThread(threadID);initcounter++;}
	commandStringBeingSent = true;
	if (!waiting) {
		*pSPI_TDBR = (message[counter] | 0x500);
		waiting = 1;
	}
	if((*pSPI_STAT & 1) == 1){
		waiting = 0;
		nextStateToDo = lowmessage;
	}
	END_STATE

	BEGIN_STATE lowmessage:
	if (!waiting) {
		*pSPI_TDBR = ((~0x100) & (0x500 |message[counter] ));
		waiting = 1;
	}
	if((*pSPI_STAT & 1) == 1){
		waiting = 0;
		nextStateToDo = doshighmessage;
	}
	END_STATE

	BEGIN_STATE doshighmessage:
	if (!waiting) {
		*pSPI_TDBR = (message[counter] | 0x500);
		waiting = 1;
	}
	if((*pSPI_STAT & 1) == 1){
		waiting = 0;
		nextStateToDo = highmessage;
		counter++;
		if(counter == strlen(message) ){
			counter = 0;
			commandStringToSend = false;
			commandStringBeingSent = false;
		}
	}
	END_STATE

	}
	currentState_LCD = nextStateToDo;

}




void SPI_Message(void){
	Flash_LED3();
	if( commandStringBeingSent == true){return;}
	if (commandStringToSend == true){return;}

	commandStringToSend = true;
	strcpy(message, " 1");
}


void SPI_Message2(void){
	Flash_LED2();
	if( commandStringBeingSent == true){return;}
	if (commandStringToSend == true){return;}

	commandStringToSend = true;
	strcpy(message, " 2");
}




void SPI_Message3(void){
	Flash_LED1();
	if( commandStringBeingSent == true){return;}
	if (commandStringToSend == true){return;}

	commandStringToSend = true;
	strcpy(message, " 3");
}










