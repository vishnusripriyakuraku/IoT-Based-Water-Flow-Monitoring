# IoT-Based Water Flow Monitoring System

## 1. Introduction

The IoT-Based Water Flow Monitoring System is designed to control and monitor water distribution using a microcontroller, RFID cards, and a water flow sensor.

The system provides access to authorized users and controls a water pump automatically.

## 2. Objectives

* To control water distribution using RFID authentication.
* To measure water flow using a flow sensor.
* To control a DC motor or water pump.
* To indicate authorized and unauthorized access using LEDs.
* To provide a foundation for future IoT-based remote monitoring.

## 3. Components Required

* Arduino Uno
* RFID RC522 module
* RFID cards
* Water flow sensor (YF-S201)
* L298N motor driver
* DC motor or water pump
* Green LED
* Red LED
* 220Ω resistors
* Jumper wires
* 12V power supply for the motor, as required

## 4. Working Principle

1. The RFID reader scans the user's RFID card.
2. The Arduino checks whether the card UID is authorized.
3. If the card is authorized, the green LED turns on and the motor driver activates the water pump.
4. The water flow sensor generates pulses while water flows.
5. The Arduino counts the pulses to calculate the water flow and volume.
6. If the card is unauthorized, the red LED indicates that access is denied.

## 5. Pin Connections

| Component          | Arduino Pin |
| ------------------ | ----------- |
| RFID SDA/SS        | D10         |
| RFID SCK           | D13         |
| RFID MOSI          | D11         |
| RFID MISO          | D12         |
| RFID RST           | D9          |
| RFID 3.3V          | 3.3V        |
| RFID GND           | GND         |
| Flow sensor signal | D2          |
| Green LED          | D3          |
| Red LED            | D4          |
| Motor driver ENA   | D5          |
| Motor driver IN1   | D7          |
| Motor driver IN2   | D8          |

## 6. Software Used

* Arduino IDE
* Embedded C/C++ (Arduino programming)
* MFRC522 library
* SPI library

## 7. Applications

* Controlled water distribution
* Water usage monitoring
* Smart irrigation prototypes
* Water management systems

## 8. Advantages

* RFID-based access control
* Automatic pump operation
* Flow measurement
* Simple and low-cost prototype
* Expandable for future IoT integration

## 9. Future Scope

* Add a Wi-Fi module or Wi-Fi-enabled microcontroller.
* Send water usage data to a cloud platform.
* Develop a mobile application for remote monitoring.
* Add alerts for abnormal water flow.
* Store user-wise water consumption records.

## 10. Conclusion

The project demonstrates a basic water flow monitoring and access control system using Arduino Uno, RFID authentication, a water flow sensor, and a motor driver. It can be extended with Wi-Fi and cloud connectivity to support remote monitoring and IoT-based water management.
