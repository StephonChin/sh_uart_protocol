/*******************************************************************************

    This file is part of the up2p.
    Copyright wilddog.com
    All right reserved.

    File:    protocol_uart.c

    No description

    TIME LIST:
    CREATE  skyli    

*******************************************************************************/

#include "protocol_uart.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化 uart 缓存 
RINGBUF_DEF(uart_buff, 32);  
/* todo
* 当判断接收到 大于 1 包数据时调用该函数对缓存中的数据进行解析。
* 从队列中取出数据，并解析
**/
int uart_parse(){
	unsigned char c;
	UART_PACKET *p_rec = NULL;

	while(1){
		int len = ringBuffer_len(uart_buff);
		if(len < sizeof(UART_PACKET)){
			// no match
			// todo 清空 ring buffer.
			RINGBUF_DEF_RESET(uart_buff);
			return -1;
		}
		ringBufPop(uart_buff, &c);
		if(c== UART_VERSION){
			// no match dump the package
			break;
		}
	}
	// todo  获整个包。
	return uart_cmd_handl(p_pack);
}
/* todo
* 底层接收,可以放置到 mcu 的 uart 中断实现中.
*/
int _uart_recv(u8 *p_rec,u16 len){
	int i;
	//todo put packet to queue
	for(i =0;i< len; i++){
		ringBufPush(uart_buff,p_rec[i]);

	}
	
}

int uart_pack_alloc(u8 **pp_packet,u16 cmd,const u8 *p_data,const u16 len){

	
	UART_PACKET *p_packet = malloc(sizeof(UART_PACKET)+len);
	if(!p_packet)
		return -1;
	//protocol packet
	p_packet->version = UART_VERSION;
	p_packet->cmd = cmd;
	p_packet->len = len;

	
	if(!p_data | len ){
		memcpy(p_packet->payload,p_data,len);	
	}
	
	*pp_packet = p_packet;

	
	return (sizeof(UART_PACKET)+len);
}

// 响应串口数据
int uart_cmd_handl(u8 *p_rec){
	UART_PACKET *p_pack = (UART_PACKET*)p_rec;

	switch(p_pack->cmd){
		case CMD_SOCKET_ON:
			// function to handle socket on
			break;
		case CMD_SOKET_OFF:
			// func_off_handle
			break;
		case CMD_LIGHT_UP:
		{
			UART_Light_T *p_light = (UART_Light_T*)p_pack->payload;
			printf("change %d light to %d \n",p_light->no,p_light->intensity);
		}
		default: 
			break;
	}
	return 0;
}

void main(void)
{
	UART_Light_T test_light;
	u8 *p_send = NULL;
	test_light.no = 10;
	test_light.intensity = 99;
	
	int slen = uart_pack_alloc(&p_send,CMD_SOCKET_ON,&test_light,sizeof(UART_Light_T));

	if(!slen | !p_send )
		return -1;

	_uart_recv(p_send,slen);

	
	free(p_send);
	p_send = NULL;
	

}
