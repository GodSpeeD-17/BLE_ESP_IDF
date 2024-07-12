# BLE_ESP_IDF

# Problem Statement:-

## To Do: 
### **Write a code for the Development Board (ESP32 or Arduino board with bluetooth on it) that you choose to broadcast bluetooth services. (not a beacon)**

## Services to broadcast:
1. Temperature Measurement
2. Humidity

(Either interface the sensor with the development board or just write a function that mimic the sensor behaviour in code)

## Details about service to broadcast over bluetooth
  - Service UUID: 00000002-0000-0000-FDFD-FDFDFDFDFDFD
  - Characteristics:
     - Temperature Measurement
     - Humidity

## Used Framework: ESP-IDF (Espressif IoT Development Framework)

## Approach:
  - Created components for:
    - bluetooth (consists functions that deal with Bluetooth Low Energy (BLE))
    - humidity (consists function for generating random values within specified range)
    - temperature (consists function for generating random values within specified range)
  - main.c file consists the main entry point for the application (with infinite loop)
  - After every specified duration of time, constantly update the temperature and humidity values
  - After updation of values, calls the function specified in bluetooth component to update the value and notify the client  
