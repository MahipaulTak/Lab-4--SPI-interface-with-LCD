/*****************************************************************************
 * Lab4.h
 *****************************************************************************/

#ifndef __LAB4_H__
#define __LAB4_H__

#include "Lab0_Library.h"
#include <string.h>


void init_SPI(void);

void init_LCD(void);

void print_LCD();

void inint_LCD();

void SPI_Message(void);

void SPI_Message2(void);

void SPI_Message3(void);
void SPI_Message4(void);
extern char message[100];
extern int counter ;

extern unsigned long int initval[4];
extern int initcounter;
extern volatile unsigned int threadID;


#endif /* __LAB4_H__ */
