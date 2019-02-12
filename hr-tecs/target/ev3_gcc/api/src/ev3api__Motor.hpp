/*
 * Motor.hpp
 *
 *  Created on: Oct 10, 2013
 *      Author: liyixiao
 */

#ifndef MOTOR_HPP_
#define MOTOR_HPP_

#include "EV3.hpp"

namespace EV3 {

class Motor {
public:
    Motor(MotorPort port, MotorType type);

    /*
     * speed: -100 ~ 100
     */
    void setSpeed(int speed);

    int getSpeed();

    void setPower(int power);

    void brake(bool floating = false);

    /*
     * speed_abs: 1 ~ 100
     */
    void rotate(int degrees, uint32_t speed_abs = 50, bool blocking = true);

    static void syncByTime(Motor* mtA, Motor* mtB, uint32_t time, int speed, bool blocking = true);
private:
    MotorPort _port;
    int _dev_type;
};

} /* namespace EV3 */

#endif /* MOTOR_HPP_ */
