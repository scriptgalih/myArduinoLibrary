#include "pid2.h"

float pid2::showKP()
{
    return _kp;
}

float pid2::showKI()
{
    return _ki;
}

float pid2::showKD()
{
    return _kd;
}

void pid2::SV(float sv)
{
    _sv = sv;
}

float pid2::calc(float input)
{
    _error = _sv - input;
    _Proportional = _error * _kp;
    // _Integral = (_integral_e * _ki);
    _integral_e = (_integral_e + (_error * _ki));
    _Derivative = (_error - _last_e) * _kd;
    _last_e = _error;
    // _integral_e += _error;
    _PID = _Proportional + _integral_e + _Derivative;

    if (_limit_status)
    {
        if (_integral_e >= _limit_PID)
        {
            _integral_e = _limit_PID;
        }
        else if (_integral_e <= -(_limit_PID))
        {
            _integral_e = -(_limit_PID);
        }

        if (_PID >= _limit_PID)
        {
            _PID = _limit_PID;
            _integral_e = _last_integral_e;
            // _Proportional = _last_p;
        }
        else if (_PID <= -(_limit_PID))
        {
            _PID = -(_limit_PID);
            _integral_e = _last_integral_e;
            // _Proportional = _last_p;
        }
    }
    _last_integral_e = _integral_e;
    _last_p = _Proportional;
    return _PID;
}

void pid2::setLimit(float limit)
{
    _limit_status = true;
    _limit_PID = limit;
}
void pid2::setParam(float kp, float ki, float kd)
{
    _kp = kp;
    _ki = ki;
    _kd = kd;
}

void pid2::setKP(float kp)
{
    _kp = kp;
}

void pid2::setKI(float ki)
{
    _ki = ki;
}

void pid2::setKD(float kd)
{
    _kd = kd;
}

void pid2::resetOutput()
{
    _PID = 0;
    _integral_e = 0;
    _last_e = 0;
}

float pid2::showP()
{
    return _Proportional;
}

float pid2::showI()
{
    return _integral_e;
}

float pid2::showD()
{
    return _Derivative;
}

float pid2::showPID()
{
    return _pid;
}
