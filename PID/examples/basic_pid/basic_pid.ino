#include "pid2.h"

pid2 myPid;
void setup()
{
    Serial.begin(115200);
    Serial.println("initialize pid parameter");
    myPid.setParam(1.2, 0.f, 0.f); // set parameter .setParam(KP, KI, KD);
    myPid.SV(0); // set your set value
}

void loop()
{   
    //use timer for optimal calculation
    float input = 0.4;
    Serial.println(myPid.calc(input));
}