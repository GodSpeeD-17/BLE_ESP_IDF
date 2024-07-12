# Bluetooth Low Energy uisng ESP-IDF (BLE_ESP_IDF)

## To Do: 
  - ### ***Write a code for the Development Board (ESP32 or Arduino board with bluetooth on it) that you choose to broadcast bluetooth services. (not a beacon)***
  - ### ***Bonus Credit: Transfer WiFi credentials over bluetooth and connect to Wifi. (Use smartphone to send wifi credentials)***

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
  - Could not attempt for extra credit: Transfer WiFi credentials over bluetooth and connect to Wifi. (Use smartphone to send wifi credentials)
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

    - ![Code Compiled and Uploaded successfully](https://github.com/user-attachments/assets/8a8cccaa-d5ec-45ea-a8ec-2e5005f6ed61)

2. BLE Advertisement Started and Connected
   
    - ![BLE Advertisement Phase + Connection Phase](https://github.com/user-attachments/assets/c82f458c-9e12-4310-8175-169ad77e98b3)

3. BLE Data Read Request from remote client
   
    - ![BLE sample data read request from client](https://github.com/user-attachments/assets/c5bc4776-3636-46d2-9b13-9d8ba5993568)

4. BLE Data Received from ESP-32 and displayed on nRF Connect App

    - Console:

        - ![Console display during request](https://github.com/user-attachments/assets/98ee7c46-c333-42a2-b4c9-29f1ff26b649)
    
    - nRF Connect Mobile App:

        - ![Temperature & Humidity Mobile Screenshot](https://github.com/user-attachments/assets/5ad80667-252a-4004-8631-6401ace8bbe7)

5. Ability to still function even after disconenction of remote device

  - Disconenction:
    - ![Disconnection event screenshot](https://github.com/user-attachments/assets/58973849-273e-40cb-b160-25c5b6c0a7bb)

  - Reconnection:
    -  ![Connection after disconenction](https://github.com/user-attachments/assets/d82d9ec7-65c8-45bc-b1e8-f94f07185494)




