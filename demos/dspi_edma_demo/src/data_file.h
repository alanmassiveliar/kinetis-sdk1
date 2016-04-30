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

/*
 *  data_file.h
 * 
 *
 * @brief  This file contains the data array to be transfered from DSPI master
 *         to DSPI slave.
 *
 */

#ifndef __DATA_FILE_H__
#define __DATA_FILE_H__
/*******************************************************************************
 * Standard C Included Files
 ******************************************************************************/
#include <stdint.h>
/*******************************************************************************
 * Standard C Included Files
 ******************************************************************************/

const uint32_t g_dataBuffer[] = 
{
    0x0123, 0x4567, 0x89AB, 0xCDEF, 0xFEDC, 0xBA98, 0x7654, 0x3210,
    0x0123, 0x4567, 0x89AB, 0xCDEF, 0xFEDC, 0xBA98, 0x7654, 0x3210,
    0x0123, 0x4567, 0x89AB, 0xCDEF, 0xFEDC, 0xBA98, 0x7654, 0x3210,
    0x0123, 0x4567, 0x89AB, 0xCDEF, 0xFEDC, 0xBA98, 0x7654, 0x3210,
    0x0123, 0x4567, 0x89AB, 0xCDEF, 0xFEDC, 0xBA98, 0x7654, 0x3210,
    0x0123, 0x4567, 0x89AB, 0xCDEF, 0xFEDC, 0xBA98, 0x7654, 0x3210,
    0x0123, 0x4567, 0x89AB, 0xCDEF, 0xFEDC, 0xBA98, 0x7654, 0x3210,
    0x0123, 0x4567, 0x89AB, 0xCDEF, 0xFEDC, 0xBA98, 0x7654, 0x3210
};

const uint32_t g_expectedReturn[] = 
{
    0x0100, 0x0302, 0x0504, 0x0706,
    0x0908, 0x0B0A, 0x0D0C, 0x0F0E,
    0x1110, 0x1312, 0x1514, 0x1716,
    0x1918, 0x1B1A, 0x1D1C, 0x1F1E,
    0x2120, 0x2322, 0x2524, 0x2726,
    0x2928, 0x2B2A, 0x2D2C, 0x2F2E,
    0x3130, 0x3332, 0x3534, 0x3736,
    0x3938, 0x3B3A, 0x3D3C, 0x3F3E,
    0x4140, 0x4342, 0x4544, 0x4746,
    0x4948, 0x4B4A, 0x4D4C, 0x4F4E,
    0x5150, 0x5352, 0x5554, 0x5756,
    0x5958, 0x5B5A, 0x5D5C, 0x5F5E,
    0x6160, 0x6362, 0x6564, 0x6766,
    0x6968, 0x6B6A, 0x6D6C, 0x6F6E,
    0x7170, 0x7372, 0x7574, 0x7776,
    0x7978, 0x7B7A, 0x7D7C, 0x7F7E
};

#endif /* __DATA_FILE_H__ */

/******************************************************************************
 * EOF
 ******************************************************************************/
