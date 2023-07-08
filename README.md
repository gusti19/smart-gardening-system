## Smart Gardening System

This repository contains the code for a Smart Gardening System using an Arduino and an LCD display. The system measures soil moisture and controls a motor based on the moisture level detected.

### Components Used:
- Arduino board
- I2C LCD display
- Soil moisture sensor
- DC motor

### Functionality:
- The code initializes the LCD display and sets up the pins for soil moisture sensor and motor.
- It defines functions to show the project title and student numbers on the LCD.
- The setup function calls the necessary initialization functions and displays the project title and student numbers.
- The loop function continuously reads the soil moisture level, updates the LCD display, and controls the motor based on the moisture level.
- The statusSensor function updates the LCD display with the current moisture level and displays appropriate messages based on the moisture level.

### Instructions:
1. Set up the hardware components as described in the circuit diagram.
2. Upload the code to your Arduino board.
3. Make sure the LCD display and other connections are properly configured.
4. Power on the system and observe the moisture level and motor control on the LCD display.

Please refer to the circuit diagram and comments in the code for more detailed information.

**Note:** The code assumes the use of a specific LCD library (LiquidCrystal_I2C). Make sure you have installed the required library before running the code.

For any further information or assistance, please refer to the documentation or contact the project contributors.


Feel free to explore, modify, and enhance the code to meet your specific requirements. Happy gardening!
