/*******************************************************************************
  System Initialization File

  File Name:
    initialization.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "configuration.h"
#include "definitions.h"
#include "device.h"



// ****************************************************************************
// ****************************************************************************
// Section: Configuration Bits
// ****************************************************************************
// ****************************************************************************

/*** DEVCFG0 ***/
#pragma config DEBUG =      OFF
#pragma config JTAGEN =     OFF
#pragma config ICESEL =     ICS_PGx2
#pragma config PWP =        OFF
#pragma config BWP =        OFF
#pragma config CP =         OFF


/*** DEVCFG1 ***/
#pragma config FNOSC =      FRCPLL
#pragma config FPBDIV =     DIV_2
#pragma config FSOSCEN =    OFF
#pragma config IESO =       ON
#pragma config POSCMOD =    OFF
#pragma config OSCIOFNC =   OFF
#pragma config FCKSM =      CSDCMD
#pragma config WDTPS =      PS1048576
#pragma config FWDTEN =     OFF
#pragma config WINDIS =     OFF
#pragma config FWDTWINSZ =  WINSZ_25


/*** DEVCFG2 ***/
#pragma config FPLLIDIV =   DIV_2
#pragma config FPLLMUL =    MUL_24
#pragma config FPLLODIV =   DIV_1
#pragma config UPLLEN =     OFF
#pragma config UPLLIDIV =   DIV_2

/*** DEVCFG3 ***/
#pragma config FSRSSEL =    PRIORITY_7
#pragma config FVBUSONIO =  ON
#pragma config USERID =     0xffff
#pragma config PMDL1WAY =   ON
#pragma config IOL1WAY =    ON
#pragma config FUSBIDIO =   ON




// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="DRV_SPI Instance 0 Initialization Data">

/* SPI Client Objects Pool */
static DRV_SPI_CLIENT_OBJ drvSPI0ClientObjPool[DRV_SPI_CLIENTS_NUMBER_IDX0];

/* SPI Transfer Objects Pool */
static DRV_SPI_TRANSFER_OBJ drvSPI0TransferObjPool[DRV_SPI_QUEUE_SIZE_IDX0];

/* SPI PLIB Interface Initialization */
const DRV_SPI_PLIB_INTERFACE drvSPI0PlibAPI = {

    /* SPI PLIB Setup */
    .setup = (DRV_SPI_PLIB_SETUP)SPI1_TransferSetup,

    /* SPI PLIB WriteRead function */
    .writeRead = (DRV_SPI_PLIB_WRITE_READ)SPI1_WriteRead,

    /* SPI PLIB Transfer Status function */
    .isTransmitterBusy = (DRV_SPI_PLIB_TRANSMITTER_IS_BUSY)SPI1_IsTransmitterBusy,

    /* SPI PLIB Callback Register */
    .callbackRegister = (DRV_SPI_PLIB_CALLBACK_REGISTER)SPI1_CallbackRegister,
};

const uint32_t drvSPI0remapDataBits[]= { 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000400, 0x00000800 };
const uint32_t drvSPI0remapClockPolarity[] = { 0x00000000, 0x00000040 };
const uint32_t drvSPI0remapClockPhase[] = { 0x00000000, 0x00000100 };

const DRV_SPI_INTERRUPT_SOURCES drvSPI0InterruptSources =
{
    /* Peripheral has more than one interrupt vectors */
    .isSingleIntSrc                        = false,

    /* Peripheral interrupt lines */
    .intSources.multi.spiTxReadyInt      = -1,
    .intSources.multi.spiTxCompleteInt   = _SPI1_TX_IRQ,
    .intSources.multi.spiRxInt           = _SPI1_RX_IRQ,
};

/* SPI Driver Initialization Data */
const DRV_SPI_INIT drvSPI0InitData =
{
    /* SPI PLIB API */
    .spiPlib = &drvSPI0PlibAPI,

    .remapDataBits = drvSPI0remapDataBits,

    .remapClockPolarity = drvSPI0remapClockPolarity,

    .remapClockPhase = drvSPI0remapClockPhase,

    /* SPI Number of clients */
    .numClients = DRV_SPI_CLIENTS_NUMBER_IDX0,

    /* SPI Client Objects Pool */
    .clientObjPool = (uintptr_t)&drvSPI0ClientObjPool[0],


    /* SPI Queue Size */
    .transferObjPoolSize = DRV_SPI_QUEUE_SIZE_IDX0,

    /* SPI Transfer Objects Pool */
    .transferObjPool = (uintptr_t)&drvSPI0TransferObjPool[0],

    /* SPI interrupt sources (SPI peripheral and DMA) */
    .interruptSources = &drvSPI0InterruptSources,
};

// </editor-fold>


// *****************************************************************************
// *****************************************************************************
// Section: System Data
// *****************************************************************************
// *****************************************************************************
/* Structure to hold the object handles for the modules in the system. */
SYSTEM_OBJECTS sysObj;

