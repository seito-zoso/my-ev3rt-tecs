#include "jsp_def.h"
/**/

#ifdef _SH3_MS7727CP01_GNUDEV_
typedef int32_t   INT;
typedef uint32_t  UINT;
typedef int32_t   VP_INT;
typedef	uint64_t  UD;	/* 符号無し64ビット整数 */

typedef uint32_t  size_t;

/* μITRON4.0仕様(Ver. 4.02.00) のスタンダードプロファイルでないもののうち　*/
/* TOPPERS/JSPがターゲット依存部でサポートするもの　*/
/* config/sh3/cpu_defs.h */

typedef	UINT		INTNO;		/* 割込み番号 */

/*
 * 割込みマスクの型と割込みマスクの変更/参照
 */
typedef	UINT		IPM;		/* 割込みマスク */

/* config/sh3/cpu_defs.h */
typedef	UD  SYSUTIM;	       /* 性能評価用システム時刻 */


#endif

/**/


/*    enum32 OBJECT_ATTR { TA_NULL=0u } */

    ENUM OBJECT_ATTR { TA_NULL = 0 }; 

    ENUM RETURN_VALUE { TRUE=1 , FALSE=0, E_OK=0 }   ;

    ENUM ERROR_CODE { 
	E_SYS=-5 			/* システムエラー */ 
,	E_NOSPT=-9  			/* 未サポート機能 */
,	E_RSFN		= (-10)		/* 予約機能コード */
,	E_RSATR		= (-11)		/* 予約属性 */
,	E_PAR		= (-17)		/* パラメータエラー */
,	E_ID		= (-18)		/* 不正ID番号 */
,	E_CTX		= (-25)		/* コンテキストエラー */
,	E_MACV		= (-26)		/* メモリアクセス違反 */
,	E_OACV		= (-27)		/* オブジェクトアクセス違反 */
,	E_ILUSE		= (-28)		/* サービスコール不正使用 */
,	E_NOMEM		= (-33)		/* メモリ不足 */
,	E_NOID		= (-34)		/* ID番号不足 */
,	E_OBJ		= (-41)		/* オブジェクト状態エラー */
,	E_NOEXS		= (-42)		/* オブジェクト未生成 */
,	E_QOVR		= (-43)		/* キューイングオーバーフロー */
,	E_RLWAI		= (-49)		/* 待ち状態の強制解除 */
,	E_TMOUT		= (-50)		/* ポーリング失敗またはタイムアウト */
,	E_DLT		= (-51)		/* 待ちオブジェクトの削除 */
,	E_CLS		= (-52)		/* 待ちオブジェクトの状態変化 */
,	E_WBLK		= (-57)		/* ノンブロッキング受付け */ ,
	E_BOVR		= -58		/* バッファオーバーフロー */
};

/*
 *  タイムアウト指定
 */
    ENUM TIME_OUT {
    	TMO_POL    =	0		/* ポーリング */
      , TMO_FEVR   =	(-1)		/* 永久待ち */
      , TMO_NBLK   =	(-2)		/* ノンブロッキング */
    };

/*
 *  オブジェクト属性の定義
 */
    ENUM OBJECT_ATTR {
/*  	  TA_HLNG	=0x00u */
  	  TA_HLNG	=0		/* 高級言語用インタフェース */
 	, TA_ASM	=1		/* アセンブリ言語用インタフェース */
    };

    ENUM TASK_WAIT_QUEUE_ATTR {
	  TA_TFIFO	=0		/* タスクの待ち行列をFIFO順に */
	, TA_TPRI	=1		/* タスクの待ち行列を優先度順に */
    };

    ENUM MSG_QUEUE_ATTR {
	  TA_MFIFO	=0		/* メッセージキューをFIFO順に */
	, TA_MPRI	=2		/* メッセージキューを優先度順に */
    };
    ENUM TASK_STATE_ATTR {
	   TA_ACT	=2		/* タスクを起動された状態で生成 */
    };
    ENUM EVENT_FLG_ATTR {
	  TA_WSGL	=0		/* イベントフラグの待ちタスクを1つに */
	, TA_CLR	=4		/* イベントフラグのクリア指定 */
    };
    ENUM CYC_HDR_ATTR {
 	  TA_STA	= 2		/* 周期ハンドラを動作状態で生成 */
    };
