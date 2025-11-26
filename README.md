# 🦇 Ultrasonic Sensory Glasses (Arduino)

![Platform](https://img.shields.io/badge/Platform-Arduino-00979D?style=for-the-badge&logo=arduino)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Functional-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

> **Assistive Technology:** A wearable device that aids blind or low-vision persons in obstacle detection through spatial audio feedback.

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
- **Variable Rhythm:**
  - Safe (> 1m): Silence.
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

### Right Side 👉
* **Trig:** Digital Pin 8
* **Echo:** Digital Pin 7
* **Buzzer:** Digital Pin 2

> **Note:** All VCC pins are connected to 5V, and GND pins to the Arduino GND.

## 💻 How to Run the Code

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Clone this repository or download the `.ino` file.
3. Connect the Arduino to your PC via USB.
4. Select the correct port in `Tools > Port`.
5. Upload the code by clicking the **Upload** button (Right Arrow).

## 🧠 Logic Explanation (Snippet)

The secret behind the buzzer rhythm lies in this simple mathematical formula within the `emitirSom` (emitSound) function:

```cpp
// The silence duration is proportional to the distance
// If distance = 10cm -> wait 20ms (Very fast beeps)
// If distance = 90cm -> wait 180ms (Slow beeps)
delay(distancia * 2);
