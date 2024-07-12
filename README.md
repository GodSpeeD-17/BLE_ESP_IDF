# Bluetooth Low Energy uisng ESP-IDF (BLE_ESP_IDF)

## To Do: 
### ***Write a code for the Development Board (ESP32 or Arduino board with bluetooth on it) that you choose to broadcast bluetooth services. (not a beacon)***

## Services to broadcast:
1. Temperature Measurement
2. Humidity

_(Either interface the sensor with the development board or just write a function that mimic the sensor behaviour in code)_

## Details about service to broadcast over bluetooth
  - Service UUID: 00000002-0000-0000-FDFD-FDFDFDFDFDFD
  - Characteristics:
     - Temperature Measurement
     - Humidity

## Approach:
  - Board Used: ESP-32 Devkit
  - Used Framework: ESP-IDF (Espressif IoT Development Framework)
  - Temperature units: °C
  - Humidity units: %
  - Used demo functions in order to create different instaneous values for temperature and humidity
  - Used the concepts of components to ease the overall process
  - Created components for:
    - bluetooth (consists functions that deal with Bluetooth Low Energy (BLE))
    - humidity (consists function for generating random values within specified range)
    - temperature (consists function for generating random values within specified range)
  - main.c file consists the main entry point for the application (with infinite loop)
  - After every specified duration of time, constantly update the temperature and humidity values
  - After updation of values, calls the function specified in bluetooth component to update the value and notify the client  

## Screenshots:
1. Code compiled and uploaded successfully
![Code Compiled and Uploaded successfully](https://github.com/user-attachments/assets/8a8cccaa-d5ec-45ea-a8ec-2e5005f6ed61)

2. BLE Advertisement Started
![BLE Advertisement Phase](https://github.com/user-attachments/assets/c82f458c-9e12-4310-8175-169ad77e98b3)

3.  
