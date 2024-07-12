# Bluetooth Low Energy uisng ESP-IDF (BLE_ESP_IDF)

## To Do: 
  - ### _Write a code for the Development Board (ESP32 or Arduino board with bluetooth on it) that you choose to broadcast bluetooth services. (not a beacon)_
  - ### _Bonus Credit: Transfer WiFi credentials over bluetooth and connect to Wifi. (Use smartphone to send wifi credentials)_

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

      ![Code Compiled and Uploaded successfully](https://github.com/user-attachments/assets/8a8cccaa-d5ec-45ea-a8ec-2e5005f6ed61)

2. BLE Advertisement Started and Connected

      ![BLE Advertisement Phase + Connection Phase](https://github.com/user-attachments/assets/c82f458c-9e12-4310-8175-169ad77e98b3)

3. BLE Data Read Request from remote client

      ![BLE sample data read request from client](https://github.com/user-attachments/assets/c5bc4776-3636-46d2-9b13-9d8ba5993568)

4. BLE Data Received from ESP-32 and displayed on nRF Connect App (Verification)

  - Console:

      ![Console display during request](https://github.com/user-attachments/assets/ddc4076d-25f6-45aa-80db-cfa69b6f9fb3)

    
  - nRF Connect Mobile App:

      ![Temperature & Humidity Mobile Screenshot](https://github.com/user-attachments/assets/d49e477a-f655-4f50-9c39-9e80f89e34f6)


5. Ability to still function even after disconenction of remote device

    - Disconnection:

        ![Disconnection event screenshot](https://github.com/user-attachments/assets/58973849-273e-40cb-b160-25c5b6c0a7bb)

    - Reconnection:

        ![Connection after disconenction](https://github.com/user-attachments/assets/d82d9ec7-65c8-45bc-b1e8-f94f07185494)

6. Reference Log Output:

  - ESP-IDF Terminal:

      C:\Users\Shrey_Coding\Desktop\ESP-IDF\bluetooth_temp_hum>idf.py -p COM5 flash monitor
      Executing action: flash
      Running ninja in directory C:\Users\Shrey_Coding\Desktop\ESP-IDF\bluetooth_temp_hum\build
      Executing "ninja flash"...
      [1/5] cmd.exe /C "cd /D C:\Users\Shrey_Coding\Desktop\ESP-...p/ESP-IDF/bluetooth_temp_hum/build/bluetooth_temp_hum.bin"
      bluetooth_temp_hum.bin binary size 0xb3d70 bytes. Smallest app partition is 0x100000 bytes. 0x4c290 bytes (30%) free.
      [1/1] cmd.exe /C "cd /D C:\Users\Shrey_Coding\Desktop\ESP-...SP-IDF/bluetooth_temp_hum/build/bootloader/bootloader.bin"
      Bootloader binary size 0x6860 bytes. 0x7a0 bytes (7%) free.
      [2/3] cmd.exe /C "cd /D C:\Espressif\frameworks\esp-idf-v5...th_temp_hum.bin 0x8000 partition_table/partition-table.bin
      esptool.py v4.7.0
      Serial port COM5
      Connecting.....
      Chip is ESP32-D0WD-V3 (revision v3.0)
      Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
      Crystal is 40MHz
      MAC: b8:d6:1a:6a:b0:90
      Uploading stub...
      Running stub...
      Stub running...
      Changing baud rate to 460800
      Changed.
      Configuring flash size...
      Flash will be erased from 0x00001000 to 0x00007fff...
      Flash will be erased from 0x00010000 to 0x000c3fff...
      Flash will be erased from 0x00008000 to 0x00008fff...
      Compressed 26720 bytes to 16349...
      Writing at 0x00001000... (100 %)
      Wrote 26720 bytes (16349 compressed) at 0x00001000 in 0.8 seconds (effective 266.6 kbit/s)...
      Hash of data verified.
      Compressed 736624 bytes to 422317...
      Writing at 0x00010000... (3 %)
      Writing at 0x0001f305... (7 %)
      Writing at 0x0002bca3... (11 %)
      Writing at 0x000339b5... (15 %)
      Writing at 0x000395dc... (19 %)
      Writing at 0x0003f328... (23 %)
      Writing at 0x00044db3... (26 %)
      Writing at 0x0004a996... (30 %)
      Writing at 0x000503d8... (34 %)
      Writing at 0x00056dba... (38 %)
      Writing at 0x0005cca2... (42 %)
      Writing at 0x00063103... (46 %)
      Writing at 0x0006920d... (50 %)
      Writing at 0x0006f091... (53 %)
      Writing at 0x00075129... (57 %)
      Writing at 0x0007af8f... (61 %)
      Writing at 0x00080989... (65 %)
      Writing at 0x00086a10... (69 %)
      Writing at 0x0008ccbe... (73 %)
      Writing at 0x00092c66... (76 %)
      Writing at 0x0009cbc8... (80 %)
      Writing at 0x000a4976... (84 %)
      Writing at 0x000adb45... (88 %)
      Writing at 0x000b36e7... (92 %)
      Writing at 0x000b8c9a... (96 %)
      Writing at 0x000becc1... (100 %)
      Wrote 736624 bytes (422317 compressed) at 0x00010000 in 10.6 seconds (effective 554.3 kbit/s)...
      Hash of data verified.
      Compressed 3072 bytes to 103...
      Writing at 0x00008000... (100 %)
      Wrote 3072 bytes (103 compressed) at 0x00008000 in 0.1 seconds (effective 250.4 kbit/s)...
      Hash of data verified.
      
      Leaving...
      Hard resetting via RTS pin...
      NG_DIRECTORY=C:/Users/Shrey_Coding/Desktop/ESP-IDF/bluetooth_temp_hum/build -P C:/Espressif/frameworks/esp-idf-v5.2.2/components/esptool_py/run_serial_tool.cmake"
      Executing action: monitor
      Running idf_monitor in directory C:\Users\Shrey_Coding\Desktop\ESP-IDF\bluetooth_temp_hum
      Executing "C:\Espressif\python_env\idf5.2_py3.11_env\Scripts\python.exe C:\Espressif\frameworks\esp-idf-v5.2.2\tools/idf_monitor.py -p COM5 -b 115200 --toolchain-prefix xtensa-esp32-elf- --target esp32 --revision 0 C:\Users\Shrey_Coding\Desktop\ESP-IDF\bluetooth_temp_hum\build\bluetooth_temp_hum.elf --force-color -m 'C:\Espressif\python_env\idf5.2_py3.11_env\Scripts\python.exe' 'C:\Espressif\frameworks\esp-idf-v5.2.2\tools\idf.py' '-p' 'COM5'"...
      --- WARNING: GDB cannot open serial ports accessed as COMx
      --- Using \\.\COM5 instead...
      --- esp-idf-monitor 1.4.0 on \\.\COM5 115200 ---
      --- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
      29 2019 12:21:46
      
      rst       : 40MHz
      I (44) boot.esp32: SPI Mode       : DIO
      I (49) boot.esp32: SPI Flash Size : 2MB
      I (53) boot: Enablin ets Jul 29 2019 12:21:46
      
      rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
      configsip: 0, SPIWP:0xee
      clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
      mode:DIO, clock div:2
      load:0x3fff0030,len:7172
      load:0x40078000,len:15540
      load:0x40080400,len:4
      0x40080400: _init at ??:?
      
      ho 8 tail 4 room 4
      load:0x40080404,len:3904
      entry 0x40080640
      I (31) boot: ESP-IDF v5.2.2-dirty 2nd stage bootloader
      I (31) boot: compile time Jul 10 2024 22:48:35
      I (31) boot: Multicore bootloader
      I (36) boot: chip revision: v3.0
      I (40) boot.esp32: SPI Speed      : 40MHz
      I (44) boot.esp32: SPI Mode       : DIO
      I (49) boot.esp32: SPI Flash Size : 2MB
      I (53) boot: Enabling RNG early entropy source...
      I (59) boot: Partition Table:
      I (62) boot: ## Label            Usage          Type ST Offset   Length
      I (70) boot:  0 nvs              WiFi data        01 02 00009000 00006000
      I (77) boot:  1 phy_init         RF data          01 01 0000f000 00001000
      I (85) boot:  2 factory          factory app      00 00 00010000 00100000
      I (92) boot: End of partition table
      I (96) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1fbc4h (129988) map
      I (149) esp_image: segment 1: paddr=0002fbec vaddr=3ffbdb60 size=0042ch (  1068) load
      I (150) esp_image: segment 2: paddr=00030020 vaddr=400d0020 size=78d10h (494864) map
      I (325) esp_image: segment 3: paddr=000a8d38 vaddr=3ffbdf8c size=044c8h ( 17608) load
      I (331) esp_image: segment 4: paddr=000ad208 vaddr=40080000 size=16b3ch ( 92988) load
      I (380) boot: Loaded app from partition at offset 0x10000
      I (380) boot: Disabling RNG early entropy source...
      I (391) cpu_start: Multicore app
      I (400) cpu_start: Pro cpu start user code
      I (400) cpu_start: cpu freq: 160000000 Hz
      I (400) cpu_start: Application information:
      I (403) cpu_start: Project name:     bluetooth_temp_hum
      I (409) cpu_start: App version:      1
      I (413) cpu_start: Compile time:     Jul 10 2024 22:48:27
      I (419) cpu_start: ELF file SHA256:  718865613...
      I (425) cpu_start: ESP-IDF:          v5.2.2-dirty
      I (430) cpu_start: Min chip rev:     v0.0
      I (435) cpu_start: Max chip rev:     v3.99
      I (440) cpu_start: Chip rev:         v3.0
      I (445) heap_init: Initializing. RAM available for dynamic allocation:
      I (452) heap_init: At 3FFAFF10 len 000000F0 (0 KiB): DRAM
      I (458) heap_init: At 3FFB6388 len 00001C78 (7 KiB): DRAM
      I (464) heap_init: At 3FFB9A20 len 00004108 (16 KiB): DRAM
      I (470) heap_init: At 3FFC6F90 len 00019070 (100 KiB): DRAM
      I (476) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
      I (483) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
      I (489) heap_init: At 40096B3C len 000094C4 (37 KiB): IRAM
      I (497) spi_flash: detected chip: generic
      I (500) spi_flash: flash io: dio
      W (504) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
      I (518) coexist: coex firmware version: d96c1e51f
      I (523) main_task: Started on CPU0
      I (533) main_task: Calling app_main()
      I (553) BTDM_INIT: BT controller compile version [4012cfb]
      I (553) BTDM_INIT: Bluetooth MAC: b8:d6:1a:6a:b0:92
      I (553) phy_init: phy_version 4791,2c4672b,Dec 20 2023,16:06:06
      I (943) BLE_CONFIG: Device name set to: ESP32_TEMP_HUM
      I (943) BLE_CONFIG: REGISTER_APP_EVT, status 0, app_id 85
      I (953) BLE_CONFIG: CREATE_SERVICE_EVT, status 0, service_handle 40
      W (953) BT_BTM: BTM_BleWriteAdvData, Partial data write into ADV
      W (963) BLE_CONFIG:
      Bluetooth initialization complete. Device name: ESP32_TEMP_HUM
      
      I (963) BLE_CONFIG: Advertising data set successfully.
      ---------------------------------------------------------------------------
      W (983) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      I (993) BLE_CONFIG: Advertising start successfully
      W (993) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 31.43 °C   Humidity = 61.29 %
      ---------------------------------------------------------------------------
      W (2003) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (2003) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 23.08 °C   Humidity = 54.56 %
      ---------------------------------------------------------------------------
      W (3013) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (3013) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 22.19 °C   Humidity = 89.51 %
      ---------------------------------------------------------------------------
      W (4023) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (4023) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 20.05 °C   Humidity = 62.93 %
      ---------------------------------------------------------------------------
      W (5033) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (5033) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 32.66 °C   Humidity = 70.32 %
      ---------------------------------------------------------------------------
      W (6043) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (6043) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 36.47 °C   Humidity = 76.68 %
      ---------------------------------------------------------------------------
      W (7053) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (7053) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 24.23 °C   Humidity = 74.92 %
      ---------------------------------------------------------------------------
      W (8063) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (8063) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 32.69 °C   Humidity = 92.27 %
      ---------------------------------------------------------------------------
      W (9073) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (9073) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 27.24 °C   Humidity = 80.20 %
      ---------------------------------------------------------------------------
      W (10083) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (10083) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 40.10 °C   Humidity = 87.84 %
      ---------------------------------------------------------------------------
      W (11093) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (11093) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 26.01 °C   Humidity = 89.36 %
      ---------------------------------------------------------------------------
      W (12103) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (12103) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 27.31 °C   Humidity = 77.97 %
      ---------------------------------------------------------------------------
      W (13113) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (13113) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 33.91 °C   Humidity = 88.44 %
      ---------------------------------------------------------------------------
      W (14123) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (14123) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 35.25 °C   Humidity = 92.30 %
      ---------------------------------------------------------------------------
      W (15133) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (15133) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 29.26 °C   Humidity = 77.34 %
      ---------------------------------------------------------------------------
      W (16143) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (16143) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 38.60 °C   Humidity = 61.20 %
      ---------------------------------------------------------------------------
      W (17153) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (17153) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 21.32 °C   Humidity = 75.13 %
      ---------------------------------------------------------------------------
      W (18163) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (18163) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 33.09 °C   Humidity = 61.05 %
      ---------------------------------------------------------------------------
      W (19173) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (19173) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 32.49 °C   Humidity = 77.19 %
      ---------------------------------------------------------------------------
      W (20183) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (20183) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 37.24 °C   Humidity = 65.49 %
      ---------------------------------------------------------------------------
      W (21193) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (21193) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 25.84 °C   Humidity = 68.45 %
      ---------------------------------------------------------------------------
      W (22203) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (22203) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 39.06 °C   Humidity = 67.54 %
      ---------------------------------------------------------------------------
      W (23213) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (23213) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 21.65 °C   Humidity = 79.38 %
      ---------------------------------------------------------------------------
      W (24223) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (24223) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 30.90 °C   Humidity = 59.37 %
      ---------------------------------------------------------------------------
      W (25233) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (25233) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 24.56 °C   Humidity = 61.11 %
      I (25883) BLE_CONFIG: Connection Established! gatts_if = 3
      I (26223) BLE_CONFIG: Advertising start successfully
      ---------------------------------------------------------------------------
      Temperature = 26.42 °C   Humidity = 61.68 %
      I (26503) BLE_CONFIG: Advertising start successfully
      ---------------------------------------------------------------------------
      Temperature = 33.01 °C   Humidity = 70.80 %
      ---------------------------------------------------------------------------
      Temperature = 33.71 °C   Humidity = 98.14 %
      ---------------------------------------------------------------------------
      Temperature = 30.64 °C   Humidity = 56.25 %
      ---------------------------------------------------------------------------
      Temperature = 23.31 °C   Humidity = 62.87 %
      ---------------------------------------------------------------------------
      Temperature = 35.87 °C   Humidity = 56.79 %
      ---------------------------------------------------------------------------
      Temperature = 23.50 °C   Humidity = 88.13 %
      I (32753) BLE_CONFIG: Temperature Read: 23.50 °C (0x2E 9)
      ---------------------------------------------------------------------------
      Temperature = 30.34 °C   Humidity = 84.47 %
      ---------------------------------------------------------------------------
      Temperature = 21.30 °C   Humidity = 73.57 %
      ---------------------------------------------------------------------------
      Temperature = 27.26 °C   Humidity = 50.97 %
      I (35283) BLE_CONFIG: Humidity Read: 50.97 % (0xE913)
      ---------------------------------------------------------------------------
      Temperature = 32.93 °C   Humidity = 96.38 %
      ---------------------------------------------------------------------------
      Temperature = 21.93 °C   Humidity = 98.20 %
      I (37573) BLE_CONFIG: Temperature Read: 21.93 °C (0x91 8)
      ---------------------------------------------------------------------------
      Temperature = 25.46 °C   Humidity = 98.10 %
      ---------------------------------------------------------------------------
      Temperature = 24.87 °C   Humidity = 87.03 %
      I (39383) BLE_CONFIG: Humidity Read: 87.03 % (0xFF21)
      ---------------------------------------------------------------------------
      Temperature = 40.00 °C   Humidity = 82.05 %
      ---------------------------------------------------------------------------
      Temperature = 37.52 °C   Humidity = 99.87 %
      I (41573) BLE_CONFIG: Temperature Read: 37.52 °C (0xA8 E)
      ---------------------------------------------------------------------------
      Temperature = 33.10 °C   Humidity = 56.10 %
      I (42983) BLE_CONFIG: Humidity Read: 56.10 % (0xEA15)
      ---------------------------------------------------------------------------
      Temperature = 26.96 °C   Humidity = 59.85 %
      ---------------------------------------------------------------------------
      Temperature = 23.47 °C   Humidity = 67.31 %
      ---------------------------------------------------------------------------
      Temperature = 23.86 °C   Humidity = 52.00 %
      W (45713) BT_HCI: hcif disc complete: hdl 0x0, rsn 0x13
      E (45713) BLE_CONFIG: Disconnected, gatts_if reset! Started advertisement!
      I (45733) BLE_CONFIG: Advertising start successfully
      ---------------------------------------------------------------------------
      W (46243) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (46243) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 33.55 °C   Humidity = 69.74 %
      ---------------------------------------------------------------------------
      W (47253) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (47253) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 24.06 °C   Humidity = 63.68 %
      I (47823) BLE_CONFIG: Connection Established! gatts_if = 3
      I (48163) BLE_CONFIG: Advertising start successfully
      ---------------------------------------------------------------------------
      Temperature = 33.70 °C   Humidity = 88.23 %
      I (48453) BLE_CONFIG: Advertising start successfully
      ---------------------------------------------------------------------------
      Temperature = 31.06 °C   Humidity = 61.30 %
      ---------------------------------------------------------------------------
      Temperature = 30.32 °C   Humidity = 91.74 %
      ---------------------------------------------------------------------------
      Temperature = 31.10 °C   Humidity = 100.55 %
      ---------------------------------------------------------------------------
      Temperature = 39.95 °C   Humidity = 50.05 %
      I (52743) BLE_CONFIG: Temperature Read: 39.95 °C (0x9B F)
      ---------------------------------------------------------------------------
      Temperature = 21.48 °C   Humidity = 64.53 %
      ---------------------------------------------------------------------------
      Temperature = 24.60 °C   Humidity = 67.56 %
      I (54343) BLE_CONFIG: Humidity Read: 67.56 % (0x641A)
      ---------------------------------------------------------------------------
      Temperature = 35.43 °C   Humidity = 72.37 %
      I (55813) BLE_CONFIG: Temperature Read: 35.43 °C (0xD7 D)
      ---------------------------------------------------------------------------
      Temperature = 25.35 °C   Humidity = 54.29 %
      ---------------------------------------------------------------------------
      Temperature = 28.07 °C   Humidity = 50.55 %
      I (57273) BLE_CONFIG: Humidity Read: 50.55 % (0xBF13)
      ---------------------------------------------------------------------------
      Temperature = 24.73 °C   Humidity = 62.45 %
      ---------------------------------------------------------------------------
      Temperature = 35.72 °C   Humidity = 50.53 %
      ---------------------------------------------------------------------------
      Temperature = 30.83 °C   Humidity = 86.55 %
      ---------------------------------------------------------------------------
      Temperature = 39.76 °C   Humidity = 52.76 %
      ---------------------------------------------------------------------------
      Temperature = 37.54 °C   Humidity = 58.02 %
      ---------------------------------------------------------------------------
      Temperature = 33.55 °C   Humidity = 92.16 %
      ---------------------------------------------------------------------------
      Temperature = 36.81 °C   Humidity = 95.80 %
      ---------------------------------------------------------------------------
      Temperature = 33.86 °C   Humidity = 69.07 %
      ---------------------------------------------------------------------------
      Temperature = 36.79 °C   Humidity = 93.65 %
      ---------------------------------------------------------------------------
      Temperature = 30.32 °C   Humidity = 54.32 %
      ---------------------------------------------------------------------------
      Temperature = 38.17 °C   Humidity = 59.83 %
      ---------------------------------------------------------------------------
      Temperature = 29.67 °C   Humidity = 76.46 %
      ---------------------------------------------------------------------------
      Temperature = 21.28 °C   Humidity = 73.07 %
      ---------------------------------------------------------------------------
      Temperature = 34.20 °C   Humidity = 96.28 %
      ---------------------------------------------------------------------------
      Temperature = 26.30 °C   Humidity = 52.48 %
      ---------------------------------------------------------------------------
      Temperature = 35.04 °C   Humidity = 87.10 %
      ---------------------------------------------------------------------------
      Temperature = 26.25 °C   Humidity = 92.31 %
      ---------------------------------------------------------------------------
      Temperature = 28.09 °C   Humidity = 91.22 %
      ---------------------------------------------------------------------------
      Temperature = 22.52 °C   Humidity = 62.95 %
      ---------------------------------------------------------------------------
      Temperature = 21.53 °C   Humidity = 64.78 %
      ---------------------------------------------------------------------------
      Temperature = 20.42 °C   Humidity = 88.88 %
      ---------------------------------------------------------------------------
      Temperature = 33.17 °C   Humidity = 74.43 %
      ---------------------------------------------------------------------------
      Temperature = 28.49 °C   Humidity = 71.36 %
      ---------------------------------------------------------------------------
      Temperature = 31.67 °C   Humidity = 53.63 %
      ---------------------------------------------------------------------------
      Temperature = 40.98 °C   Humidity = 78.51 %
      ---------------------------------------------------------------------------
      Temperature = 38.67 °C   Humidity = 63.78 %
      ---------------------------------------------------------------------------
      Temperature = 35.09 °C   Humidity = 89.60 %
      ---------------------------------------------------------------------------
      Temperature = 36.61 °C   Humidity = 80.09 %
      ---------------------------------------------------------------------------
      Temperature = 37.98 °C   Humidity = 82.34 %
      ---------------------------------------------------------------------------
      Temperature = 31.89 °C   Humidity = 58.31 %
      ---------------------------------------------------------------------------
      Temperature = 38.01 °C   Humidity = 68.94 %
      ---------------------------------------------------------------------------
      Temperature = 27.65 °C   Humidity = 67.65 %
      ---------------------------------------------------------------------------
      Temperature = 40.58 °C   Humidity = 58.48 %
      ---------------------------------------------------------------------------
      Temperature = 26.29 °C   Humidity = 77.89 %
      ---------------------------------------------------------------------------
      Temperature = 40.88 °C   Humidity = 87.43 %
      ---------------------------------------------------------------------------
      Temperature = 26.71 °C   Humidity = 80.64 %
      ---------------------------------------------------------------------------
      Temperature = 20.12 °C   Humidity = 81.11 %
      ---------------------------------------------------------------------------
      Temperature = 32.82 °C   Humidity = 76.23 %
      ---------------------------------------------------------------------------
      Temperature = 26.24 °C   Humidity = 94.37 %
      ---------------------------------------------------------------------------
      Temperature = 33.04 °C   Humidity = 60.91 %
      ---------------------------------------------------------------------------
      Temperature = 32.75 °C   Humidity = 97.59 %
      W (99193) BT_HCI: hcif disc complete: hdl 0x0, rsn 0x13
      E (99193) BLE_CONFIG: Disconnected, gatts_if reset! Started advertisement!
      I (99213) BLE_CONFIG: Advertising start successfully
      ---------------------------------------------------------------------------
      W (99263) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (99263) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 34.96 °C   Humidity = 73.63 %
      ---------------------------------------------------------------------------
      W (100273) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (100273) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 35.77 °C   Humidity = 74.47 %
      ---------------------------------------------------------------------------
      W (101283) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (101283) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 33.48 °C   Humidity = 68.54 %
      ---------------------------------------------------------------------------
      W (102293) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (102293) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 36.59 °C   Humidity = 91.23 %
      ---------------------------------------------------------------------------
      W (103303) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (103303) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 32.24 °C   Humidity = 78.02 %
      ---------------------------------------------------------------------------
      W (104313) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (104313) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 31.76 °C   Humidity = 71.92 %
      ---------------------------------------------------------------------------
      W (105323) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (105323) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 20.04 °C   Humidity = 90.58 %
      ---------------------------------------------------------------------------
      W (106333) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (106333) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 38.14 °C   Humidity = 68.28 %
      ---------------------------------------------------------------------------
      W (107343) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (107343) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 27.91 °C   Humidity = 92.92 %
      ---------------------------------------------------------------------------
      W (108353) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (108353) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 29.98 °C   Humidity = 96.68 %
      ---------------------------------------------------------------------------
      W (109363) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (109363) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 40.79 °C   Humidity = 81.63 %
      ---------------------------------------------------------------------------
      W (110373) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (110373) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 39.79 °C   Humidity = 69.66 %
      ---------------------------------------------------------------------------
      W (111383) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (111383) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 34.32 °C   Humidity = 80.14 %
      ---------------------------------------------------------------------------
      W (112393) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (112393) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 39.71 °C   Humidity = 91.79 %
      ---------------------------------------------------------------------------
      W (113403) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (113403) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 32.00 °C   Humidity = 99.03 %
      ---------------------------------------------------------------------------
      W (114413) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (114413) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 35.55 °C   Humidity = 95.81 %
      ---------------------------------------------------------------------------
      W (115423) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (115423) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 21.29 °C   Humidity = 71.97 %
      ---------------------------------------------------------------------------
      W (116433) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (116433) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 20.57 °C   Humidity = 71.82 %
      ---------------------------------------------------------------------------
      W (117443) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (117443) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 29.06 °C   Humidity = 68.29 %
      ---------------------------------------------------------------------------
      W (118453) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (118453) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 33.41 °C   Humidity = 82.52 %
      ---------------------------------------------------------------------------
      W (119463) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (119463) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 31.60 °C   Humidity = 70.16 %
      ---------------------------------------------------------------------------
      W (120473) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (120473) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 25.06 °C   Humidity = 61.85 %
      ---------------------------------------------------------------------------
      W (121483) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (121483) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 23.27 °C   Humidity = 52.58 %
      ---------------------------------------------------------------------------
      W (122493) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (122493) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 22.10 °C   Humidity = 62.74 %
      ---------------------------------------------------------------------------
      W (123503) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (123503) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 31.71 °C   Humidity = 72.05 %
      ---------------------------------------------------------------------------
      W (124513) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (124513) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 29.71 °C   Humidity = 72.17 %
      ---------------------------------------------------------------------------
      W (125523) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (125523) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 32.80 °C   Humidity = 99.75 %
      ---------------------------------------------------------------------------
      W (126533) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (126533) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 25.46 °C   Humidity = 89.68 %
      ---------------------------------------------------------------------------
      W (127543) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (127543) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 34.26 °C   Humidity = 77.66 %
      ---------------------------------------------------------------------------
      W (128553) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (128553) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 21.54 °C   Humidity = 79.63 %
      ---------------------------------------------------------------------------
      W (129563) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (129563) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 22.11 °C   Humidity = 98.48 %
      ---------------------------------------------------------------------------
      W (130573) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (130573) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 32.31 °C   Humidity = 77.12 %
      ---------------------------------------------------------------------------
      W (131583) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (131583) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 30.32 °C   Humidity = 76.23 %
      ---------------------------------------------------------------------------
      W (132593) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (132593) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 29.09 °C   Humidity = 87.22 %
      ---------------------------------------------------------------------------
      W (133603) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (133603) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 36.76 °C   Humidity = 51.17 %
      ---------------------------------------------------------------------------
      W (134613) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (134613) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 20.02 °C   Humidity = 96.36 %
      ---------------------------------------------------------------------------
      W (135623) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (135623) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 38.35 °C   Humidity = 98.28 %
      ---------------------------------------------------------------------------
      W (136633) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (136633) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 32.26 °C   Humidity = 64.75 %
      ---------------------------------------------------------------------------
      W (137643) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (137643) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 32.64 °C   Humidity = 57.58 %
      ---------------------------------------------------------------------------
      W (138653) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (138653) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 22.21 °C   Humidity = 56.77 %
      ---------------------------------------------------------------------------
      W (139663) BLE_CONFIG:
      Cannot indicate temperature, no valid connection!
      
      W (139663) BLE_CONFIG:
      Cannot indicate humidity, no valid connection!
      
      Temperature = 21.26 °C   Humidity = 85.51 %
      
      Done

    
  - nRF Connectivity Application: 
`
      nRF Connect, 2024-07-12
      ESP32_TEMP_HUM (B8:D6:1A:6A:B0:92)
      V	15:11:08.171	Connecting to B8:D6:1A:6A:B0:92...
      D	15:11:08.171	gatt = device.connectGatt(autoConnect = false, TRANSPORT_LE, preferred PHY = LE 1M)
      D	15:11:08.602	[Broadcast] Action received: android.bluetooth.device.action.ACL_CONNECTED
      D	15:11:08.608	[Callback] Connection state changed with status: 0 and new state: CONNECTED (2)
      I	15:11:08.608	Connected to B8:D6:1A:6A:B0:92
      V	15:11:08.609	Discovering services...
      D	15:11:08.609	gatt.discoverServices()
      I	15:11:08.922	Connection parameters updated (interval: 7.5ms, latency: 0, timeout: 5000ms)
      D	15:11:09.102	[Callback] Services discovered with status: 0
      I	15:11:09.102	Services discovered
      V	15:11:09.108	Generic Attribute (0x1801)
      - Service Changed [I] (0x2A05)
         Client Characteristic Configuration (0x2902)
      Generic Access (0x1800)
      - Device Name [R] (0x2A00)
      - Appearance [R] (0x2A01)
      - Central Address Resolution [R] (0x2AA6)
      Unknown Service (00000002-0000-0000-fdfd-fdfdfdfdfdfd)
      - Temperature [N R] (0x2A6E)
      - Humidity [N R] (0x2A6F)
      D	15:11:09.108	gatt.setCharacteristicNotification(00002a05-0000-1000-8000-00805f9b34fb, true)
      I	15:11:09.190	Connection parameters updated (interval: 48.75ms, latency: 0, timeout: 5000ms)
      V	15:11:15.374	Reading characteristic 00002a6e-0000-1000-8000-00805f9b34fb
      D	15:11:15.374	gatt.readCharacteristic(00002a6e-0000-1000-8000-00805f9b34fb)
      I	15:11:15.449	Read Response received from 00002a6e-0000-1000-8000-00805f9b34fb, value: (0x) 2E-09
      A	15:11:15.450	"23.50℃" received
      V	15:11:17.887	Reading characteristic 00002a6f-0000-1000-8000-00805f9b34fb
      D	15:11:17.887	gatt.readCharacteristic(00002a6f-0000-1000-8000-00805f9b34fb)
      I	15:11:17.980	Read Response received from 00002a6f-0000-1000-8000-00805f9b34fb, value: (0x) E9-13
      A	15:11:17.980	"50.97%" received
      V	15:11:20.207	Reading characteristic 00002a6e-0000-1000-8000-00805f9b34fb
      D	15:11:20.207	gatt.readCharacteristic(00002a6e-0000-1000-8000-00805f9b34fb)
      I	15:11:20.272	Read Response received from 00002a6e-0000-1000-8000-00805f9b34fb, value: (0x) 91-08
      A	15:11:20.272	"21.93℃" received
      V	15:11:21.987	Reading characteristic 00002a6f-0000-1000-8000-00805f9b34fb
      D	15:11:21.987	gatt.readCharacteristic(00002a6f-0000-1000-8000-00805f9b34fb)
      I	15:11:22.076	Read Response received from 00002a6f-0000-1000-8000-00805f9b34fb, value: (0x) FF-21
      A	15:11:22.076	"87.03%" received
      V	15:11:24.186	Reading characteristic 00002a6e-0000-1000-8000-00805f9b34fb
      D	15:11:24.186	gatt.readCharacteristic(00002a6e-0000-1000-8000-00805f9b34fb)
      I	15:11:24.269	Read Response received from 00002a6e-0000-1000-8000-00805f9b34fb, value: (0x) A8-0E
      A	15:11:24.269	"37.52℃" received
      V	15:11:25.599	Reading characteristic 00002a6f-0000-1000-8000-00805f9b34fb
      D	15:11:25.599	gatt.readCharacteristic(00002a6f-0000-1000-8000-00805f9b34fb)
      I	15:11:25.683	Read Response received from 00002a6f-0000-1000-8000-00805f9b34fb, value: (0x) EA-15
      A	15:11:25.684	"56.10%" received
      V	15:11:27.234	Disconnecting...
      D	15:11:27.234	gatt.disconnect()
      D	15:11:27.278	[Callback] Connection state changed with status: 0 and new state: DISCONNECTED (0)
      I	15:11:27.278	Disconnected
      D	15:11:28.381	[Broadcast] Action received: android.bluetooth.device.action.ACL_DISCONNECTED
      D	15:11:30.097	gatt.close()
      D	15:11:30.101	wait(200)
      V	15:11:30.302	Connecting to B8:D6:1A:6A:B0:92...
      D	15:11:30.302	gatt = device.connectGatt(autoConnect = false, TRANSPORT_LE, preferred PHY = LE 1M)
      D	15:11:30.561	[Broadcast] Action received: android.bluetooth.device.action.ACL_CONNECTED
      D	15:11:30.589	[Callback] Connection state changed with status: 0 and new state: CONNECTED (2)
      I	15:11:30.589	Connected to B8:D6:1A:6A:B0:92
      V	15:11:30.613	Discovering services...
      D	15:11:30.613	gatt.discoverServices()
      I	15:11:30.861	Connection parameters updated (interval: 7.5ms, latency: 0, timeout: 5000ms)
      D	15:11:31.053	[Callback] Services discovered with status: 0
      I	15:11:31.053	Services discovered
      V	15:11:31.061	Generic Attribute (0x1801)
      - Service Changed [I] (0x2A05)
         Client Characteristic Configuration (0x2902)
      Generic Access (0x1800)
      - Device Name [R] (0x2A00)
      - Appearance [R] (0x2A01)
      - Central Address Resolution [R] (0x2AA6)
      Unknown Service (00000002-0000-0000-fdfd-fdfdfdfdfdfd)
      - Temperature [N R] (0x2A6E)
      - Humidity [N R] (0x2A6F)
      D	15:11:31.061	gatt.setCharacteristicNotification(00002a05-0000-1000-8000-00805f9b34fb, true)
      I	15:11:31.145	Connection parameters updated (interval: 48.75ms, latency: 0, timeout: 5000ms)
      V	15:11:35.333	Reading characteristic 00002a6e-0000-1000-8000-00805f9b34fb
      D	15:11:35.333	gatt.readCharacteristic(00002a6e-0000-1000-8000-00805f9b34fb)
      I	15:11:35.440	Read Response received from 00002a6e-0000-1000-8000-00805f9b34fb, value: (0x) 9B-0F
      A	15:11:35.440	"39.95℃" received
      V	15:11:36.977	Reading characteristic 00002a6f-0000-1000-8000-00805f9b34fb
      D	15:11:36.977	gatt.readCharacteristic(00002a6f-0000-1000-8000-00805f9b34fb)
      I	15:11:37.046	Read Response received from 00002a6f-0000-1000-8000-00805f9b34fb, value: (0x) 64-1A
      A	15:11:37.046	"67.56%" received
      V	15:11:38.425	Reading characteristic 00002a6e-0000-1000-8000-00805f9b34fb
      D	15:11:38.425	gatt.readCharacteristic(00002a6e-0000-1000-8000-00805f9b34fb)
      I	15:11:38.510	Read Response received from 00002a6e-0000-1000-8000-00805f9b34fb, value: (0x) D7-0D
      A	15:11:38.511	"35.43℃" received
      V	15:11:39.889	Reading characteristic 00002a6f-0000-1000-8000-00805f9b34fb
      D	15:11:39.889	gatt.readCharacteristic(00002a6f-0000-1000-8000-00805f9b34fb)
      I	15:11:39.969	Read Response received from 00002a6f-0000-1000-8000-00805f9b34fb, value: (0x) BF-13
      A	15:11:39.969	"50.55%" received
   
`
