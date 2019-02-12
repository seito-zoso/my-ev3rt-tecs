/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tSpeaker_template.c => src/tSpeaker.c
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * #[</PREAMBLE>]# */

/* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
#include "tSpeaker_tecsgen.h"
#include "ev3api.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* �������ؿ� #_TEPF_# */
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
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
