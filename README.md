# Automatic_Street_Light_Controller_IOT
IoT-based automatic street light controller using LDR sensor and microcontroller for energy-efficient smart lighting.

# Overview:
This project is designed to automatically control street lights using sensors, a microcontroller, and IoT technology. It helps in energy saving by turning lights ON/OFF based on environmental conditions.

# Objectives:
- Reduce electricity consumption
- Automate street lighting system
- Enable remote monitoring using IoT

# Components Used:
- LDR Sensor (Light Dependent resistor)
- Microcontroller (Arduino ESP32)
- PIR Sensor
- LED 
- Resistors
- BC547 Transistor

# Working Principle:
- LDR detects light intensity
- When it becomes dark → street light turns ON
- When it is bright → street light turns OFF
- IoT module sends data for remote monitoring

# IoT Features:
- Real-time monitoring
- Remote control using mobile/web
- Energy usage tracking

# Technologies Used:
- Embedded C / Arduino IDE
- IoT Platform (Blynk)
- Sensors & Microcontroller

# Project Image:
<img width="1280" height="960" alt="WhatsApp Image 2026-04-22 at 11 33 38 AM" src="https://github.com/user-attachments/assets/979ca94a-31b8-4dbe-9923-64e1e86c2e75" />



# Circuit Diagram:

<img width="1083" height="391" alt="image" src="https://github.com/user-attachments/assets/45411440-d800-4411-97f1-09f56430ac71" />
# Circuit Explanation:

This circuit represents a smart street light system using ESP32, LDR, and PIR sensor.

The ESP32 microcontroller is the main controller of the system. It receives input signals from the LDR and PIR sensor. The LDR is connected to an analog pin (GPIO34) and is used to detect ambient light intensity. During daytime, the LDR output indicates high light, so the street light remains OFF. During nighttime, the light intensity decreases, activating the system.

The PIR sensor is connected to another GPIO pin and is used to detect motion. When motion is detected, the ESP32 sends a signal to the transistor.

A BC547 transistor is used as a switch to control the LED. When the transistor is triggered, current flows through the LED, turning it ON. A resistor is used to limit current and protect the LED.

This system helps in energy saving by automatically controlling street lights based on light intensity and human movement.


# Applications:

• Smart Cities: Used in smart city infrastructure for automated and energy-efficient street lighting systems.

• Highways: Can be implemented on highways to reduce energy consumption by activating lights only when vehicles are detected.

• Public Street Lighting: Suitable for urban and rural street lighting to automate ON/OFF control based on light intensity and motion.

# Conclusion:

- The project successfully implements an automatic street light control system using ESP32, LDR, and PIR sensor. It detects ambient light and human motion to control lighting efficiently.

- By turning OFF lights during daytime and activating them only when required at night, the system reduces energy consumption and improves performance. This solution is cost-effective and suitable for smart city applications.
