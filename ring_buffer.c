/*******************************************************************************

    This file is part of the up2p.
    Copyright evalogik.com
    All right reserved.

    File:    ring_buffer.c

    No description

    TIME LIST:
    CREATE  skyli    
	data: 20180417

*******************************************************************************/

#include "ring_buffer.h"

#define DBG  printf

int ringBuffer_len(ringBuf_t *p){
	return (p->tail > p->head) ? (p->maxLen - p->tail): (p->head - p->tail)
}
int ringBufPush(ringBuf_t *c, uint8_t data)
{
    // next is where head will point to after this write.
    int next = c->head + 1;
    if (next >= c->maxLen)
        next = 0;

    if (next == c->tail) // check if circular buffer is full
        return -1;       // and return with an error.

    c->buffer[c->head] = data; // Load data and then move
    c->head = next;            // head to next data offset.
    return 0;  // return success to indicate successful push.
}

int ringBufPop(ringBuf_t *c, uint8_t *data)
{
    // if the head isn't ahead of the tail, we don't have any characters
    if (c->head == c->tail) // check if circular buffer is empty
        return -1;          // and return with an error

    // next is where tail will point to after this read.
    int next = c->tail + 1;
    if(next >= c->maxLen)
        next = 0;

    *data = c->buffer[c->tail]; // Read data and then move
    c->tail = next;             // tail to next data offset.
    return 0;  // return success to indicate successful push.
}
int ringBuffer_get(ringBuf_t *p, uint8_t *data,int len){
	if( len > ringBuffer_len(p)){
		// request too mach .
		return -1;
	}
	int i;
	for(i=0;i<len; i++){
		ringBufPop(p,data[i]);
	}
	return (i);
}
// test code 
RINGBUF_DEF(myDatBuf, 32);

void main(void)
{
    uint8_t outData, inData = 0x55;

    if (ringBufPush(&myDatBuf, inData)) {
        DBG("Out of space in CB");
        return;
    }

    if (ringBufPop(&myDatBuf, &outData)) {
        DBG("CB is empty");
        return;
    }

    // here outData = inData = 0x55;
    return data;
}
