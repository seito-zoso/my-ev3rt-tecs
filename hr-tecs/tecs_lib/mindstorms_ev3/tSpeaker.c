/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSpeaker_template.c => src/tSpeaker.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSpeaker_tecsgen.h"
#include "ev3api.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eSpeaker
 * entry port: eSpeaker
 * signature:  sSpeaker
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSpeaker_setVolume
 * name:         eSpeaker_setVolume
 * global_name:  tSpeaker_eSpeaker_setVolume
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSpeaker_setVolume(uint8_t volume)
{
	return  ev3_speaker_set_volume(volume);
}

/* #[<ENTRY_FUNC>]# eSpeaker_playTone
 * name:         eSpeaker_playTone
 * global_name:  tSpeaker_eSpeaker_playTone
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSpeaker_playTone(uint16_t frequency, int32_t duration)
{
	return ev3_speaker_play_tone(frequency, duration);
}

/* #[<ENTRY_FUNC>]# eSpeaker_playFile
 * name:         eSpeaker_playFile
 * global_name:  tSpeaker_eSpeaker_playFile
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSpeaker_playFile(const memfile_t* p_memfile, int32_t duration)
{
	return ev3_speaker_play_file(p_memfile, duration);
}

/* #[<ENTRY_FUNC>]# eSpeaker_stop
 * name:         eSpeaker_stop
 * global_name:  tSpeaker_eSpeaker_stop
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSpeaker_stop()
{
	return ev3_speaker_stop();
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
