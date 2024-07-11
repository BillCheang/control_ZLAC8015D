#include "SignalCommunicator.h"

// Constructor
SignalCommunicator::SignalCommunicator(int *huart) {
    this->huart = huart;
}

// Initialization function
void SignalCommunicator::init() {
    // Common initialization code for communication
    //HAL_UART_Init(huart);
    
}

// Function to send data
void SignalCommunicator::sendData(int *data, int size) {
    // Common code for sending data
   // HAL_UART_Transmit(huart, data, size, HAL_MAX_DELAY);
    
}

// Function to receive data
void SignalCommunicator::receiveData(int *buffer, int size) {
    // Common code for receiving data
    //HAL_UART_Receive(huart, buffer, size, HAL_MAX_DELAY);
    
    // Protocol specific receiving code

}
