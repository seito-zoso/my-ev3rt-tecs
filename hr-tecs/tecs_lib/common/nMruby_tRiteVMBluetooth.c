/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tRiteVMBluetooth_template.c => src/tRiteVMBluetooth.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * irepLib          uint8_t*         ATTR_irepLib    
 * irepAppSize      uint32_t         ATTR_irepAppSize
 * setptn           FLGPTN           ATTR_setptn     
 * mrb              mrb_state*       VAR_mrb         
 * context          mrbc_context*    VAR_context     
 * irepApp          uint8_t*         VAR_irepApp     
 *
 * 呼び口関数 #_TCPF_#
 * require port: signature:sKernel context:task
 *   ER             sleep( );
 *   ER             sleepTimeout( TMO timeout );
 *   ER             delay( RELTIM delayTime );
 *   ER             exitTask( );
 *   ER             getTaskId( ID* p_taskId );
 *   ER             rotateReadyQueue( PRI taskPriority );
 *   ER             getTime( SYSTIM* p_systemTime );
 *   ER             getMicroTime( SYSUTM* p_systemMicroTime );
 *   ER             lockCpu( );
 *   ER             unlockCpu( );
 *   ER             disableDispatch( );
 *   ER             enableDispatch( );
 *   ER             disableTaskException( );
 *   ER             enableTaskException( );
 *   ER             changeInterruptPriorityMask( PRI interruptPriority );
 *   ER             getInterruptPriorityMask( PRI* p_interruptPriority );
 *   ER             exitKernel( );
 *   bool_t         senseContext( );
 *   bool_t         senseLock( );
 *   bool_t         senseDispatch( );
 *   bool_t         senseDispatchPendingState( );
 *   bool_t         senseKernel( );
 * call port: cTask signature: sTask context:task
 *   ER             cTask_activate( );
 *   ER_UINT        cTask_cancelActivate( );
 *   ER             cTask_terminate( );
 *   ER             cTask_changePriority( PRI priority );
 *   ER             cTask_getPriority( PRI* p_priority );
 *   ER             cTask_refer( T_RTSK* pk_taskStatus );
 *   ER             cTask_wakeup( );
 *   ER_UINT        cTask_cancelWakeup( );
 *   ER             cTask_releaseWait( );
 *   ER             cTask_suspend( );
 *   ER             cTask_resume( );
 *   ER             cTask_raiseException( TEXPTN pattern );
 *   ER             cTask_referException( T_RTEX* pk_rtex );
 *   ER             cTask_startOverRunHandler( OVRTIM ovrtim );
 *   ER             cTask_stopOverRunHandler( );
 *   ER             cTask_referOverRunHandler( T_ROVR* pk_rovr );
 * call port: cReset signature: sReset context:task
 *   void           cReset_reset( );
 * call port: cCyclic signature: sCyclic context:task optional:true
 *   bool_t     is_cCyclic_joined()                     check if joined
 *   ER             cCyclic_start( );
 *   ER             cCyclic_stop( );
 *   ER             cCyclic_refer( T_RCYC* pk_cyclicHandlerStatus );
 * call port: cEventflag signature: sEventflag context:task optional:true
 *   bool_t     is_cEventflag_joined(int subscript)        check if joined
 *   ER             cEventflag_set( subscript, FLGPTN setPattern );
 *   ER             cEventflag_clear( subscript, FLGPTN clearPattern );
 *   ER             cEventflag_wait( subscript, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern );
 *   ER             cEventflag_waitPolling( subscript, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern );
 *   ER             cEventflag_waitTimeout( subscript, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern, TMO timeout );
 *   ER             cEventflag_initialize( subscript );
 *   ER             cEventflag_refer( subscript, T_RFLG* pk_eventflagStatus );
 *       subscript:  0...(NCP_cEventflag-1)
 * call port: cSemaphore signature: sSemaphore context:task optional:true
 *   bool_t     is_cSemaphore_joined()                     check if joined
 *   ER             cSemaphore_signal( );
 *   ER             cSemaphore_wait( );
 *   ER             cSemaphore_waitPolling( );
 *   ER             cSemaphore_waitTimeout( TMO timeout );
 *   ER             cSemaphore_initialize( );
 *   ER             cSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cInit signature: nMruby_sInitializeBridge context:task optional:true
 *   bool_t     is_cInit_joined()                     check if joined
 *   void           cInit_initializeBridge( const mrb_state* mrb );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "nMruby_tRiteVMBluetooth_tecsgen.h"
#include <stdio.h>
#include <string.h>
#include <kernel.h>
#include <kernel_cfg.h>

#include <mruby.h>
#include <mruby/proc.h>
#include <mruby/data.h>
#include <mruby/compile.h>
#include <mruby/dump.h>
#include <mruby/irep.h>

