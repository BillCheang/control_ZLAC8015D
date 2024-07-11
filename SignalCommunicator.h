#ifndef SIGNALCOMMUNICATOR_H
#define SIGNALCOMMUNICATOR_H

//#include "stm32f1xx_hal.h"

class SignalCommunicator {
public:
    int *huart;
    // Constructor
    SignalCommunicator(int *huart);//todo
    
    // Initialization function
    void init();
    
    // Function to send data
    void sendData(int *data, int size);//todo
    
    // Function to receive data
    void receiveData(int *buffer, int size);//todo

};

#endif // SIGNALCOMMUNICATOR_H
