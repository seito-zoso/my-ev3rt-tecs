/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: t_stddef.h 8 2006-10-29 12:01:12Z asp $
 */

/*
 *		TOPPERS共通インクルードファイル
 *
 *  TOPPERS関連のすべてのソースファイルでインクルードすべきインクルード
 *  ファイル．各種のカーネルやソフトウェア部品で共通に用いることを想定
 *  している．TOPPERSの各種のカーネルやソフトウェア部品で共通に用いるデー
 *  タ型，定数，マクロの定義などを含む．
 *
 *  アセンブリ言語のソースファイルやシステムコンフィギュレーションファ
 *  イルからこのファイルをインクルードする時は，TOPPERS_MACRO_ONLYを定
 *  義しておく．これにより，マクロ定義以外を除くようになっている．また，
 *  NULLの定義も除く．
 *
 *  このファイルをインクルードする前にインクルードしておくべきファイル
 *  はない．
 */

#ifndef TOPPERS_T_STDDEF_H
#define TOPPERS_T_STDDEF_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ターゲット依存部
 */
#include "target_stddef.h"

/*
 *  C言語/EC++でthrow()に対処するための定義
 */
#if !defined(__cplusplus) || defined(__embedded_cplusplus)
#define throw()
#endif

#ifndef UNUSE_TECS_DEF

#ifndef TOPPERS_MACRO_ONLY

/*
 *  ターゲット依存のデータ型とマクロのデフォルト定義
 */
#ifndef TOPPERS_bool
#define TOPPERS_bool	int				/* ブール型 */
#endif /* TOPPERS_bool */

#ifndef TOPPERS_size
#define TOPPERS_size	uintptr_t		/* サイズ型 */
#endif /* TOPPERS_size */

#ifndef TOPPERS_fp
struct TOPPERS_dummy_t { int TOPPERS_dummy_field; };
typedef	void			(*TOPPERS_fp_t)(struct TOPPERS_dummy_t);
#define TOPPERS_fp		TOPPERS_fp_t	/* プログラムの起動番地 */
#endif /* TOPPERS_fp */

#ifndef CHAR_BIT
#define CHAR_BIT		8				/* char型のビット数 */
#endif /* CHAR_BIT */

/*
 *  共通データ型
 */
typedef signed int		int_t;		/* 自然なサイズの符号付き整数 */
typedef unsigned int	uint_t;		/* 自然なサイズの符号無し整数 */

typedef signed long		long_t;		/* 長めのサイズの符号付き整数 */
typedef unsigned long	ulong_t;	/* 長めのサイズの符号無し整数 */

typedef TOPPERS_bool	BOOL;		/* 真偽値 */
typedef	TOPPERS_size	SIZE;		/* メモリ領域のサイズ */
typedef	TOPPERS_fp		FP;			/* プログラムの起動番地 */

typedef int_t			FN;			/* 機能コード */
typedef	int_t			ER;			/* エラーコード */
typedef	int_t			ID;			/* オブジェクトのID番号 */
typedef	uint_t			ATR;		/* オブジェクトの属性 */
typedef	uint_t			STAT;		/* オブジェクトの状態 */
typedef	uint_t			MODE;		/* サービスコールの動作モード */
typedef	int_t			PRI;		/* 優先度 */

typedef	int_t			TMO;		/* タイムアウト指定 */
typedef	uint_t			RELTIM;		/* 相対時間 */
typedef	ulong_t			SYSTIM;		/* システム時刻 */
typedef	ulong_t			SYSUTIM;	/* 性能評価用システム時刻 */

typedef	int_t			ER_BOOL;	/* エラーコードまたは真偽値 */
typedef	int_t			ER_ID;		/* エラーコードまたはID番号 */
typedef	int_t			ER_UINT;	/* エラーコードまたは符号無し整数 */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  一般定数
 *
 *  TOPPERS_MACRO_ONLYの時には，NULLを定義しない．これは，システムコン
 *  フィギュレーションファイルを処理する場合にはNULLを定義してはならな
 *  いためである．
 */
#ifndef TOPPERS_MACRO_ONLY
#ifndef NULL
#define NULL		0			/* 無効ポインタ */
#endif /* NULL */
#endif /* TOPPERS_MACRO_ONLY */

