#ifndef ZLAC8015D_H
#define ZLAC8015D_H

#include "register_addresses.h"
#include <cstdint>
#include "SignalCommunicator.h"

class ZLAC8015D {
public:
    ZLAC8015D(uint8_t deviceAddress);

    // �]�m�t�׼Ҧ�
    void setSpeedMode();

    // �Ұʰ��F
    void enableMotor();

    // ����F
    void stopMotor();

    // �]�m�P�B�ؼгt��
    void setSyncTargetSpeed(int speedRPM);


    void setLeftRightSpeed(int leftSpeedRPM, int rightSpeedRPM);

    int readLeftMotorEncoder();

    int readRightMotorEncoder();

    vector<int> readLeftRightMotorSpeed();

    vector<int> readLeftRightMotorCurrent();

    vector<int> readFaultCode();

    vector<int> readLeftRightMotorTemperature();

    // �M���G��
    void clearFault();

    // ��氱��
    void emergencyStop();

private:
    uint8_t deviceAddress;
    SignalCommunicator RS485Communicator;
};

#endif // ZLAC8015D_H
