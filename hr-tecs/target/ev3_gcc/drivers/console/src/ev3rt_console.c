/**
 * All previous output will be cleared when buffer is full, for performance and simplicity.
 */

#include "platform_interface_layer.h"

/**
 * Console font
 */

#define CONSOLE_FONT 	    (global_brick_info.font_w6h8)
#define CONSOLE_FONT_WIDTH  (6)
#define CONSOLE_FONT_HEIGHT (8)
#define CONSOLE_LINE_WIDTH  (178 /* EV3_LCD_WIDTH */ / CONSOLE_FONT_WIDTH) // Number of characters in a line

/**
 * Console log buffer
 */

#define LOG_LINE_WIDTH   (178 /* EV3_LCD_WIDTH */ / CONSOLE_FONT_WIDTH) // Number of characters in a line
#define LOG_MAX_LINES    (1024 * 16)
#define LOG_SCREEN_LINES (128 /* EV3_LCD_HEIGHT */ / CONSOLE_FONT_HEIGHT)

static uint8_t  log_buffer[LOG_MAX_LINES][LOG_LINE_WIDTH];
static int32_t  log_first_line;
static int32_t  log_current_line;       // Current line for output
static int32_t  log_current_column;     // Current column for output [Line end: log_current_column == LOG_LINE_WIDTH]
static uint8_t* log_output_ptr;         // Current pointer for output
static bool_t   log_scroll_mode;        // True: scroll back now, False: update on new characters
static bool_t   log_scroll_line;        // First line in scroll mode

// Must be called with EV3RT_CONSOLE_MTX
static void log_put_char(char c) {
    if (log_current_column == LOG_LINE_WIDTH) { // newline
        // Update line and column
        log_current_column = 0;
        if (++log_current_line >= LOG_MAX_LINES) {
            log_current_line = 0;
            log_output_ptr = log_buffer;
        }
        if (log_current_line == log_first_line) {
            if (++log_first_line >= LOG_MAX_LINES) {
                log_first_line = 0;
            }
        }

        // Roll screen
        if (console_visible && !log_scroll_mode) {
            // TODO: draw
        }
    } else {
        log_current_column++;
    }
    *log_output_ptr++  = c;

    if (console_visible && !log_scroll_mode) {
        // TODO: draw char
    }
}


/**
 * Console status (must be protected by mutex EV3RT_CONSOLE_MTX)
 */
static bool_t console_visible;

/**
 * Console screen buffer
 */

#define SCREEN_MAX_LINES (128 /* EV3_LCD_HEIGHT */ / CONSOLE_FONT_HEIGHT)

static uint8_t screen_buffer[SCREEN_MAX_LINES][CONSOLE_LINE_WIDTH];
static int32_t screen_first_line; // Index of first line to display

static void ev3rt_console_refresh() {
	for (int i = 0; i <= SCREEN_MAX_LINES; ++i) {
		for (int j = 0; j < CONSOLE_LINE_WIDTH; ++j) {
			bitmap_t *char_bitmap = utf8_char_bitmap(*(screen_buffer + i * CONSOLE_LINE_WIDTH + j), CONSOLE_FONT);
			if (char_bitmap == NULL) char_bitmap = utf8_char_bitmap('?', CONSOLE_FONT);
			bitmap_bitblt(char_bitmap, 0, 0, &lcd_console_fb, char_bitmap->width * j, char_bitmap->height * i, char_bitmap->width, char_bitmap->height, ROP_COPY);
		}
	}
}

#if 0
void lcd_console_update() {
	// TODO: mutex on current_line updated
	// Auto scroll mode (for test)
	int32_t first_line = current_line - 6;
	if (first_line < 0) first_line = 0;
	for (int i = first_line; i <= current_line; ++i) {
		for (int j = 0; j < linewidth; ++j) {
			bitmap_t *char_bitmap = utf8_char_bitmap(*(buffer + i * linewidth + j), &font);
			if (char_bitmap == NULL) char_bitmap = utf8_char_bitmap('?', &font);
			bitmap_bitblt(char_bitmap, 0, 0, &lcd_console_fb, char_bitmap->width * j, char_bitmap->height * (first_line + 6 - current_line), char_bitmap->width, char_bitmap->height, ROP_COPY);
		}
	}
}
#endif

#define BUF_MAX_SZ (128 * 1024)

static font_t   font;
static int32_t  linewidth;          // Number of characters in a line
static int32_t  max_lines;          // Maximum number of lines in the buffer
static int32_t  current_line;       // Current line for output
static int32_t  current_column;     // Current column for output
static uint8_t  buffer[BUF_MAX_SZ];
static uint8_t* buffer_ptr;         // Buffer pointer for output => buffer + cur_line * linewidth + current_column

void initialize_lcd_console() {
	font           = *global_brick_info.font_w6h8;
	linewidth      = lcd_console_fb.width / font.width;
	max_lines      = sizeof(buffer) / linewidth;
	current_line   = 0;
	current_column = 0;
	buffer_ptr     = buffer;
}

/**
 * Interface for CSL
 */

static void ev3rt_console_set_visibility(bool_t visible) {
	if (loc_mtx(EV3RT_CONSOLE_MTX) != E_OK) {
		assert(false);
		return;
	}

	if (console_visible != visible) { // visibility changed
		console_visible = visible;
		if (console_visible) {
			ev3rt_console_refresh();
			on_display_fb = ev3rt_console_fb;
		} else {
		    on_display_fb = lcd_screen_fb;
		}
	}

	if (unl_mtx(EV3RT_CONSOLE_MTX)) {
		assert(false);
		return;
	}
}

void lcd_console_send_character(char c) {
    if (loc_mtx(EV3RT_CONSOLE_MTX) != E_OK) {
        assert(false);
        return;
    }

    if (c != '\n') {
        log_put_char(c);
    } else {
        for (int i = LOG_LINE_WIDTH - current_column; i > 0; --i)
            log_put_char(' ');
    }

    if (unl_mtx(EV3RT_CONSOLE_MTX)) {
        assert(false);
        return;
    }
}

void ev3rt_console_log_scroll_up() {
    if (loc_mtx(EV3RT_CONSOLE_MTX) != E_OK) {
        assert(false);
        return;
    }

    if (((log_first_line + LOG_SCREEN_LINES) % LOG_MAX_LINES) >= log_current_line) { // Enough lines for scrolling?
        if (!log_scroll_mode) { // Enter scroll mode
            log_scroll_line == log_current_line - LOG_SCREEN_LINES;
        }
    }


    if (unl_mtx(EV3RT_CONSOLE_MTX)) {
        assert(false);
        return;
    }
}

/**
 * EV3RT console button task
 */
void console_button_task(intptr_t unused) {
	ER ercd;
	FLGPTN flgptn;
	while((ercd = wai_flg(console_button_flag, (1 << TNUM_BRICK_BUTTON) - 1, TWF_ORW, &flgptn)) == E_OK) {
		for (int i = 0; i < TNUM_BRICK_BUTTON; ++i)
			if (flgptn & (1 << i)) {
				switch(i) {
				case BRICK_BUTTON_BACK: // toggle
					ev3rt_console_set_visibility(!console_visible);
					break;
				}
			}
	}
	syslog(LOG_ERROR, "%s(): Fatal error, ercd: %d", __FUNCTION__, ercd);
}

