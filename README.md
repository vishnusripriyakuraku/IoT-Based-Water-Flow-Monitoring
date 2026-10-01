# IoT-Based Water Flow Monitoring System

## Project Overview

The IoT-Based Water Flow Monitoring System is designed to monitor and control water distribution using RFID authentication and embedded technology.

This project uses a microcontroller, RFID cards, a water flow sensor, a DC motor and LED indicators to provide controlled water access and monitor water consumption.

## Objectives

* To implement RFID-based user authentication.
* To monitor water flow and total water consumption.
* To control water distribution using a DC motor.
* To indicate system status using LED indicators.
* To develop a foundation for IoT-based water monitoring.

## Technologies Used

* Arduino IDE
* Embedded C
* RFID
* IoT
* Microcontroller

## Hardware Requirements

* Arduino Uno
* RFID RC522 module
* RFID cards
* Water flow sensor
* DC motor or water pump
* Motor driver
* Green LED
* Red LED
* Resistors
* Jumper wires
* Power supply

## Software Requirements

* Arduino IDE
* MFRC522 library
* SPI library

## Working Principle

The RFID reader scans the user's card and sends the card UID to the microcontroller.

The microcontroller checks whether the scanned UID is authorized.

* **Authorized card:** The green LED indicates successful authentication, and the motor can be activated.
* **Unauthorized card:** The red LED indicates unsuccessful authentication, and the motor remains in its previous state.

The water flow sensor detects water movement and generates pulses. The microcontroller counts these pulses to calculate the flow rate and total water consumption.

The collected data can be extended to an IoT platform for remote monitoring.

## Features

* RFID-based authentication
* Automated water supply control
* Real-time water flow measurement
* Total water consumption calculation
* LED status indication
* Expandable IoT monitoring

## Applications

* Smart water distribution systems
* Water usage monitoring
* Smart irrigation prototypes
* Automated water dispensing
* Water management systems

## Future Enhancements

* Cloud-based water monitoring
* Mobile application integration
* Multiple-user authentication
* Water usage history
* Automatic water supply cutoff
* Water consumption alerts

## Repository Structure

```text
IoT-Based-Water-Flow-Monitoring/
│
├── README.md
├── water_flow_monitoring.ino
├── Circuit_Diagram/
│   └── circuit_diagram.png
├── Documentation/
│   └── project_report.pdf
└── Images/
    └── project_setup.jpg
```

## Conclusion

The IoT-Based Water Flow Monitoring System demonstrates how embedded systems and RFID technology can be used to control water access and monitor water consumption.

The project provides a foundation for developing smart water management solutions with additional IoT capabilities.
