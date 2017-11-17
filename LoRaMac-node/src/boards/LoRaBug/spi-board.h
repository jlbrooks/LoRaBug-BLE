/**
 * This is the HAL implementation of SPI.
 * @author Craig Hesling
 * @date Jan 7, 2017
 */

#ifndef __SPI_MCU_H__
#define __SPI_MCU_H__

#include <ti/drivers/SPI.h>
#include <ti/sysbios/gates/GateMutexPri.h>
#include "gpio.h"

/*!
 * SPI driver structure definition
 */
struct Spi_s
{
    SPI_Handle Spi;
    SPI_Params Params;
    GateMutexPri_Struct gmutex;
    Gpio_t Nss;
};

#endif  // __SPI_MCU_H__