#include "zmodem-toppers.h"
#include "syssvc/serial.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#define MEM_SIZE 1024*1024 // 1MB
//#define VM_EVAL
//#define MALLOC_EVAL

#include <t_syslog.h>

#define INVALID_VALUE -1
#define EVENTFLAG_START 0
#define EVENTFLAG_END   1
/*
#define SYSLOG_MBM( a , b ) syslog( (a) , (b) )
#define SYSLOG_MBM_3( a , b , c , d , e ) syslog( (a) , (b) , (c), (d), (e) )
#define SYSLOG_MBM_2( a , b , c , d ) syslog( (a) , (b) , (c), (d) )
*/
#define SYSLOG_MBM( a , b ) 
#define SYSLOG_MBM_3( a , b , c , d , e ) 
#define SYSLOG_MBM_2( a , b , c , d )

/**
 * Buffer to store the application module file
 */
// static uint8_t app_binary_buf[COUNT_STK_T(TMAX_APP_BINARY_SIZE)] __attribute__((nocommon));
// uint8_t app_binary_buf[COUNT_STK_T(TMAX_APP_BINARY_SIZE)];

// void mrb_init_zmodem(CELLCB *p_cellcb, uint8_t app_binary_buf[COUNT_STK_T(TMAX_APP_BINARY_SIZE)]);
void mrb_init_mrb(CELLCB *p_cellcb, mrb_state *mrb, mrbc_context *c);
static void test_serial_loader(CELLCB *p_cellcb, intptr_t portid);
ER zmodem_recv_file(ID portid, void *buf, SIZE size, SIZE *filesz);
bool_t flg_malloc;

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMrubyBody
 * entry port: eMrubyBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMrubyBody_main
 * name:         eMrubyBody_main
 * global_name:  nMruby_tRiteVMBluetooth_eMrubyBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMrubyBody_main(CELLIDX idx)
{
#ifdef VM_EVAL
    SYSUTM tstart, tend;
#endif

    CELLCB	*p_cellcb;
    // mrb_state *mrb;
    // mrbc_context *c;

    static FLGPTN p_flagPattern_start;
    static FLGPTN p_flagPattern_end;

    if (VALID_IDX(idx)) {
        p_cellcb = GET_CELLCB(idx);
    }

    while(1) {
        flg_malloc = false;

        if (is_cSemaphore_joined()) {
            cSemaphore_wait();
        }
            test_serial_loader(p_cellcb, SIO_PORT_BT);
            flg_malloc = true;
	    SYSLOG_MBM(LOG_NOTICE, "eMrubyBody_main 1");
        if (is_cSemaphore_joined()) {
            cSemaphore_signal();
        }
	    SYSLOG_MBM(LOG_NOTICE, "eMrubyBody_main 2");
#ifdef VM_EVAL
    get_utm(&tstart);
#endif
        /* new interpreter instance */
        VAR_mrb = mrb_open();
        if (VAR_mrb == NULL) {
            syslog(LOG_EMERG, "Invalid mrb_state, exiting test driver");
            // cSerialPort_write("Invalid mrb_state, exiting test driver\n", 39);
            return;
        }
	    SYSLOG_MBM(LOG_NOTICE, "eMrubyBody_main 3");
#ifdef VM_EVAL
    get_utm(&tend);
    syslog(LOG_EMERG, "mrb_open time = %d micro sec", tend - tstart);
#endif
        VAR_context = mrbc_context_new( VAR_mrb );
	    SYSLOG_MBM(LOG_NOTICE, "eMrubyBody_main 4");

        if (is_cInit_joined()) {
            // TECS Bridge
            cInit_initializeBridge( VAR_mrb );
        }
	    SYSLOG_MBM(LOG_NOTICE, "eMrubyBody_main 5");
	    SYSLOG_MBM_3(LOG_NOTICE, "_inib=%p _inib->cEventflag=%p subscript=%d" , (p_cellcb)->_inib, (p_cellcb)->_inib->cEventflag , EVENTFLAG_START );
	    SYSLOG_MBM_2(LOG_NOTICE, "(p_cellcb)->_inib->cEventflag[%d]=%p", EVENTFLAG_START, (p_cellcb)->_inib->cEventflag[EVENTFLAG_START] );
		
        if (is_cEventflag_joined( EVENTFLAG_START )) {
	    SYSLOG_MBM(LOG_NOTICE, "eMrubyBody_main 5-1");
            cEventflag_set( EVENTFLAG_START, ATTR_setptn );
	    SYSLOG_MBM(LOG_NOTICE, "eMrubyBody_main 5-2");
            cEventflag_wait( EVENTFLAG_START, waitptn, TWF_ANDW, &p_flagPattern_start );
	    SYSLOG_MBM(LOG_NOTICE, "eMrubyBody_main 5-3");
            cEventflag_clear( EVENTFLAG_END, 0x00 );
	    SYSLOG_MBM(LOG_NOTICE, "eMrubyBody_main 5-4");
        }
	    SYSLOG_MBM(LOG_NOTICE, "eMrubyBody_main 6");

        mrb_init_mrb(p_cellcb, VAR_mrb, VAR_context);
        syslog(LOG_EMERG, "end of mruby program");

        if (is_cEventflag_joined( EVENTFLAG_END )) {
            cEventflag_clear( EVENTFLAG_START, 0x00 );
            cEventflag_set( EVENTFLAG_END, ATTR_setptn );
            cEventflag_wait( EVENTFLAG_END, waitptn, TWF_ANDW, &p_flagPattern_end );
        }
#ifdef VM_EVAL
    get_utm(&tstart);
#endif
        mrbc_context_free( VAR_mrb, VAR_context );
        mrb_close( VAR_mrb );
#ifdef VM_EVAL
    get_utm(&tend);
    syslog(LOG_EMERG, "mrb_close time = %d micro sec", tend - tstart);
#endif
    }
}

