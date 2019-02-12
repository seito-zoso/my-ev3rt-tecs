#ifndef TSIOPORTEV3UART_H
#define TSIOPORTEV3UART_H

#include <t_stddef.h>

/*
 * UARTの割り込みサービスハンドラ．
 * uart_driからの内部結合．
 */
void uart_sio_isr(intptr_t unused);

#endif
