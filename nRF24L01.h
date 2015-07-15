/*
*******************************************************************************
*	The MIT License (MIT)
*
*	Copyright (c) 2015 Pham Van Tuong 
*
*	Permission is hereby granted, free of charge, to any person obtaining a copy
*	of this software and associated documentation files (the "Software"), to deal
*	in the Software without restriction, including without limitation the rights
*	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*	copies of the Software, and to permit persons to whom the Software is
*	furnished to do so, subject to the following conditions:
*
*	The above copyright notice and this permission notice shall be included in
*	all copies or substantial portions of the Software.
*
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*	THE SOFTWARE.
*
*******************************************************************************
*/

/*
 *	Filename	:nRF24L01.h
 *	Created on	:Jul 4, 2015
 *  Author		:Pham Van Tuong
 *	Version		:1.A
 */

#ifndef NRF24L01_H_
#define NRF24L01_H_

/*
 * 	MEMORY MAP
 * 	Datasheet - p.53 to p.58
 */
enum {
	CONFIG,		//Configuration Register
	EN_AA,		//Enable ‘Auto Acknowledgment’ function
	EN_RXADDR,	//Enabled RX Addresses
	SETUP_AW,	//Setup of Address Widths
	SETUP_RETR,	//Setup of Automatic Retransmission
	RF_CH,		//RF channel
	RF_SETUP,	//RF settup Register
	STATUS,		//Status Register
	OBSERVE_TX,	//Transmit observe register
	CD,			//Carrier Detect
	RX_ADDR_P0,	//Receive address data pipe 0
	RX_ADDR_P1,
	RX_ADDR_P2,
	RX_ADDR_P3,
	RX_ADDR_P4,
	RX_ADDR_P5,
	TX_ADDR,	//Transmit address
	RX_PW_P0,	//RX payload in data pipe 0
	RX_PW_P1,
	RX_PW_P2,
	RX_PW_P3,
	RX_PW_P4,
	RX_PW_P5,
	FIFO_STATUS,//FIFO Status Register
	DYNPD = 0x1C,
	FEATURE = 0x1D
} REG_MAP;

/*  */
/******************************************************************************
 * 							Bit Mnemonics
 *
 *****************************************************************************/
/*
 * Configuration Register
 */
enum {
	PRIM_RX,		//0
	PWR_UP,
	CRCO,
	EN_CRC,
	MASK_MAX_RT,
	MASK_TX_DS,
	MASK_RX_DR		//6
} CONFIG_BIT;

enum {
	ENAA_P0,
	ENAA_P1,
	ENAA_P2,
	ENAA_P3,
	ENAA_P4,
	ENAA_P5
} EN_AA_BIT;

enum {
	ERX_P0,
	ERX_P1,
	ERX_P2,
	ERX_P3,
	ERX_P4,
	ERX_P5
} EN_RXADDR_BIT;

/* setup of address width */
#define AW          0 /* 2 bits */

/* setup of auto re-transmission */
#define ARD         4 /* 4 bits */
#define ARC         0 /* 4 bits */

/* RF setup register */
#define PLL_LOCK    4
#define RF_DR       3
#define RF_PWR      1 /* 2 bits */

/* general status register */
#define RX_DR       6
#define TX_DS       5
#define MAX_RT      4
#define RX_P_NO     1 /* 3 bits */
#define TX_FULL     0

/* transmit observe register */
#define PLOS_CNT    4 /* 4 bits */
#define ARC_CNT     0 /* 4 bits */

/* fifo status */
#define TX_REUSE    6
#define FIFO_FULL   5
#define TX_EMPTY    4
#define RX_FULL     1
#define RX_EMPTY    0

/* dynamic length */
#define DPL_P0      0
#define DPL_P1      1
#define DPL_P2      2
#define DPL_P3      3
#define DPL_P4      4
#define DPL_P5      5


/* Instruction Mnemonics */
#define R_REGISTER    0x00 /* last 4 bits will indicate reg. address */
#define W_REGISTER    0x20 /* last 4 bits will indicate reg. address */
#define REGISTER_MASK 0x1F
#define R_RX_PAYLOAD  0x61
#define W_TX_PAYLOAD  0xA0
#define FLUSH_TX      0xE1
#define FLUSH_RX      0xE2
#define REUSE_TX_PL   0xE3
#define ACTIVATE      0x50
#define R_RX_PL_WID   0x60
#define NOP           0xFF


#endif /* NRF24L01_H_ */
