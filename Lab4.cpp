/*****************************************************************************
 * Lab4.cpp
 *****************************************************************************/
/*****************************************************************************
 * Lab2pls.cpp.
 *  *   *  Created on: Nov 20, 2016
 *      Author: Mahipaul Tak and Alex Minifie
 *****************************************************************************/

#include <sys/platform.h>
#include "adi_initialize.h"
#include "Lab4.h"
#include <GPIO2016/ADSP_GPIO_Interface.h>
#include <uTTCOSg2016/uTTCOSg.h>

int main()
{



	int numBackgroundThreads = 0;
	int numberYourThreads = 30;
	int maxNumberThreads = numBackgroundThreads + numberYourThreads;
	uTTCOSg_OS_Init(USE_AUDIO_INTERRUPT, 0, 44000);
	Init_LED_GPIOInterface();
	Init_Input_GPIOInterface();

    // initialize and set up the SPI and LCD before audio interrupt change so as to make sure
    // LCD has correct setting before starting message threads
	init_SPI();
	init_LCD();

	uTTCOSg_AddThread(Flash_Led6, NO_DELAY, EXECUTE_EVERY_SECOND);
	uTTCOSg_AddThread(SPI_Message, DELAY_ONE_SECOND/8, EXECUTE_EVERY_SECOND/8);
	uTTCOSg_AddThread(SPI_Message2, DELAY_ONE_SECOND/4, EXECUTE_EVERY_SECOND/9);
	uTTCOSg_AddThread(SPI_Message3, DELAY_ONE_SECOND/2, EXECUTE_EVERY_SECOND/10);
	uTTCOSg_AddThread(print_LCD, ONE_TICK, EXECUTE_EVERY_SECOND);


uTTCOSg_Start_Scheduler(maxNumberThreads);
    // starting schedular changes spi register and this resets to allow for proper SPI usage
init_SPI();




// Execution time of TT_COS_Dispatch( ) and TT_COS_Update( ) improved by specifiying maxNumberTasks
while (1) {

	// Wait, in low power mode, for an interrupt
	// The interrupt service routine calls TTCOS_Update( )
	uTTCOSg_GoToSleep( );

	// Run all the threads in the system according
	// to whether their delays have expired
	uTTCOSg_DispatchThreads( );
}



}
