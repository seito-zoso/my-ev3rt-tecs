/*
 * Motor.cpp
 *
 *  Created on: Oct 10, 2013
 *      Author: liyixiao
 */

#include "Motor.hpp"

extern "C" {
#include "d_pwm.h"
}

namespace EV3 {

Motor::Motor(MotorPort port, MotorType type) : _port(port) {
    assert(port >= PortA && port < TNUM_MOTOR);
    assert(type == MEDIUM_MOTOR || type == LARGE_MOTOR);
    assert(ev3->_motors[port] == NULL);

    ev3->_motors[port] = this;

    if (type == MEDIUM_MOTOR)
        _dev_type = TYPE_MINITACHO;
    else
        _dev_type = TYPE_TACHO;

    /*
     * Set Motor Type
     */
    char buf[TNUM_MOTOR + 1];
    buf[0] = opOUTPUT_SET_TYPE;
    for (int i = PortA; i < TNUM_MOTOR; ++i)
        buf[i + 1] =
                (ev3->_motors[i] == NULL) ? TYPE_NONE : ev3->_motors[i]->_dev_type;
    pwm_dev1_write(NULL, buf, sizeof(buf), NULL);

    /*
     * Set initial state to IDLE
     */
    buf[0] = opOUTPUT_STOP;
    buf[1] = 1 << port;
    buf[2] = 0;
    pwm_dev1_write(NULL, buf, sizeof(buf), NULL);
}

void Motor::setSpeed(int speed) {
    assert(speed >= -100 && speed <= 100);

    /*
     * Set speed and start
     */
    char buf[3];
    buf[0] = opOUTPUT_SPEED;
    buf[1] = 1 << _port;
    buf[2] = speed;
    pwm_dev1_write(NULL, buf, sizeof(buf), NULL);
    buf[0] = opOUTPUT_START;
    buf[1] = 1 << _port;
    pwm_dev1_write(NULL, buf, sizeof(buf), NULL);
}

void Motor::setPower(int power) {
    assert(power >= -100 && power <= 100);

    /*
     * Set speed and start
     */
    char buf[3];
    buf[0] = opOUTPUT_POWER;
    buf[1] = 1 << _port;
    buf[2] = power;
    pwm_dev1_write(NULL, buf, sizeof(buf), NULL);
    buf[0] = opOUTPUT_START;
    buf[1] = 1 << _port;
    pwm_dev1_write(NULL, buf, sizeof(buf), NULL);
}

int Motor::getSpeed() {
    return pwm_dev2_mmap[_port].Speed;
}

void Motor::brake(bool floating) {
    char buf[3];
    buf[0] = opOUTPUT_STOP;
    buf[1] = 1 << _port;
    buf[2] = !floating;
    pwm_dev1_write(NULL, buf, sizeof(buf), NULL);
}

void Motor::rotate(int degrees, uint32_t speed_abs, bool blocking) {
    STEPSPEED ss;
    ss.Cmd = opOUTPUT_STEP_SPEED;
    ss.Speed = speed_abs * (degrees < 0 ? -1 : 1);
    ss.Step1 = 0;         // Up to Speed
    ss.Step2 = (degrees < 0 ? -degrees : degrees);   // Keep Speed
    ss.Step3 = 0;         // Down to Speed
    ss.Brake = true;
    ss.Nos = 1 << _port;
    pwm_dev1_write(NULL, (const char*) &ss, sizeof(ss), NULL);
    if (blocking)
        while (*MotorReadyStatusPtr & (1 << _port));
}

void Motor::syncByTime(Motor* mtA, Motor* mtB, uint32_t time, int speed, bool blocking) {
    TIMESYNC ts;
//    DATA8   Cmd;
//    DATA8   Nos;
//    DATA8   Speed;
//    DATA16  Turn;
//    DATA32  Time;
//    DATA8   Brake;
    ts.Cmd = opOUTPUT_TIME_SYNC;
    ts.Nos = (1 << mtA->_port) | (1 << mtB->_port);
    ts.Speed = speed;
    ts.Turn = 0;
    ts.Time = time;
    ts.Brake = true;
    pwm_dev1_write(NULL, (const char*) &ts, sizeof(ts), NULL);
    if (blocking)
        while (*MotorReadyStatusPtr & (1 << mtA->_port));
}

} /* namespace EV3 */
