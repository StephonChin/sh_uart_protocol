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

#define UART_VERSION	0x55

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

#define UART_VERSION	0x55

// 指令类型
typedef enum UART_CMD_T{
    // 不加密命令
    CMD_NONE                = 0x00,   // 空类型
	CMD_SOCKET_ON			= 0x10,   //控制开关
	CMD_SOKET_OFF			= 0x11,	
    CMD_COLOR_SET			= 0x20,	// 控制发送串口
	
	CMD_MAX
}UART_Cmd_T;
    
	
typedef struct{
    u8 version;          // 验证数,表示协议和协议版本
    u8 crc8;            // 预留，payload 部分的 crc 校验，
    u16 cmd;            // 命令类型 
    u16 idx;			// 序号, 预留给 sensor 使用
	u16 len;            // 数据长度
    char payload[0];    // 数据
} UART_PACKET;
typedef struct{
	u8 no;		  // 几号灯
	u8 intensity; // 光强度
}UART_Light_T;

#ifdef __cplusplus
}
#endif

#endif _protocol_uart_h_