/*
 *  サービスコールの動作モードの定義
 */
    ENUM EVENT_FLG_OP_MODE {
	TWF_ANDW	= 0		/* イベントフラグのAND待ち */
,	TWF_ORW		= 1		/* イベントフラグのOR待ち */
    };
/*
 *  その他の定数の定義
 */
    ENUM MISC_CONST {
	TSK_SELF	= 0		/* 自タスク指定 */
,	TSK_NONE	= 0		/* 該当するタスクがない */
,	TPRI_SELF	= 0		/* 自タスクのベース優先度の指定 */
,	TPRI_INI	= 0		/* タスクの起動時優先度の指定 */
    };

/* 以下はITRON4.0仕様で指定された項目 */
/* enumで指定する場合は、enumのサイズは依存部により決定される */

ENUM OBJECT_ATTR {
/*  	  TA_HLNG	=0x00u */
  	  TA_HLNG	=0		/* 高級言語用インタフェース */
 	, TA_ASM	=1		/* アセンブリ言語用インタフェース */
};

#define TA_HLNG (0)
#define TA_ASM	(1)		/* アセンブリ言語用インタフェース */

/* 以下はアプリケーション固有の値 */



/* 以下にはサービスコールのインタフェース定義に使用するための型を定義する */

    typedef UINT    	UW;
    typedef INT 	ER;
    typedef INT 	ER_BOOL;
    typedef INT 	ER_ID;
    typedef INT 	ER_UINT;
    typedef INT 	ID;
    typedef INT 	PRI;
    typedef bool_t 	BOOL;
    typedef void        *VP;
    /* , _bool_ int */
    typedef UINT 	MODE;
    /* typedef _vp_int_ VP_INT */
    typedef int         EXCNO;
    typedef UINT	ATR;		/* オブジェクトの属性 */

    typedef size_t      SIZE;

    typedef INT 	TMO;
    typedef UINT        RELTIM;
    typedef UW          SYSTIM;         

    /**/
    /* kernel.hで定義 */
    typedef UINT TEXPTN;
    typedef UINT FLGPTN;

　　typedef void (*FP)(void);

    typedef struct t_msg {  /* メールボックスのメッセージヘッダ */
            struct t_msg    *next;
    } T_MSG;
    
    typedef struct t_msg_pri {              /* 優先度付きメッセージヘッダ */
            T_MSG           msgque;         /* メッセージヘッダ */
            PRI             msgpri;         /* メッセージ優先度 */
    } T_MSG_PRI;
        
/* μITRON4.0仕様(Ver. 4.02.00) のスタンダードプロファイルでないもののうち　*/
/* TOPPERS/JSPが実装独自に提供するカーネルのサービスコールのうち　*/
/* TOPPERS/JSPが非依存部でサポートするもの　*/
/* #define TMAX_LOGINFO	6 */

    typedef struct {
		UINT	logtype;		/* ログ情報の種別 */
		SYSTIM	logtim;			/* ログ時刻 */
		VP_INT	loginfo[TMAX_LOGINFO];	/* その他のログ情報 */
    } SYSLOG;

/* TOPPERS/JSPが実装独自に提供するカーネルのサービスコールのうち　*/
/* TOPPERS/JSPがターゲット依存部でサポートするもの　*/


