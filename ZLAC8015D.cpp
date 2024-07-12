#include "ZLAC8015D.h"
#include <iostream>  // 例如，根據需要包含其他標頭檔
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
    // 實作設置速度模式的函式體

}

void ZLAC8015D::enableMotor() {
    // 實作啟用馬達的函式體
    RS485Communicator.sendSingleRegisterCommand(deviceAddress,
                                                REG_CONTROL_WORD,
                                                0x008,false);
}

void ZLAC8015D::setSyncTargetSpeed(int speedRPM) {
    // 實作設置同步目標速度的函式體
    RS485Communicator.sendMultiRegisterCommand(deviceAddress,
                                                REG_LEFT_TARGET_SPEED,
                                                0x002,speedRPM,speedRPM,true);
}

void ZLAC8015D::setLeftRightSpeed(int leftSpeedRPM, int rightSpeedRPM) {
    // 實作設置左右輪速度的函式體
        RS485Communicator.sendMultiRegisterCommand(deviceAddress,

                                                REG_LEFT_TARGET_SPEED,
                                                0x002,leftSpeedRPM,rightSpeedRPM,true);
}

void ZLAC8015D::stopMotor() {
    // 實作停止馬達的函式體
        RS485Communicator.sendMultiRegisterCommand(deviceAddress,
                                                REG_LEFT_TARGET_SPEED,
                                                0x002,0,0,true);
}


void ZLAC8015D::clearFault() {
    // 實作清除故障的函式體
    RS485Communicator.sendSingleRegisterCommand(deviceAddress,
                                                REG_CONTROL_WORD,
                                                0x006,false);
}

int ZLAC8015D::readLeftMotorEncoder() {
    // 實作讀取左馬達編碼器的函式體，並返回編碼器值
        vector<int> result= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_ACTUAL_POSITION_FEEDBACK_LEFT_HIGH,
                                                0x002);

    return 0;  // 範例，根據具體邏輯修改
}

int ZLAC8015D::readRightMotorEncoder() {
    // 實作讀取右馬達編碼器的函式體，並返回編碼器值
    vector<int> result= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_ACTUAL_POSITION_FEEDBACK_RIGHT_HIGH,
                                                0x002);
    return 0;  // 範例，根據具體邏輯修改
}

vector<int> ZLAC8015D::readLeftRightMotorSpeed() {
    vector<int> data= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_ACTUAL_POSITION_FEEDBACK_RIGHT_HIGH,
                                                0x002);
    vector<int>  result;
    // 實作讀取左右馬達速度的函式體，並返回速度值
    return result;  // 範例，根據具體邏輯修改
}

vector<int> ZLAC8015D::readLeftRightMotorCurrent() {
     vector<int> data= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_REAL_TIME_TORQUE_FEEDBACK_LEFT,
                                                0x002);
    // 實作讀取左右馬達電流的函式體，並返回電流值
     vector<int>  result;
    return result; // 範例，根據具體邏輯修改
}

vector<int> ZLAC8015D::readFaultCode() {
    // 實作讀取故障代碼的函式體，並返回故障代碼
    vector<int> data= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_LAST_FAULT_CODE_LEFT,
                                                0x002);
    vector<int>  result;
    return result;  // 範例，根據具體邏輯修改
}

vector<int> ZLAC8015D::readLeftRightMotorTemperature() {
    // 實作讀取左右馬達溫度的函式體，並返回溫度值
    vector<int> data= RS485Communicator.receiveMultiRegisterCommand(deviceAddress,
                                                REG_MOTOR_TEMPERATURE,
                                                0x001);
    vector<int> result;                                            
    return result;  // 範例，根據具體邏輯修改
}

void ZLAC8015D::emergencyStop() {
       RS485Communicator.sendSingleRegisterCommand(deviceAddress,
                                                REG_CONTROL_WORD,
                                                0x005,false);
}
