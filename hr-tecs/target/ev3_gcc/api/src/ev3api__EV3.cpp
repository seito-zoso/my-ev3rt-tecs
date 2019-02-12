/*
 * EV3.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: liyixiao
 */

#include "ev3api__EV3.hpp"

#include "am1808.h"
extern "C" {
#include "gpio.h"
}

namespace EV3 {

EV3 *ev3;

static ISR button_clicked_handler[TNUM_BUTTON];
static intptr_t button_exinf[TNUM_BUTTON];
static const int button_pin[TNUM_BUTTON] = {
    [LEFT_BUTTON]   = GP6_6,
    [RIGHT_BUTTON]  = GP7_12,
    [UP_BUTTON]     = GP7_15,
    [DOWN_BUTTON]   = GP7_14,
    [ENTER_BUTTON]  = GP1_13,
    [BACK_BUTTON]   = GP6_10
};
#define BUTTON_WAIT_PRESS (0)
#define BUTTON_WAIT_RELEASE (1)
static int button_status[TNUM_BUTTON];

static void button_irq_handler(intptr_t button) {
    if(button_status[button] == BUTTON_WAIT_PRESS) {
        button_status[button] = BUTTON_WAIT_RELEASE;
        request_gpio_irq(button_pin[button], TRIG_FAL_EDGE, button_irq_handler, button);
    } else {
        if(button_clicked_handler[button] != NULL)
            button_clicked_handler[button](button_exinf[button]);
        button_status[button] = BUTTON_WAIT_PRESS;
        request_gpio_irq(button_pin[button], TRIG_RIS_EDGE, button_irq_handler, button);
    }
}

EV3::EV3() {
    for(int i = 0; i < TNUM_BUTTON; ++i) {
        button_clicked_handler[i] = NULL;
        button_status[i] = BUTTON_WAIT_PRESS;
        request_gpio_irq(button_pin[i], TRIG_RIS_EDGE, button_irq_handler, i);
    }
}

void EV3::setLED(uint32_t color) {
    ev3_set_led(color);
}

void EV3::setOnButtonClicked(Button button, ISR handler, intptr_t exinf) {
    button_exinf[button] = exinf;
    button_clicked_handler[button] = handler;
}

}
