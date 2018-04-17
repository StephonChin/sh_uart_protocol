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

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    uint8_t * const buffer;
    int head;
    int tail;
    const int maxLen;
} ringBuf_t;

#define RINGBUF_DEF(x,y) do{         \
    uint8_t x##_dataSpace[y];     \
    ringBuf_t x = {               \
        .buffer = x##_dataSpace,      \
        .head = 0,                \
        .tail = 0,                \
        .maxLen = y               \
    } }while(0)
#define RINGBUF_DEF_RESET(p)  p->head = p->tail
int ringBufPush(ringcBuf_t *c, uint8_t data);
int ringBufPop(ringBuf_t *c, uint8_t *data);
int ringBuffer_len(ringBuf_t *p);
int ringBuffer_get(ringBuf_t *p, uint8_t *data,int len);