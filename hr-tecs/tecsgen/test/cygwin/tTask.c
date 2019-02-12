/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * task_attribute   ATR              ATTR_task_attribute
 * exception_attribute ATR              ATTR_exception_attribute
 * priority         PRI              ATTR_priority   
 * stack_size       SIZE             ATTR_stack_size 
 * name             char_t*          ATTR_name       
 *
 * 呼び口関数 #_TCPF_#
 * call port : cBody  signature: sTaskBody context: task
 *   void           cBody_main( );
 * call port : cExceptionBody  signature: sTaskExceptionBody context: task
 *   void           cExceptionBody_main( TEXPTN pattern );
 *
 * #[</PREAMBLE>]# */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include "tTask_tecsgen.h"
int pthread_yield(void);

#ifndef E_OK
#define	E_OK	0		/* 正常終了 */
#define	E_ID	(-18)	/* 不正ID番号 */
#endif

/* Simple error handling functions */
#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

/* 関数プロトタイプ宣言 */
static void	prepare_signal();
static void *sig_thread(void *arg);

#define N_PTHREAD   100
pthread_t  pthread[N_PTHREAD];
int        n_pthread = 0;

void *tTask_call_cBody_main( void *p )
{
	CELLCB *p_cellcb = (CELLCB *)p;
	// printf( "%s: not active at start up ###\n", ATTR_name );
	VAR_state = TASK_STATE_1;

	pthread_mutex_init ( &VAR_my_mutex,  0 );	
	pthread_cond_init ( &VAR_my_cond,  0 );	

	// すべてのタスクの準備ができるまで待つ
	// pthread_suspend( pthread_self() );
	pthread_mutex_lock( &VAR_my_mutex );
	pthread_cond_wait( &VAR_my_cond, &VAR_my_mutex );
	pthread_mutex_unlock( &VAR_my_mutex ) ;

	fprintf( stderr, "*** starting task '%s'  %08lX\n", ATTR_name, (unsigned long)tTask_call_cBody_main );
	cBody_main();
	fprintf( stderr, "*** exiting task '%s'\n", ATTR_name );
	pthread_exit(0);

	return (void *)0;
}

/*
 * プロセスの main
 *
 * すべてのタスクは、子スレッドの中で動作する。
 * main スレッドは、すべての子スレッドが終了するのを待ち、すべての子スレッドが終了すると main が終了する。
 * すべての子スレッドの終了を待たずして、終了したい場合は、exit() を呼出す。
 */
int main(int arg, char **argv)
{
	int		i;
	CELLCB	*p_cellcb;
	int		result;
	static int		state = 999;

	INITIALIZE_TECS();

	/* 不要なシグナルの無視 */
	prepare_signal();

	// タスクを生成
	// resume を掛けられたときに未生成だと失敗してしまうため、先にすべて生成する
	// printf( "create tasks\n" );
	state = 1;
	FOREACH_CELL( i, p_cellcb )
		if( n_pthread >= N_PTHREAD ){
			fprintf( stderr, "too many threads max=%d", N_PTHREAD );
			exit( 1 );
		}
		pthread_create( &VAR_my_thread, NULL, tTask_call_cBody_main, (void *)p_cellcb );
		pthread[n_pthread] = VAR_my_thread;
		n_pthread++;
	END_FOREACH_CELL

	// タスクは、すべてのタスクが生成完了するまで suspend 状態となる
	// printf( "wait for init tasks\n" );
	state = 2;
	FOREACH_CELL( i, p_cellcb )
		// 厳密には、条件変数を使うべきだろうが、テスト用と割り切って、変数だけで状態を見る
		// もし pthread に suspend 状態かどうか見る手段があれば、その方がよい
		while( VAR_state != TASK_STATE_1 )
			pthread_yield();
	END_FOREACH_CELL

	// 1 msec の休止を入れる
	// usleep を入れないと pthread_continue で止まることがある.
	// suspend 状態に入りきれない状態で continue しているからか ?
	usleep(1000);

	// TA_ACT 属性を持つタスクを起動させる
	// printf( "start TA_ACT tasks\n" );
	state = 3;

	FOREACH_CELL( i, p_cellcb )
		if( ATTR_taskAttribute & TA_ACT ){
			// printf( "%s: start\n", ATTR_name );
			pthread_cond_signal( &VAR_my_cond );
			state++;
		}
	END_FOREACH_CELL

	/* すべてのスレッドが終わるのを待つ */
	while( --n_pthread >= 0 ){
		pthread_join( pthread[n_pthread], (void **)&result );
//		fprintf( stderr, "thread[%d] exited with status %d\n", n_pthread, result );
	}
}
/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

/*
 * 不要シグナルの無視
 *   socket への write で、相手がすでにいない場合 SIGPIPE が発生するのを無視
 */
static void
prepare_signal()
{
	int			result;
    pthread_t	thread;
    static sigset_t	set;
    int 		s;

    sigemptyset(&set);
    sigaddset(&set, SIGPIPE);     /* SIGPIPE の無視 */
    s = pthread_sigmask(SIG_BLOCK, &set, NULL);
    if (s != 0)
        handle_error_en(s, "pthread_sigmask");

	/* 不要シグナル補足スレッドの生成 */
    s = pthread_create(&thread, NULL, &sig_thread, (void *) &set);
    if (s != 0)
        handle_error_en(s, "pthread_create");
}

/*
 * 不要なシグナルを補足
 */
static void *
sig_thread(void *arg)
{
    sigset_t *set = (sigset_t *) arg;
    int s, sig;

    for (;;) {
        s = sigwait(set, &sig);
        if (s != 0)
            handle_error_en(s, "sigwait");
        printf("Signal handling thread got signal %d\n", sig);
    }
}
