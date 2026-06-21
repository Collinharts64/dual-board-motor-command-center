# Wireless Command Center & Industrial Motor Controller

## Project Overview
This project is a dual-board embedded system featuring a wireless command interface and an isolated high-power motor control station. A hand-held controller built on an **Arduino Nano** transmits remote commands to a central processing station built on an **Arduino Uno**. The Uno decodes these signals to handle real-time motor speed, directional control, and system status telemetry.

## System Architecture & Hardware Stack

### 1. Transmit Station (Command Center)
* **Microcontroller:** Arduino Nano
* **User Interface:** 8-LED Status Array (provides visual feedback of current modes, speed levels, or link status)
* **Communication:** Wireless Transmitter Module

### 2. Receive & Power Execution Station
* **Microcontroller:** Arduino Uno
* **Communication:** Wireless Receiver Module
* **Speed Modulation:** ZK-BMG Motor Governor (PWM controller used to efficiently throttle the DC motor)
* **Power & Isolation:** IC Relay Module (handles safe physical switching/isolation of the high-current DC motor circuit)
* **Actuator:** High-Torque DC Motor

## Circuit Design & Safety Protocols
To handle inductive motor loads without risking damage to the microcontrollers or causing logic resets:
* **Galvanic Isolation:** The IC Relay Module isolates the digital control signals of the Arduino Uno from the high-amperage motor supply line.
* **Hardware PWM Control:** The ZK-BMG governor manages high-frequency switching to ensure smooth acceleration and torque delivery.

## Repository Directory Structure
* `/src/nano_tx`: Firmware for the handheld input console (Nano).
* `/src/uno_rx`: Firmware for the hardware execution and relay control unit (Uno).
* `/schematics`: Visual wiring diagrams tracking signal flow between the microcontrollers, relay module, and governor.

## Future Enhancements
* Transitioning the communication protocol to a transceiver layout for bi-directional telemetry feedback.
* Designing a custom PCB layout to consolidate the relay, governor interface, and Uno socket.
