#ifndef ZLAC8015D_H
#define ZLAC8015D_H

#include "register_addresses.h"
#include <cstdint>
#include "SignalCommunicator.h"

class ZLAC8015D {
public:
    ZLAC8015D(uint8_t deviceAddress);

    // 設置速度模式
    void setSpeedMode();

    // 啟動馬達
    void enableMotor();

    // 停止馬達
    void stopMotor();

    // 設置同步目標速度
    void setSyncTargetSpeed(int speedRPM);


    void setLeftRightSpeed(int leftSpeedRPM, int rightSpeedRPM);

    int readLeftMotorEncoder();

    int readRightMotorEncoder();

    vector<int> readLeftRightMotorSpeed();

    vector<int> readLeftRightMotorCurrent();

    vector<int> readFaultCode();

    vector<int> readLeftRightMotorTemperature();

    // 清除故障
    void clearFault();

    // 緊急停止
    void emergencyStop();

private:
    uint8_t deviceAddress;
    SignalCommunicator RS485Communicator;
};

#endif // ZLAC8015D_H
