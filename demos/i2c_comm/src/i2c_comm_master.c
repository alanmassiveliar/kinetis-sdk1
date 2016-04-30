/*
 * Copyright (c) 2013 - 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "board.h"
#include "fsl_i2c_master_driver.h"
#include "fsl_device_registers.h"
#include "fsl_port_hal.h"
#include "fsl_debug_console.h"
#include "fsl_clock_manager.h"
#include "fsl_gpio_driver.h"
#include "fsl_uart_hal.h"
#include <string.h>
#include <math.h>
#include <stdio.h>

static void LED_toggle_master(void)
{
    GPIO_DRV_TogglePinOutput(kGpioLED1);
}

enum _subaddress_index_e
{
    Subaddress_Index_0 = 0x00,
    Subaddress_Index_1 = 0x01,
    Subaddress_Index_2 = 0x02,
    Subaddress_Index_3 = 0x03,
    Subaddress_Index_4 = 0x04,
    Subaddress_Index_5 = 0x05,
    Subaddress_Index_6 = 0x06,
    Subaddress_Index_7 = 0x07,
    Invalid_Subaddress_Index,
    Max_Subaddress_Index
};

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
void main(void)
{
    // status_t err;
    uint8_t i;
    uint8_t index, indexChar, value;
    uint8_t cmdBuff[1] = {0xFF};
    uint8_t sendBuff[1] = {0xFF};       //save data sent to i2c slave
    uint8_t receiveBuff[1] = {0xFF};    //save data received from i2c slave
    
    i2c_master_state_t master;
    i2c_status_t returnValue;

    i2c_device_t slave =
    {
        .address = 0x3A,
        .baudRate_kbps = 100
    };

    hardware_init();
    
    dbg_uart_init();

    OSA_Init();

    GPIO_DRV_Init(0, ledPins);

    // Init I2C module
    I2C_DRV_MasterInit(BOARD_I2C_COMM_INSTANCE, &master);

    printf("\r\n====== I2C Master ======\r\n\r\n");
    
    OSA_TimeDelay(500);
    LED_toggle_master();
    OSA_TimeDelay(500);
    LED_toggle_master();
    OSA_TimeDelay(500);
    LED_toggle_master();
    OSA_TimeDelay(500);
    LED_toggle_master();

    while (1)
    {
        printf("\r\nI2C Master reads values from I2C Slave sub address:\r\n");
        printf("\r\n------------------------------------");
        printf("\r\nSlave Sub Address   |    Character         ");
        printf("\r\n------------------------------------");
        for (i=Subaddress_Index_0; i<Invalid_Subaddress_Index; i++)
        {
            cmdBuff[0] = i;
            returnValue = I2C_DRV_MasterReceiveDataBlocking(
                                                            BOARD_I2C_COMM_INSTANCE,
                                                            &slave,
                                                            cmdBuff,
                                                            1,
                                                            receiveBuff,
                                                            sizeof(receiveBuff),
                                                            500);
            if (returnValue == kStatus_I2C_Success)
            {
                printf("\r\n[%d]                      %c", i, receiveBuff[0]);
            }
            else
            {
                printf("\r\nI2C communication failed, error code: %d", returnValue);
            }

        }
        printf("\r\n------------------------------------");
        printf("\r\n");

        printf("\r\nPlease input Slave sub address and the new character.");

        do
        {
            printf("\r\nSlave Sub Address: ");
            indexChar = getchar();
            putchar(indexChar);

            printf("\r\nInput New Character: ");
            value = getchar();
            putchar(value);

            printf("\n");

            index = (uint8_t)(indexChar - '0');

            if (index >= Invalid_Subaddress_Index)
            {
                printf("\r\nInvalid Sub Address.");
            }
        } while (index >= Invalid_Subaddress_Index);

        cmdBuff[0]  = index;
        sendBuff[0] = value;
        
        returnValue = I2C_DRV_MasterSendDataBlocking(
                                                    BOARD_I2C_COMM_INSTANCE,
                                                    &slave,
                                                    cmdBuff,
                                                    1,
                                                    sendBuff,
                                                    sizeof(sendBuff),
                                                    500);
        if (returnValue != kStatus_I2C_Success)
        {
            printf("\r\nI2C communication failed, error code: %d", returnValue);
        }

    }
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////

