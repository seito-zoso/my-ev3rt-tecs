
/*
 * このファイルは、コンパイル、リンクを正常に通すことだけを目的として設
 * けられたものである。動作させるのには役に立たない。
 */
#define	DeclareTask( Task )
#define	TASK( t )	void tTask_##t()

#define DeclareResource( Resource )
#define ISR( i )	void tISR_##i()

#define	DeclareAlarm( Alarm1 )
#define	ALARMCALLBACK( SampleCallback )	void tAlarm_##SampleCallback()