#define TRUE		1			/* 真 */
#define FALSE		0			/* 偽 */
#define E_OK		0			/* 正常終了 */

/*
 *  メインエラーコード
 */
#define E_SYS		(-5)		/* システムエラー */
#define E_NOSPT		(-9)		/* 未サポート機能 */
#define E_RSFN		(-10)		/* 予約機能コード */
#define E_RSATR		(-11)		/* 予約属性 */
#define E_PAR		(-17)		/* パラメータエラー */
#define E_ID		(-18)		/* 不正ID番号 */
#define E_CTX		(-25)		/* コンテキストエラー */
#define E_MACV		(-26)		/* メモリアクセス違反 */
#define E_OACV		(-27)		/* オブジェクトアクセス違反 */
#define E_ILUSE		(-28)		/* サービスコール不正使用 */
#define E_NOMEM		(-33)		/* メモリ不足 */
#define E_NOID		(-34)		/* ID番号不足 */
#define E_OBJ		(-41)		/* オブジェクト状態エラー */
#define E_NOEXS		(-42)		/* オブジェクト未生成 */
#define E_QOVR		(-43)		/* キューイングオーバーフロー */
#define E_RLWAI		(-49)		/* 待ち状態の強制解除 */
#define E_TMOUT		(-50)		/* ポーリング失敗またはタイムアウト */
#define E_DLT		(-51)		/* 待ちオブジェクトの削除 */
#define E_CLS		(-52)		/* 待ちオブジェクトの状態変化 */
#define E_WBLK		(-57)		/* ノンブロッキング受付け */
#define E_BOVR		(-58)		/* バッファオーバーフロー */

/*
 *  オブジェクト属性
 */
#define TA_NULL		0U			/* オブジェクト属性を指定しない */

/*
 *  タイムアウト指定
 */
#define TMO_POL		0			/* ポーリング */
#define TMO_FEVR	(-1)		/* 永久待ち */
#define TMO_NBLK	(-2)		/* ノンブロッキング */

/*
 *  エラーコード生成・分解マクロ
 *
 *  以下のマクロ定義は，符号付き整数が2の補数で表現されており，右シフト
 *  演算子（>>）が算術シフトされることを仮定している．そうでない開発環
 *  境では，target_stddef.hでこれらの定義を上書きしなければならない．
 *
 *  MERCDマクロの定義は，メインエラーコードが負であることを仮定している．
 *  そうでない場合，2つの定義が一致しなくなる．
 */
#ifndef ERCD
#define ERCD(mercd, sercd) \
				((ER)((((uint_t) sercd) << 8) | (((uint_t) mercd) & 0xffU)))
#endif /* ERCD */

#ifndef MERCD
#ifdef INT8_MAX
#define MERCD(ercd)		((ER)((int8_t)(ercd)))
#else /* INT8_MAX */
#define MERCD(ercd)		((ER)(((uint_t) ercd) | ~0xffU))
#endif /* INT8_MAX */
#endif /* MERCD */

#ifndef SERCD
#define SERCD(ercd)		((ER)((ercd) >> 8))
#endif /* SERCD */

/*
 *  型に関する情報を取り出すためのマクロの定義
 */
#ifndef offsetof
#define	offsetof(structure, field)	((uintptr_t) &(((structure *) 0)->field))
#endif /* offsetof */

#ifndef alignof
#define alignof(type)	offsetof(struct { char field1; type field2; }, field2)
#endif /* alignof */

/*
 *  アラインメントチェックマクロ
 */
#ifndef ALIGN_TYPE
#define ALIGN_TYPE(addr, type) \
						((((uintptr_t)(addr)) & (alignof(type) - 1)) == 0U)
#endif /* ALIGN_TYPE */

/*
 *  assertマクロの定義
 */
#undef assert
#ifndef NDEBUG
#define assert(exp)		((void)((exp) ? 0 : (TOPPERS_assert_fail(#exp, \
							__FILE__, __LINE__), TOPPERS_assert_abort(), 0)))
#else /* NDEBUG */
#define assert(exp)		((void) 0)
#endif /* NDEBUG */

#endif /* UNUSE_TECS_DEF */

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_T_STDDEF_H */