/* TOPPERS/JSPが実装独自に提供するサービスコールのうち　*/
/* インターフェースの解釈がターゲット依存であるもの　*/
    typedef struct {
	UINT	reacnt;		/* 受信バッファ中の文字数 */
	UINT	wricnt;		/* 送信バッファ中の文字数 */
    } T_SERIAL_RPOR;

    /* ITRON4.0仕様スタンダードプロファイル準拠のサービスコールのsignature */
    signature sKernel {
	/* 以下はタスクコンテキスト用 */
    	ER act_tsk ( [in] ID tskid );
    	ER_UINT can_act ( [in] ID tskid );
    	void ext_tsk ( void );
    	ER ter_tsk ( [in] ID tskid );
    	ER chg_pri ( [in] ID tskid , [in] PRI tskpri );
    	ER get_pri ( [in] ID tskid , [out] PRI * p_tskpri );
    	ER slp_tsk ( void );
    	ER tslp_tsk ( [in] TMO tmout );
    	ER wup_tsk ( [in] ID tskid );
        ER_UINT can_wup ( [in] ID tskid );
        ER rel_wai  ( [in] ID tskid );
        ER sus_tsk  ( [in] ID tskid );
        ER rsm_tsk  ( [in] ID tskid );
        ER frsm_tsk ( [in] ID tskid );
        ER dly_tsk  ( [in] RELTIM dlytim );
        ER ras_tex  ( [in] ID tskid , [in] TEXPTN rasptn );
        ER dis_tex  ( void );
        ER ena_tex  ( void );
        ER sig_sem  ( [in] ID semid );
        ER wai_sem  ( [in] ID semid );
        ER pol_sem  ( [in] ID semid );
        ER twai_sem ( [in] ID semid , [in] TMO tmout );
        ER set_flg  ( [in] ID flgid , [in] FLGPTN setptn );
        ER clr_flg  ( [in] ID flgid , [in] FLGPTN clrptn );
        ER wai_flg  ( [in] ID flgid , [in] FLGPTN waiptn , [in] MODE wfmode , [out] FLGPTN * p_flgptn );
        ER pol_flg  ( [in] ID flgid , [in] FLGPTN waiptn , [in] MODE wfmode , [out] FLGPTN * p_flgptn );
        ER twai_flg ( [in] ID flgid , [in] FLGPTN waiptn , [in] MODE wfmode , [out] FLGPTN * p_flgptn , [in] TMO tmout );
        ER snd_dtq  ( [in] ID dtqid , [in] VP_INT data );
        ER psnd_dtq ( [in] ID dtqid , [in] VP_INT data );
        ER tsnd_dtq ( [in] ID dtqid , [in] VP_INT data , [in] TMO tmout );
        ER fsnd_dtq ( [in] ID dtqid , [in] VP_INT data );
        ER rcv_dtq  ( [in] ID dtqid , [out] VP_INT *p_data );
        ER prcv_dtq ( [in] ID dtqid , [out] VP_INT *p_data );
        ER trcv_dtq ( [in] ID dtqid , [out] VP_INT *p_data , [in] TMO tmout );
        ER snd_mbx  ( [in] ID mbxid ,  [send(sigAlloc)] T_MSG * pk_msg );
        ER rcv_mbx  ( [in] ID mbxid  , [receive(sigAlloc)] T_MSG * * ppk_msg);
        ER prcv_mbx ( [in] ID mbxid , [receive(sigAlloc)] T_MSG * * ppk_msg , int msgsize );
        ER trcv_mbx ( [in] ID mbxid , [receive(sigAlloc)] T_MSG * * ppk_msg , [in] TMO tmout , int msgsize );
        ER get_mpf  ( [in] ID mpfid , [receive(sigAlloc)] VP * p_blk , int msgsize );
        ER pget_mpf ( [in] ID mpfid , [receive(sigAlloc)] VP * p_blk , int msgsize );
        ER tget_mpf ( [in] ID mpfid , [out , receive(sigAlloc) , size_is(msgsize) ] VP * p_blk , [in] TMO tmout , int msgsize );
        ER rel_mpf ( [in] ID mpfid , [send(sigAlloc)] VP blk );
        ER set_tim ( [in] SYSTIM * p_systim );
        ER get_tim ( [out] SYSTIM * p_systim );
        ER sta_cyc ( [in] ID cycid );
        ER stp_cyc ( [in] ID cycid );
        ER rot_rdq ( [in] PRI tskpri );
        ER get_tid ( [out] ID * p_tskid );
        ER loc_cpu ( void );
        ER unl_cpu ( void );
        ER dis_dsp ( void );
        ER ena_dsp ( void );

	/* 以下は非タスクコンテキスト用 */
        ER iact_tsk ( [in] ID tskid );
        ER iwup_tsk ( [in] ID tskid );
        ER irel_wai ( [in] ID tskid );
        ER iras_tex ( [in] ID tskid , [in] TEXPTN rasptn );
        ER isig_sem ( [in] ID semid );
        ER iset_flg ( [in] ID flgid , [in] FLGPTN setptn );
        ER ipsnd_dtq ( [in] ID dtqid , [in] VP_INT data );
        ER ifsnd_dtq ( [in] ID dtqid , [in] VP_INT data );
        ER isig_tim ( void );
        ER irot_rdq ( [in] PRI tskpri );
        ER iget_tid ( [out] ID * p_tskid );
        ER iloc_cpu ( void );
        ER iunl_cpu ( void );

	/* 以下はタスクコンテキストでも非タスクコンテキストでも呼び出せる */
        BOOL sns_tex ( void );
        BOOL sns_ctx ( void );
        BOOL sns_loc ( void );
        BOOL sns_dsp ( void );
        BOOL sns_dpn ( void );


/* μITRON4.0仕様(Ver. 4.02.00) のスタンダードプロファイルでないもののうち　*/
/* TOPPERS/JSPがターゲット依存部でサポートするもの　*/
	ER	dis_int( [in] INTNO intno);
	ER	ena_int( [in] INTNO intno);
	ER	chg_ipm( [in] IPM ipm);
	ER	get_ipm( [in] IPM *p_ipm);

/* TOPPERS/JSPが実装独自に提供するカーネルのサービスコールのうち　*/
/* TOPPERS/JSPが非依存部でサポートするもの　*/
	BOOL vxsns_ctx( [in] VP p_excinf);
    	BOOL vxsns_loc( [in] VP p_excinf);
    	BOOL vxsns_dsp( [in] VP p_excinf);
    	BOOL vxsns_dpn( [in] VP p_excinf);
    	BOOL vxsns_tex( [in] VP p_excinf);
	BOOL vsns_ini(void);
	ER vwri_log( [in] UINT prio, [in] SYSLOG *p_log);
	ER_UINT vrea_log( [out] SYSLOG *p_log);
	ER vmsk_log( [in] UINT logmask, [in] UINT lowmask);

/* TOPPERS/JSPが実装独自に提供するカーネルのサービスコールのうち　*/
/* TOPPERS/JSPがターゲット依存部でサポートするもの　*/
/*	 ER	vxget_tim(SYSUTIM *p_sysutim) throw(); */
	 ER	vxget_tim( [out] SYSUTIM *p_sysutim);

/* TOPPERS/JSPが実装独自に提供するサービスコールのうち　*/
/* インターフェースの解釈がターゲット依存であるもの　*/
	ER serial_opn_por( [in] ID portid);
	ER serial_cls_por( [in] ID portid);
	/* ER_UINT serial_rea_dat(ID portid, char *buf, UINT len) */
	ER_UINT serial_rea_dat( [in] ID portid, [in] UINT len , [out , size_is(len)] char *buf);

/* この場合は、エラーになるはず
	ER_UINT serial_rea_dat( [in] ID portid, [out] UINT len , [out , size_is(len)] char *buf);
*/
/* この場合は、エラーになるはず
	ER_UINT serial_rea_dat( [in] ID portid, [in] UINT len , [out , count_is(len)] char *buf);
*/
	/* ER_UINT serial_wri_dat(ID portid, char *buf, UINT len) */
	ER_UINT serial_wri_dat( [in] ID portid,  [in] UINT len, [out , size_is(len)] char *buf);
	ER serial_ctl_por( [in] ID portid, [in]UINT ioctl);
	ER serial_ref_por( [in] ID portid, [out]T_SERIAL_RPOR *pk_rpor);

/* TOPPERS/JSPが実装独自に提供するライブラリ　*/
/* 関数の型にconstを指定できない 
	const char *itron_strerror([in]ER ercd);
*/
/* 関数の型にポインタ型を指定できない
	char *itron_strerror([in]ER ercd); 
*/
	char itron_strerror([in]ER ercd);
/* 関数の引数の型にconstを指定できない
	void t_perror([in]UINT prio, [in]const char *file, [in]int line, [in]const char *expr, [in]ER ercd); 
*/
	void t_perror([in]UINT prio, [in] char *file, [in]int line, [in] char *expr, [in]ER ercd);

    };
/*}; */

