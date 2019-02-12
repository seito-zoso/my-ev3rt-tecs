/*
 * EV3.hpp
 *
 *  Created on: Oct 9, 2013
 *      Author: liyixiao
 */

#ifndef EV3_HPP_
#define EV3_HPP_

#include <t_stddef.h>
#include <kernel.h>

namespace EV3 {

class Motor;
class Sensor;

/*
 *  Definition of LED Colors
 */
#define LED_OFF     (0)
#define LED_RED     (0x1)
#define LED_GREEN   (0x2)
#define LED_ORANGE  (LED_RED | LED_GREEN)

enum Button {
    LEFT_BUTTON = 0,
    RIGHT_BUTTON,
    UP_BUTTON,
    DOWN_BUTTON,
    ENTER_BUTTON,
    BACK_BUTTON,
    TNUM_BUTTON
};

class EV3 {
public:
    EV3();
    void setLED(uint32_t color);
    void setOnButtonClicked(Button button, ISR handler, intptr_t exinf);

private:
    Sensor* _sensors[TNUM_SENSOR];
    Motor* _motors[TNUM_MOTOR];

    friend class Sensor;
    friend class Motor;
};

extern EV3 *ev3;

}

#endif /* EV3_HPP_ */
