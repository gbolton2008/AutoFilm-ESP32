# AutoFilm-ESP32 README

## Overview

AutoFilm-ESP32 is an automated film processing machine designed to handle the development of photographic film using a Kindermann style stainless steel tank. The device utilizes an ESP32 microcontroller, NEMA-17 stepper motor, DS18B20 temperature sensor, and a 2004 type LCD with I2C interface. The software allows for precise control of the development process, including rotation patterns and agitation timings.

## Features

- **Automated Film Processing**: Automates the film development process, reducing the need for manual intervention.
- **Customizable Sequences**: Define and adjust development sequences for various film types and processes.
- **User Interface**: Simple and intuitive interface with a keypad and LCD display.
- **Persistent Settings**: Upcoming feature to store and manage processing parameters directly on the device without recompilation.

## Hardware Components

- **Microcontroller**: ESP32
- **Motor**: Waterproof NEMA-17 stepper motor
- **Temperature Sensor**: DS18B20
- **Display**: 2004 type LCD with I2C interface
- **Mechanical Parts**: 
  - 8mm brass rods
  - Plastic bearings
  - 3D printed idlers, gears, and chassis
  - Stainless steel tank (Kindermann style)

## Software Structure

### Main Components

1. **devSequences.cpp**: Defines the processing sequences for various development processes. Each sequence includes:
   - Ideal processing temperature
   - Upper and lower temperature bounds
   - Rotation patterns
   - Agitation times for each step

2. **Keypad Navigation**: Use the keypad to adjust processing times for each step. Left and right buttons facilitate this adjustment.

### Future Improvements

- **Persistent Parameter Storage**: Move processing parameters to files for in-device storage and modification without recompilation.
- **Extended Customization**: Enhance user interface to allow for more detailed customization of development sequences.

## Getting Started

### Prerequisites

- ESP32 development environment set up
- Required hardware components assembled and connected as per the schematic
- Water bath with temperature control (e.g., sous vide heater)

### Installation

1. Clone the repository:
   ```bash
   git clone https://git.i3omb.com/gronod/AutoFilm-ESP32.git
Open the project in your preferred IDE (e.g., Arduino IDE, PlatformIO).
Configure the project settings, including Wi-Fi credentials if necessary.
Upload the code to the ESP32 microcontroller.

### Usage
1. ## Setup:

 - Ensure the development tank is clean and dry.
 - Prepare the water bath and set the desired temperature using a sous vide heater or another closed-loop temperature control device.
 - Submerge the development tank in the water bath.

2. ## Initialization:

 - Power on the device and wait for the initial setup to complete.
3. ## Sequence Selection:

 - Select the desired development sequence from the options provided.
4. ## Processing Steps:

 - For each processing step, follow these instructions:
  1. **Add Chemistry:** Fill the tank with the required volume of the developing chemical.
  2. **Start Step:** Begin the step by pressing the appropriate button on the keypad. The device will rotate and agitate as per the defined sequence.
  3. **Monitor Temperature:** Ensure the water bath maintains the correct temperature range.
  4. **Drain Chemistry:** At the end of the step, drain the developing chemical from the tank.
  5. **Rinse and Repeat:** Repeat the process for each subsequent step, adding and draining the appropriate chemicals as needed.

5. ## Completion:


 - Follow standard procedures to dry the film.

###Contributing
Contributions are welcome! Please follow these steps to contribute:

Fork the repository.
1. Create a new branch with a descriptive name.
2. Make your changes and test thoroughly.
3. Submit a pull request with a detailed description of your changes.

###License
This project is licensed under the GPL3 (or later) License. See the LICENSE file for details.

Contact
For any queries or issues, please open an issue in the repository or contact the maintainer at gordon@i3omb.com