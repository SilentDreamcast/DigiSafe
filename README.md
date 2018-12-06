# DigiSafe

DigiSafe is an offline username and password storage device that currently runs on Arduino based hardware using ATMEGA32u4 microcontrollers. There will be some extra security hardware sauce in the future.

This project was started as a quick 2 week sprint exercise for senior design at California State University Northridge, Computer Science. Although the project was discontinued after the exercise, it was picked up again for a Human Computer Interaction class. As the class name suggests, the current progress was to gauge a metric that made the device more human friendly. We will continue working on the device even after the class has completed.

There is a lot of stuff to do, security being a big priority onwards; but for the sake of our Human Computer Interaction course this current version is for experimentation on Account Sorting based on Alphabetical vs Popularity.

## Getting Started

These instructions will help you recreate DigiSafe for testing and personal use.

### Prerequisites

Stuff you will need:

```
* [Arduino IDE](https://www.arduino.cc/) - you don't have to use this but we did
* [Adafruit OLED library](https://github.com/adafruit/Adafruit_SSD1306) - they do great work, consider buying their products
* Arduino Leonardo - or any other board that uses the ATMEGA32u4 microcontroller or similar variant
* Soldering iron, some support components, etc.
```

### Hardware Setup

Since you are building one yourself, you may omit or add certain parts.
Parts that may be omitted: All Headers, Atmel i2c EEPROM, Real-Time-Clock, Li-poly/ion battery/charger, 5v boost converter, diodes, LEDs, USB serial UART chip, additional USB ports.
Really the only current requirements are the ATMEGA32u4 microcontroller (with supporting components), 128x32 OLED screen, 3 buttons, USB connector.

```
1. Look at the image **schematic.png**. *We used bare chips soldered to a custom breakout PCB so your results may vary. A Fritzing image is coming in the future for breadboard users.*

2. Connect the parts as seen in the schematic.

3. Check your connections again.
```

### Software Setup

```
1. Install the Arduino IDE (available for Windows, Linux, Mac)
2. Install the OLED library directly from within the IDE or git to your *Arduino/libraries* folder.
3. Download the DigiSafe source files
4. Open the .ino file
5. Modify the source to suit your hardware configuration.
6. Plug in your USB device, select the correct COM port and board.
7. Upload the code!
```

## Running the tests

Since this was project was continued for Human Computer Interation, we created a test for the account menu's sorting to reduce overall user account access times.
To run the test:

```
1. Verify your device is working. After a 1 second splash screen, the display should say "Alphabetical" and "Popularity"
2. Press the up or down button to select your sort type.
3. Open **TesterPage.html** in any web browser.
4. The page should randomly pick an account. Using the device's "up" and "down" buttons, scroll to the name in the account menu and press "select."
5. The device should now say "back" and "access". Using "select" will cause the device to automatically type the username and password into the TesterPage's credential fields and display a new Account name.
6. Repeat steps 4 and 5 until a popup says that the test is complete after 100 trys.
7. Copy the table at the bottom of the TesterPage into a spreadsheet program.
8. Repeat steps 2 through 7 using the other sorting method.
```

## Contributing and Questions

When contributing to this repository, please first discuss the change you wish to make via *issue* with the owner of this repository before making a change.
For general questions or some kind of other discussion, email silentdreamcast@gmail.com
I am new to posting projects on GitHub, please go easy on me.

## Authors

* **Marvin Mallari** - *Arduino code and hardware design*, repo-owner
* **Dawei Zhang** - *TestPage code*

## License

This project is licensed under GNU GPL V3 - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

The original DigiSafe concept team
* **Caoni**
* **Giovanni**
* **Nisan**
* **sosickofplaying**
* **Marvin**
