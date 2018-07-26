/*******************************************************************************

    This file is part of the up2p.
    Copyright showhome
    All right reserved.

    File:    protocol_uart.h

    No description

    TIME LIST:
    CREATE  skyli  

*******************************************************************************/
#ifndef _protocol_uart_h_
#define _protocol_uart_h_

#ifdef      __cplusplus
extern "C" {
#endif

#if __x86_64__ || __LP64__
#pragma message("In 64Bit machine \n")

typedef char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#else

#pragma message("In 32Bit machine \n")

// 基本类型
typedef char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef long s32;
typedef unsigned long u32;

#endif

#define UART_VERSION			0x10
#deifne	UART_BUFFER_MAX			20

// Command type for chritmas tree controlled by WIFI
typedef enum UART_CMD_T{
    CMD_NONE                = 0x00,   // void
    CMD_SOCKET_ON	    = 0x10,   // turn on
    CMD_SOKET_OFF	    = 0x11,   // turn off
    CMD_COLOR_SET	    = 0x20,   // control the serias ports
    CMD_MAX
}UART_Cmd_T;
    
// Command type for light strings controlled by WIFI via bluetooth	
typedef struct{
    u8 version;           // protocol version
    u8  crc8;             // crc checksum
    union{
      u8 buffer;
      struct{
	u8 ack      : 1;
	u8 ctrl     : 7;
      }info;
    }cmd;		  // command content            
    u8  idx;		  // reserved for sensor
    u8  len;              // data length
    u8  payload[UART_BUFFER_MAX];       // data contents
} UART_PACKET;

// Dimmer device
typedef struct{
	u8 no;		  	// 几号灯
	u8 intensity; 		// 光强度
}UART_Light_T;

#ifdef __cplusplus
}
#endif

#endif _protocol_uart_h_
