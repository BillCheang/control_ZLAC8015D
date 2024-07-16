#ifndef SIGNAL_COMMUNICATOR_H
#define SIGNAL_COMMUNICATOR_H

#include <cstdint>
#include "SignalCommunicator.h"
#include <vector>
class SignalCommunicator {
public:
    // Constructor
    SignalCommunicator();

    // Initialization function
    void init();

    // Function to send single register command
    vector<int8_t> sendSingleRegisterCommand(uint8_t deviceAddress, uint16_t registerAddressStart, int data, bool data_sign);

    // Function to send multi-register command
    vector<int8_t> sendMultiRegisterCommand(uint8_t deviceAddress, uint16_t registerAddressStart, uint16_t registerCount, int data1,int data2, bool data_sign);
   
    // Function to receive multi-register command
    vector<int> receiveMultiRegisterCommand(uint8_t deviceAddress, uint16_t registerAddressStart, uint16_t registerCount);

private:
    // UART handle or pointer, adjust type as per your actual use case
        // Modbus¥\¯à½X
    static const uint8_t READ_MULTIPLE_REGISTERS = 0x03;
    static const uint8_t WRITE_SINGLE_REGISTER = 0x06;
    static const uint8_t WRITE_MULTIPLE_REGISTERS = 0x10;
};

#endif // SIGNAL_COMMUNICATOR_H
