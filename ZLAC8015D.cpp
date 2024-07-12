#include "ZLAC8015D.h"
#include <iostream>  // �Ҧp�A�ھڻݭn�]�t��L���Y��
#include "register_addresses.h"
#include <cstdint>
#include "SignalCommunicator.h"
#include <vector>

using namespace std;

ZLAC8015D::ZLAC8015D(uint8_t deviceAddress=0x01) {
 this->deviceAddress=deviceAddress;
 //TODO

}

void ZLAC8015D::setSpeedMode() {
    RS485Communicator.sendSingleRegisterCommand(deviceAddress,
                                                REG_OPERATION_MODE,
                                                0x003,false);
    // ��@�]�m�t�׼Ҧ����禡��

}

void ZLAC8015D::enableMotor() {
    // ��@�ҥΰ��F���禡��
    RS485Communicator.sendSingleRegisterCommand(deviceAddress,
                                                REG_CONTROL_WORD,
                                                0x008,false);
}

void ZLAC8015D::setSyncTargetSpeed(int speedRPM) {
    // ��@�]�m�P�B�ؼгt�ת��禡��
    RS485Communicator.sendMultiRegisterCommand(deviceAddress,
                                                REG_LEFT_TARGET_SPEED,
                                                0x002,speedRPM,speedRPM,true);
}

void ZLAC8015D::setLeftRightSpeed(int leftSpeedRPM, int rightSpeedRPM) {
    // ��@�]�m���k���t�ת��禡��
        RS485Communicator.sendMultiRegisterCommand(deviceAddress,

                                                REG_LEFT_TARGET_SPEED,
                                                0x002,leftSpeedRPM,rightSpeedRPM,true);
}

void ZLAC8015D::stopMotor() {
    // ��@����F���禡��
        RS485Communicator.sendMultiRegisterCommand(deviceAddress,
                                                REG_LEFT_TARGET_SPEED,
                                                0x002,0,0,true);
}


void ZLAC8015D::clearFault() {
    // ��@�M���G�٪��禡��
    RS485Communicator.sendSingleRegisterCommand(deviceAddress,
                                                REG_CONTROL_WORD,
                                                0x006,false);
}

int ZLAC8015D::readLeftMotorEncoder() {
    // ��@Ū�������F�s�X�����禡��A�ê�^�s�X����
        vector<int> result= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_ACTUAL_POSITION_FEEDBACK_LEFT_HIGH,
                                                0x002);

    return 0;  // �d�ҡA�ھڨ����޿�ק�
}

int ZLAC8015D::readRightMotorEncoder() {
    // ��@Ū���k���F�s�X�����禡��A�ê�^�s�X����
    vector<int> result= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_ACTUAL_POSITION_FEEDBACK_RIGHT_HIGH,
                                                0x002);
    return 0;  // �d�ҡA�ھڨ����޿�ק�
}

vector<int> ZLAC8015D::readLeftRightMotorSpeed() {
    vector<int> data= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_ACTUAL_POSITION_FEEDBACK_RIGHT_HIGH,
                                                0x002);
    vector<int>  result;
    // ��@Ū�����k���F�t�ת��禡��A�ê�^�t�׭�
    return result;  // �d�ҡA�ھڨ����޿�ק�
}

vector<int> ZLAC8015D::readLeftRightMotorCurrent() {
     vector<int> data= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_REAL_TIME_TORQUE_FEEDBACK_LEFT,
                                                0x002);
    // ��@Ū�����k���F�q�y���禡��A�ê�^�q�y��
     vector<int>  result;
    return result; // �d�ҡA�ھڨ����޿�ק�
}

vector<int> ZLAC8015D::readFaultCode() {
    // ��@Ū���G�٥N�X���禡��A�ê�^�G�٥N�X
    vector<int> data= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_LAST_FAULT_CODE_LEFT,
                                                0x002);
    vector<int>  result;
    return result;  // �d�ҡA�ھڨ����޿�ק�
}

vector<int> ZLAC8015D::readLeftRightMotorTemperature() {
    // ��@Ū�����k���F�ūת��禡��A�ê�^�ū׭�
    vector<int> data= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_MOTOR_TEMPERATURE,
                                                0x001);
    vector<int> result;                                            
    return result;  // �d�ҡA�ھڨ����޿�ק�
}

void ZLAC8015D::emergencyStop() {
       RS485Communicator.sendSingleRegisterCommand(deviceAddress,
                                                REG_CONTROL_WORD,
                                                0x005,false);
}