// *****************************************************************************
// *****************************************************************************
// Section: Library/Stack Initialization Data
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************

const SYS_DEBUG_INIT debugInit =
{
    .moduleInit = {0},
    .errorLevel = SYS_DEBUG_GLOBAL_ERROR_LEVEL,
    .consoleIndex = 0,
};


// <editor-fold defaultstate="collapsed" desc="SYS_TIME Initialization Data">

const SYS_TIME_PLIB_INTERFACE sysTimePlibAPI = {
    .timerCallbackSet = (SYS_TIME_PLIB_CALLBACK_REGISTER)TMR2_CallbackRegister,
    .timerStart = (SYS_TIME_PLIB_START)TMR2_Start,
    .timerStop = (SYS_TIME_PLIB_STOP)TMR2_Stop ,
    .timerFrequencyGet = (SYS_TIME_PLIB_FREQUENCY_GET)TMR2_FrequencyGet,
    .timerPeriodSet = (SYS_TIME_PLIB_PERIOD_SET)TMR2_PeriodSet,
};

const SYS_TIME_INIT sysTimeInitData =
{
    .timePlib = &sysTimePlibAPI,
    .hwTimerIntNum = 9,
};

// </editor-fold>
// <editor-fold defaultstate="collapsed" desc="SYS_CONSOLE Instance 0 Initialization Data">


/* Declared in console device implementation (sys_console_uart.c) */
extern const SYS_CONSOLE_DEV_DESC sysConsoleUARTDevDesc;

const SYS_CONSOLE_UART_PLIB_INTERFACE sysConsole0UARTPlibAPI =
{
    .read = (SYS_CONSOLE_UART_PLIB_READ)UART2_Read,
	.readCountGet = (SYS_CONSOLE_UART_PLIB_READ_COUNT_GET)UART2_ReadCountGet,
	.readFreeBufferCountGet = (SYS_CONSOLE_UART_PLIB_READ_FREE_BUFFFER_COUNT_GET)UART2_ReadFreeBufferCountGet,
    .write = (SYS_CONSOLE_UART_PLIB_WRITE)UART2_Write,
	.writeCountGet = (SYS_CONSOLE_UART_PLIB_WRITE_COUNT_GET)UART2_WriteCountGet,
	.writeFreeBufferCountGet = (SYS_CONSOLE_UART_PLIB_WRITE_FREE_BUFFER_COUNT_GET)UART2_WriteFreeBufferCountGet,
};

const SYS_CONSOLE_UART_INIT_DATA sysConsole0UARTInitData =
{
    .uartPLIB = &sysConsole0UARTPlibAPI,    
};

const SYS_CONSOLE_INIT sysConsole0Init =
{
    .deviceInitData = (const void*)&sysConsole0UARTInitData,
    .consDevDesc = &sysConsoleUARTDevDesc,
    .deviceIndex = 0,
};



// </editor-fold>




// *****************************************************************************
// *****************************************************************************
// Section: Local initialization functions
// *****************************************************************************
// *****************************************************************************



/*******************************************************************************
  Function:
    void SYS_Initialize ( void *data )

  Summary:
    Initializes the board, services, drivers, application and other modules.

  Remarks:
 */

void SYS_Initialize ( void* data )
{

    /* Start out with interrupts disabled before configuring any modules */
    __builtin_disable_interrupts();

  
    CLK_Initialize();

    /* Configure KSEG0 as cacheable memory. This is needed for Prefetch Buffer */
    __builtin_mtc0(16, 0,(__builtin_mfc0(16, 0) | 0x3));

    /* Configure Flash Wait States and Prefetch */
    CHECONbits.PFMWS = 2;
    CHECONbits.PREFEN = 3;

    /* Set the SRAM wait states to zero */
    BMXCONbits.BMXWSDRM = 0;




	GPIO_Initialize();

	BSP_Initialize();
	UART2_Initialize();

    TMR2_Initialize();

	SPI1_Initialize();


    /* Initialize SPI0 Driver Instance */
    sysObj.drvSPI0 = DRV_SPI_Initialize(DRV_SPI_INDEX_0, (SYS_MODULE_INIT *)&drvSPI0InitData);

    sysObj.sysDebug = SYS_DEBUG_Initialize(SYS_DEBUG_INDEX_0, (SYS_MODULE_INIT*)&debugInit);


    sysObj.sysTime = SYS_TIME_Initialize(SYS_TIME_INDEX_0, (SYS_MODULE_INIT *)&sysTimeInitData);
    sysObj.sysConsole0 = SYS_CONSOLE_Initialize(SYS_CONSOLE_INDEX_0, (SYS_MODULE_INIT *)&sysConsole0Init);

    // Added
    sysObj.drvWifiWinc = WDRV_WINC_Initialize(0, NULL);


    APP_Initialize();


    EVIC_Initialize();

	/* Enable global interrupts */
    __builtin_enable_interrupts();


}


/*******************************************************************************
 End of File
*/
