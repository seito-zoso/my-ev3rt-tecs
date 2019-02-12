/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tLCD_template.c => src/tLCD.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * currentFont      lcdfont_t        VAR_currentFont
 *
 * 呼び口関数 #_TCPF_#
 * call port: cButton signature: sButton context:task
 *   bool_t         cButton_isPressed( button_t button );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tLCD_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

void ev3rt_console_set_visibility(bool_t visible);
void lcd_console_send_character(char c);
void lcd_clear();
lcdfont_t current_font;
int32_t default_menu_font_width;
int32_t default_menu_font_height;
#define MENU_FONT (EV3_FONT_MEDIUM)
#define MENU_FONT_WIDTH (default_menu_font_width)
#define MENU_FONT_HEIGHT (default_menu_font_height)


/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eLCD
 * entry port: eLCD
 * signature:  sLCD
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eLCD_setFont
 * name:         eLCD_setFont
 * global_name:  tLCD_eLCD_setFont
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eLCD_setFont(CELLIDX idx, lcdfont_t font)
{
	// CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		// p_cellcb = GET_CELLCB(idx);
	}
	//VAR_currentFont = font;
	current_font = font;
	return ev3_lcd_set_font(font);
}

/* #[<ENTRY_FUNC>]# eLCD_getFontSize
 * name:         eLCD_getFontSize
 * global_name:  tLCD_eLCD_getFontSize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eLCD_getFontSize(CELLIDX idx, lcdfont_t font, int32_t* p_width, int32_t* p_height)
{
	return ev3_font_get_size(font, p_width, p_height);
}

/* #[<ENTRY_FUNC>]# eLCD_drawString
 * name:         eLCD_drawString
 * global_name:  tLCD_eLCD_drawString
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eLCD_drawString(CELLIDX idx, const char* str, int32_t x, int32_t y)
{
	int32_t font_width, font_height;
	ev3_font_get_size(current_font, &font_width, &font_height);
	ev3rt_console_set_visibility(false);
	return ev3_lcd_draw_string(str, x * font_width, y * font_height);
}
/* #[<ENTRY_FUNC>]# eLCD_fillRect
 * name:         eLCD_fillRect
 * global_name:  tLCD_eLCD_fillRect
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eLCD_fillRect(CELLIDX idx, int32_t x, int32_t y, int32_t w, int32_t h, lcdcolor_t color)
{
	ev3rt_console_set_visibility(false);
	return ev3_lcd_fill_rect(x, y, w, h, color);
}
/* #[<ENTRY_FUNC>]# eLCD_drawLine
 * name:         eLCD_drawLine
 * global_name:  tLCD_eLCD_drawLine
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eLCD_drawLine(CELLIDX idx, int32_t x0, int32_t y0, int32_t x1, int32_t y1)
{
	ev3rt_console_set_visibility(false);
	return ev3_lcd_draw_line(x0, y0, x1,  y1);
}

/* #[<ENTRY_FUNC>]# eLCD_print
 * name:         eLCD_print
 * global_name:  tLCD_eLCD_print
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eLCD_print(CELLIDX idx, const char* str)
{
	// CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		// p_cellcb = GET_CELLCB(idx);
	}
	const char *p = str;
	ev3rt_console_set_visibility(true);
	while(*p!='\0') {
		lcd_console_send_character(*p++);
	}
}

/* #[<ENTRY_FUNC>]# eLCD_puts
 * name:         eLCD_puts
 * global_name:  tLCD_eLCD_puts
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eLCD_puts(CELLIDX idx, const char* str)
{
	// CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		// p_cellcb = GET_CELLCB(idx);
	}
	const char *p = str;
	ev3rt_console_set_visibility(true);
	while(*p!='\0') {
		lcd_console_send_character(*p++);
	}
	lcd_console_send_character('\n');
}

/* #[<ENTRY_FUNC>]# eLCD_clear
 * name:         eLCD_clear
 * global_name:  tLCD_eLCD_clear
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eLCD_clear(CELLIDX idx)
{
	// CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		// p_cellcb = GET_CELLCB(idx);
	}
	lcd_clear();
	ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
}


/* #[<ENTRY_FUNC>]# eLCD_showMessageBox
 * name:         eLCD_showMessageBox
 * global_name:  tLCD_eLCD_showMessageBox
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eLCD_showMessageBox(CELLIDX idx, const char* title, const char* msg)
{
	// CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		// p_cellcb = GET_CELLCB(idx);
	}
	int offset_x = 0, offset_y = 0;
	ev3rt_console_set_visibility(false);

	ev3_font_get_size(EV3_FONT_SMALL, &default_menu_font_width, &default_menu_font_height);
	ev3_lcd_set_font(EV3_FONT_SMALL);

	// Clear menu area
	ev3_lcd_fill_rect(offset_x, offset_y, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);

	// Draw title
	if (EV3_LCD_WIDTH - offset_x > strlen(title) * MENU_FONT_WIDTH)
		offset_x += (EV3_LCD_WIDTH - offset_x - strlen(title) * MENU_FONT_WIDTH) / 2;
	ev3_lcd_draw_string(title, offset_x, offset_y);
	ev3_lcd_draw_line(0, offset_y + MENU_FONT_HEIGHT - 1, EV3_LCD_WIDTH, offset_y + MENU_FONT_HEIGHT - 1);
	offset_y += MENU_FONT_HEIGHT;

	// Draw message
	//offset_x = MENU_FONT_WIDTH, offset_y += MENU_FONT_HEIGHT;
	offset_x = MENU_FONT_WIDTH;
	while (*msg != '\0') {
		if (*msg == '\n' || offset_x + MENU_FONT_WIDTH > EV3_LCD_WIDTH) { // newline
			offset_x = MENU_FONT_WIDTH;
			offset_y += MENU_FONT_HEIGHT;
		}
		if (*msg != '\n') {
			char buf[2] = { *msg, '\0' };
			ev3_lcd_draw_string(buf, offset_x, offset_y);
			offset_x += MENU_FONT_WIDTH;
		}
		msg++;
	}

	// Draw & wait 'OK' button
	ev3_lcd_draw_string("--- OK ---", (EV3_LCD_WIDTH - strlen("--- OK ---") * MENU_FONT_WIDTH) / 2, EV3_LCD_HEIGHT - MENU_FONT_HEIGHT - 5);
	while(!ev3_button_is_pressed(ENTER_BUTTON));
	while(ev3_button_is_pressed(ENTER_BUTTON));
	// Clear menu area
	ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
	ev3_lcd_set_font(current_font);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
