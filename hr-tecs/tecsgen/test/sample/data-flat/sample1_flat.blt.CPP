/* namespace TOPPERS_JSP { */


/* TOPPERS/JSP 1.4.2 SH3 MS7727CP01　*/
/* enumのサイズ: 32ビット */
/* */
enum32 APPL_TASK_PRIORITY {
 MAIN_PRIORITY=5 ,
 HIGH_PRIORITY = 9,
 MID_PRIORITY= 10,
 LOW_PRIORITY =11
};






enum32 APPL_STACK_SIZE {



 STACK_SIZE = 512
};


/*
 *  ターゲット依存の定義（CPU例外ハンドラの起動方法など）
 */



enum32 CPU_EXCEPTION {




 CPUEXC1 = 224 /* ロードエラー例外 */
};




enum32 SERIAL_PORT_NUMBER {




 TASK_PORTID = 1 /* 文字入力するシリアルポートID */
};


enum32 APPL_CONSTANT {




 LOOP_REF = 1000000 /* 速度計測用のループ回数 */
};




/* RAISE_CPU_EXCEPTION */
/* ここまで */

cell tTexHdrMain xTexhdrMain {
 x = 0;
};

cell tTexHdr Texhdr {
 cTexhdrfunc = TexhdrMain.eTexhdrfun;
};

cell tTaskMain MaintaskMain {
/* cell{}内にまったく記述がないとエラーになる */

/*　存在しない属性、ポートへの代入があると例外が発生する
	x = 0;
*/
 x = 0;

};

cell tTask Maintask {
 cTaskmain = MaintaskMain.eTaskmain;
 cTexhdr = Texhdr.eTexhdr;

 tskattr = TA_HLNG;
 itskpri = (5);
 stksz = STACK_SIZE;
/*	stk = NULL; */
};

cell tTaskMain Task0Main {
/*　存在しない属性、ポートへの代入があると例外が発生する
	x = 0;
*/
 x = 0;
};


cell tTask Task1 {
 cTaskmain = Task0Main.eTaskmain;
 cTexhdr = Texhdr.eTexhdr;
 tskattr = TA_HLNG;
/*	exinf = (VP_INT)1;*/
 exinf = 1;
 itskpri = (10);
 stksz = STACK_SIZE;
/*	stk = NULL;*/
 stk = 0;
};

cell tTask Task2 {
 cTaskmain = Task0Main.eTaskmain;
 cTexhdr = Texhdr.eTexhdr;
 tskattr = TA_HLNG;
/*	exinf = (VP_INT)2;*/
 exinf = 2;
 itskpri = (10);
 stksz = STACK_SIZE;
/*	stk = NULL;*/
 stk = 0;
};

cell tTask Task3 {
 cTaskmain = task0Main.taskmain;
 cTexhdr = Texhdr.eTexhdr;
 tskattr = TA_HLNG;
/*	exinf = (VP_INT)3;*/
 exinf = 3;
 itskpri = (10);
 stksz = STACK_SIZE;
/*	stk = NULL;*/
 stk = 0;
};

cell tCycHdrMain CychdrMain {

 x = 0;
};

cell tCycHdr Cychdr {
 cCychdrfunc = CychdrMain.eCynchdrfunc;
};

cell tExcHdrMain ExcHdrMain {
 x = 0;
};

cell tExcHdr ExcHdr {
 cExchdrfunc = eExchdrfunc;
};
