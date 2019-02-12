/* namespace TOPPERS_JSP { */


/* TOPPERS/JSP 1.4.2 SH3 MS7727CP01　*/
/* enumのサイズ: 32ビット */
/* */
/* 以下ではカーネルオブジェクトをセルとして扱う */
signature sTaskMainFunc {
/*  VP_INTはポインタ型か? */
 void taskfunc( [in]VP_INT exinf );
};

signature sTexHdr {
 void texhdr( void );
};

signature sTexHdrFunc {
 void texrtn( [in]TEXPTN texptn, [in]VP_INT exinf);
};

signature sCycHdrFunc {
 void cychdr( [in]VP_INT exinf);
};

signature sExcHdrFunc {
 void exchdr( [in]VP exinf);
};

signature sInitRtnFunc {
 void initrtn( [in]VP_INT exinf);
};

signature sAlmHdr {
 void almhdr( [in]VP_INT exinf);
};


celltype tTask {
    call sTaskMainFunc cTaskmain;
    call sTexHdr cTexhdr;
    attr {
 ATR tskattr = 0;
 VP_INT exinf = 0;
/*	FP  task = NULL; */
/* NULLは((void *)0)としている
キャストしていると例外発生する
*/
 INT task = 0;
 PRI itskpri = 15;
 SIZE stksz = 512;
/*	VP stk = NULL;*/
 VP stk = 0;

    };
    factory {
 factory_tTAsk( tskattr , exinf , itskpri , stksz , stk );
    };

};


celltype tTaskMain {
    entry sTaskMainFunc eTaskmain;
    attr {
 int x = 0;
    };
};

celltype tTexHdr {
    entry sTexHdr eTexhdr;
    call sTexHdrFunc cTexhdrfunc;

    attr {
 ATR texatr = 0;
/*	FP texhdrfunc = NULL; */
 FP texhdrfunc = 0;
    };

    factory {
 factory_tTexHdr( texatr , texhdrfunc );
    };
};

celltype tTexHdrMain {
    entry sTexHdrFunc eTexhdrfunc;

    attr {
 int x = 0;

    };
};

celltype tCycHdr {
    call sCycHdrFunc cCychdrfunc;

    attr {
 ATR cycatr = 0;
/*
	VP_INT exinf = NULL;
	FP cychdrfunc = NULL;
*/
 VP_INT exinf = 0;
 FP cychdrfunc = 0;
 RELTIM cyctim = 0;
 RELTIM cycphs = 0;
    };

    factory {
 factory_tCycHdr( cycatr , exinf , cychdrfunc , cyctim , cycphs );
    };
};

celltype tCycHdrMain {
    entry sCycHdrFunc eCychdrfunc;

    attr {
 int x = 0;

    };
};

celltype tExcHdr {
    call sExcHdrFunc cExchdrfunc;

    attr {
     EXCNO excno = 0;
 ATR excatr = 0;
/*	FP    exchdrfunc = NULL;*/
 FP exchdrfunc = 0;
    };

    factory {
 factory_tExcHdr( excno , excatr , exchdrfunc );
    };
};

celltype tExcHdrMain {
    entry sExcHdrFunc eExchdrfunc;

    attr {
 int x = 0;

    };

};

/*  とりあえずの定義 */
celltype tInitRtn {
    call sInitRtnFunc cInitrtn;

    attr {
 ATR initatr = 0;
/*	VP_INT    exinf = NULL;*/
 VP_INT exinf = 0;
/*	FP        initrtnfunc = NULL;  */
    };

    factory {
 factory_tInitRtn( initatr , exinf );
    };
};

celltype tInitRtnMain {
    entry sInitRtnFunc eInitrtn;

    attr {
 int x = 0;

    };

};

/* 以下は形式的に定義しただけ */
celltype tAlmHdr {
    call sAlmHdr cAlmhdr;

    attr {
 ATR almatr = 0;
/*	VP_INT exinf = NULL;*/
 VP_INT exinf = 0;
/*	FP     almhdr; */
    };

    factory {
 factory_tAlmHdr( );
    };

};
celltype tAlmHdrMain {
    entry sAlmHdr eAlmhdr;
    attr {
 int x = 0;

    };

};
celltype tOvrHdr {
    attr {
 int x = 0;

    };

};
celltype tOvrHdrMain {
    attr {
 int x = 0;

    };

};
celltype tIntHdr {
    attr {
 int x = 0;

    };

};
celltype tIntHdrMain {
    attr {
 int x = 0;

    };

};
celltype tIsRtn {
    attr {
 int x = 0;

    };

};
celltype tIsRtnMain {
    attr {
 int x = 0;

    };

};
celltype tExSvc {
    attr {
 int x = 0;

    };

};
celltype tExSvcMain {
    attr {
 int x = 0;

    };

};
celltype tSem {
    attr {
 int x = 0;

    };

};
celltype tFlg {
    attr {
 int x = 0;

    };

};
celltype tDtq {
    attr {
 int x = 0;

    };

};
celltype tMbx {
    attr {
 int x = 0;

    };

};
celltype tMtx {
    attr {
 int x = 0;

    };

};
celltype tMbf {
    attr {
 int x = 0;

    };

};
celltype tPor {
    attr {
 int x = 0;

    };

};
celltype tRdv {
    attr {
 int x = 0;

    };
};

celltype tMpf {
    attr {
 int x = 0;

    };

};
celltype tMpl {
    attr {
 int x = 0;

    };

};
celltype tSystem {
    attr {
 int x = 0;

    };

};

celltype tAppl {
    attr {
 int x = 0;
    };
};
