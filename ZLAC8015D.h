#ifndef ZLAC8015D_H
#define ZLAC8015D_H

#include <vector>

class ZLAC8015D {
private:
    void sendCommand(const std::vector<unsigned char>& command);

public:
    void setSpeedMode();
    void enableMotor();
    void setSyncTargetSpeed(int speedRPM);
    void setLeftRightSpeed(int leftSpeedRPM, int rightSpeedRPM);
 

  

    void stopMotor();
    void clearFault();
    int readLeftMotorEncoder();
    int readRightMotorEncoder();
    int readLeftRightMotorSpeed();
    int readLeftRightMotorCurrent();
    int readFaultCode();
    int readLeftRightMotorTemperature();
    void emergencyStop();

};

#endif // ZLAC8015D_H
