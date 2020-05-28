class pid2
{
public:
    float showKP();
    float showKI();
    float showKD();
    float calc(float input);
    void setKP(float kp);
    void setKI(float ki);
    void setKD(float kd);
    void setParam(float kp, float ki, float kd);
    void setLimit(float limit);
    void resetOutput();
    void SV(float sv);

    float showP();
    float showI();
    float showD();
    float showPID();

private:
    float _kp, _ki, _kd;
    float _integral_e, _last_integral_e;
    float _last_e;
    float _error;
    float _max;
    float _pid;
    float _Proportional, _Derivative, _Integral;
    float _last_p;
    bool _limit_status = false;
    float _limit_PID;
    float _PID;
    float _sv;
};