/* #[<ENTRY_PORT>]# eRiteVM
 * entry port: eRiteVM
 * signature:  sRiteVM
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eRiteVM_reset
 * name:         eRiteVM_reset
 * global_name:  nMruby_tRiteVMBluetooth_eRiteVM_reset
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRiteVM_reset(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    //TODO:code_fetch_hookを使う
    cTask_terminate();
    if (is_cEventflag_joined( EVENTFLAG_START )) {
        cEventflag_clear( EVENTFLAG_START, 0x00 );
    }
    if (is_cEventflag_joined( EVENTFLAG_END )) {
        cEventflag_clear( EVENTFLAG_END, 0x00 );
    }
    if (is_cSemaphore_joined()) {
        cSemaphore_initialize();
    }
    if ( flg_malloc ) {
        mrbc_context_free( VAR_mrb, VAR_context );
        mrb_close( VAR_mrb );
    }
    cReset_reset();
//TODO: ZMODEMのコンポーネント化したら変更
    ter_tsk(ZMODEM_RECV_TASK);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

void
mrb_init_mrb(CELLCB	*p_cellcb, mrb_state *mrb, mrbc_context *c){
    syslog(LOG_NOTICE,"-----mruby application-----");

    /* ２つの mruby bytecode を動作させる */
    mrb_load_irep_cxt(mrb, ATTR_irepLib, c);     //mruby library
    mrb_load_irep_cxt(mrb, VAR_irepApp, c);      //mruby application (transferred via Bluetooth)

    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
        exit(0);
    }
}

extern intptr_t bt_snd_chr(intptr_t c);
extern intptr_t uart_snd_chr(intptr_t c);
extern void initialize_lcd_dri();
#define UART1	(*(volatile struct st_uart *)0x01D0C000)
/* --------fwite----------- */
/* size_t fwrite(const void *buf, size_t size, size_t n, FILE *fp){ */
int fputs(const char_t *buf, FILE *fp) {
    intptr_t intp;
    char *cp;
    cp = (char*)buf;
    int size = strlen(buf);
    // シリアルポートが結合されている場合のみ呼び出す
    // if(is_cSerialPort_joined()){
    //     cSerialPort_write(buf, size);
    // }

    for (int i = 0; i < size; i++) {
        intp = *cp++;
        if (intp == '\n') {
            bt_snd_chr('\r');
            while(!uart_send(&UART1, '\r'));
        }
        bt_snd_chr(intp);
        while(!uart_send(&UART1, intp));
    }
    return size;
};

#ifndef EV3_SOUND
void _write(){}
void _close(){}
void _lseek(){}
void _read(){}
//void _fstat(){}
//void _isatty(){}
#endif

//void _exit(){}
//void _getpid(){}
//void _kill(){}
void _gettimeofday(){}
void _fini(){}

static
void test_serial_loader(CELLCB *p_cellcb, intptr_t portid) {
    ER   ercd;
    SIZE filesz;

    syslog(LOG_NOTICE, "Start to receive an application file using ZMODEM protocol.");
    // platform_pause_application(false); // Ensure the priority of Bluetooth  task
    ercd = zmodem_recv_file(portid, VAR_irepApp, ATTR_irepAppSize, &filesz);
    // platform_pause_application(true); // Ensure the priority of Bluetooth  task

    if (ercd != E_OK) {
        syslog(LOG_NOTICE, "Receiving file failed, ercd: %d.", ercd);
        // tslp_tsk(500);
        return;
    }
    syslog(LOG_NOTICE, "Receiving file completed, file size: %d bytes", filesz);
}
