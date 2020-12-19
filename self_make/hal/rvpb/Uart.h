#ifndef _HAL_RVPB_UART_H_
#define _HAL_RVPB_UART_H_

#include "stdint.h"

typedef union UARTDR_t
{
	uint32_t all;
	struct {
		uint32_t DATA:8;
		uint32_t FE:1;
		uint32_t PE:1;
		uint32_t BE:1;
		uint32_t OE:1;
		uint32_t RESERVED:20;
	} bits;
} UARTDR_t;

typedef union UARTRSR_t
{
	uint32_t all;
	struct {
		uint32_t FE:1;
		uint32_t PE:1;
		uint32_t BE:1;
		uint32_t OE:1;
		uint32_t RESERVED:28;
	} bits;
} UARTRSR_t;

typedef union UARTFR_t
{
	uint32_t all;
	struct {
		uint32_t CTS:1;
		uint32_t DSR:1;
		uint32_t DCD:1;
		uint32_t BUSY:1;
		uint32_t RXFE:1;
		uint32_t TXFF:1;
		uint32_t RXFF:1;
		uint32_t TXFE:1;
		uint32_t RI:1;
		uint32_t RESERVED:23;
	} bits;
} UARTFR_t;

typedef union UARTILPR_t
{
	uint32_t all;
	struct {
		uint32_t ILPDVSR:8;
		uint32_t RESERVED:24;
	} bits;
} UARTILPR_t;

typedef union UARTIBRD_t
{
	uint32_t all;
	struct {
		uint32_t BAUD:16;
		uint32_t RESERVED:16;
	} bits;
} UARTIBRD_t;

typedef union UARTFBRD_t
{
	uint32_t all;
	struct {
		uint32_t BAUD:6;
		uint32_t RESERVED:26;
	} bits;
} UARTFBRD_t;

typedef union UARTLCR_H_t
{
	uint32_t all;
	struct {
		uint32_t BRK:1;
		uint32_t PEN:1;
		uint32_t EPS:1;
		uint32_t STP2:1;
		uint32_t FEN:1;
		uint32_t WLEN:2;
		uint32_t SPS:1;
		uint32_t RESERVED:24;
	} bits;
} UARTLCR_H_t;

typedef union UARTCR_t
{
	uint32_t all;
	struct {
		uint32_t UARTEN:1;
		uint32_t SIREN:1;
		uint32_t SIRLP:1;
		uint32_t RESERVED0:4;
		uint32_t LBE:1;
		uint32_t TXE:1;
		uint32_t RXE:1;
		uint32_t DTR:1;
		uint32_t RTS:1;
		uint32_t OUT1:1;
		uint32_t OUT2:1;
		uint32_t RTSEN:1;
		uint32_t CTSEN:1;
		uint32_t RESERVED2:16;
	} bits;
} UARTCR_t;

typedef union UARTIFLS_t
{
	uint32_t all;
	struct {
		uint32_t TXIFLSEL:3;
		uint32_t RXIFLSEL:3;
		uint32_t RESERVED:26;
	} bits;
} UARTIFLS_t;

typedef union UARTIMSC_t
{
	uint32_t all;
	struct {
		uint32_t RIMIM:1;
		uint32_t CTSMIM:1;
		uint32_t DCDMIM:1;
		uint32_t DSRMIM:1;
		uint32_t RMIX:1;
		uint32_t TMIM:1;
		uint32_t RTIM:1;
		uint32_t FEIM:1;
		uint32_t PEIM:1;
		uint32_t BEIM:1;
		uint32_t OEIM:1;
		uint32_t RESERVED:21;
	} bits;
} UARTIMSC_t;

typedef union UARTRIS_t
{
	uint32_t all;
	struct {
		uint32_t RIRMIS:1;
		uint32_t CTSRMIS:1;
		uint32_t DCDRMIS:1;
		uint32_t DSRRMIS:1;
		uint32_t RXRIS:1;
		uint32_t TXRIS:1;
		uint32_t RTRIS:1;
		uint32_t FERIS:1;
		uint32_t PERIS:1;
		uint32_t BERIS:1;
		uint32_t OERIS:1;
		uint32_t RESERVED:21;
	} bits;
} UARTRIS_t;

typedef union UARTMIS_t
{
	uint32_t all;
	struct {
		uint32_t RIMMIS:1;
		uint32_t CTSMMIS:1;
		uint32_t DCDMMIS:1;
		uint32_t DSRMMIS:1;
		uint32_t RXMIS:1;
		uint32_t TXMIS:1;
		uint32_t RTMIS:1;
		uint32_t FEMIS:1;
		uint32_t PEMIS:1;
		uint32_t BEMIS:1;
		uint32_t OEMIS:1;
		uint32_t RESERVED:21;
	} bits;
} UARTMIS_t;

typedef union UARTICR_t
{
	uint32_t all;
	struct {
		uint32_t RIMIC:1;
		uint32_t CTSMIC:1; 
		uint32_t DCDMIC:1;
		uint32_t DSRMIC:1;
		uint32_t RXIC:1;
		uint32_t TXIC:1;
		uint32_t RTIC:1;
		uint32_t FEIC:1;
		uint32_t PEIC:1;
		uint32_t BEIF:1;
		uint32_t OEIC:1;
		uint32_t RESERVED:21;
	} bits;
} UARTICR_t;

typedef union UARTDMACR_t
{
	uint32_t all;
	struct {
		uint32_t RXDMAE:1;
		uint32_t TXDMAE:1;
		uint32_t DMAONERR:1;
		uint32_t RESERVED:29;
	} bits;
} UARTDMACR_t;

typedef struct PL011_t
{
	UARTDR_t	uartdr;
	UARTRSR_t	uartrsr;
	uint32_t	reserved0[4];
	UARTFR_t	uartfr;
	uint32_t	reserved1;
	UARTILPR_t	uartilpr;
	UARTIBRD_t	uartibrd;
	UARTFBRD_t	uartfbrd;
	UARTLCR_H_t	uartlcr;
	UARTCR_t	uartcr;
	UARTIFLS_t	uartifls;
	UARTIMSC_t	uartimsc;
	UARTRIS_t	uartris;
	UARTMIS_t	uartmis;
	UARTICR_t	uarticr;
	UARTDMACR_t	uartdmacr;
} PL011_t;

#define UART0_BASE_ADDR		0x10009000
#define UART1_BASE_ADDR		0x1000A000
#define UART2_BASE_ADDR		0x1000B000
#define UART3_BASE_ADDR		0x1000C000

#define UART0_INTERRUPT		44
#define UART1_INTERRUPT		45
#define UART2_INTERRUPT		46
#define UART3_INTERRUPT		47

#endif
