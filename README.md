# 🦇 Ultrasonic Sensory Glasses (Arduino)

![Platform](https://img.shields.io/badge/Platform-Arduino-00979D?style=for-the-badge&logo=arduino)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Functional-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

> **Assistive Technology:** A wearable device that aids in obstacle detection through spatial audio feedback.

## 📸 Demo

![Project Demo](assets/demo-project.gif)

<div align="center">
  <img src="assets/glasses-photo.jpg" width="45%" alt="Glasses Prototype"/>
  <img src="assets/circuit-setup.jpg" width="45%" alt="Circuit Wiring"/>
</div>

## 💡 About the Project

This project consists of a pair of glasses equipped with **ultrasonic sensors** and **buzzers**. The goal is to create an artificial "echolocation" system.

The system independently measures the distance of objects to the left and right. The closer an object is, the faster the interval of the sound signal (Beep) becomes, alerting the user to potential collisions.

### Features:
- 📡 **Dual Detection:** Simultaneous monitoring of both left and right sides.
- 🔊 **Spatial Feedback:** The left buzzer signals obstacles on the left, and the right buzzer signals for the right.
- 🚀 **Variable Rhythm:** - Safe (> 1m): Silence.
  - Approaching (1m - 50cm): Slow beeps.
  - Danger (< 30cm): Frenetic, fast beeps.

## 🛠️ Hardware List

| Qty | Component | Description |
| --- | --- | --- |
| 1 | Arduino Uno / Nano | The brain of the project |
| 2 | HC-SR04 | Ultrasonic Distance Sensors |
| 2 | Buzzer (Active/Passive) | Sound emitters (Piezo) |
| 1 | Breadboard | For prototyping |
| X | Jumper Wires | Connection cables (Male-Male / Male-Female) |
| 1 | Power Bank | Portable power supply (5V) |

## 🔌 Wiring Diagram (Pinout)

The connections are defined in the code as follows:

### Left Side 👈
* **Trig:** Digital Pin 9
* **Echo:** Digital Pin 10
* **Buzzer:** Digital Pin 3
