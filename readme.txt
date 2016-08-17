ABOUT PROJECT:

Project name: "Demo of EA-XPR-021 features"

Project purpose: 
- Demonstrate the functionality of each feature of the expansion board
- Implement a module for each functionality

Project structure:
Consider the following demo functions (the demo number will be displayed on the segment digit):
0: Idle state
1: Temperature (display on LCD display the ambient temperature). By pressing a push button, change from C to F
2: RGB LED demo (make the LED change with a random frequency the color)
3: Joystick demo (control the buzzer sound by joystick movement). If the joystick is pressed up/down, 
increase/drecrease volume. If the joystick is pressed left/right, increase/decrease frequency. 

Switch through the cases 0-3 using the rotary encoder. Warp around between demo programs 0 and 3 

The project makes use of code from the following library projects
- CMSISv1p30_LPC13xx : for CMSIS 1.30 files relevant to LPC13xx
- Lib_FatFs_SD       : for control module and FAT file system module
- MCU_Lib            : for LPC13xx peripheral driver files
- EaBaseBoard_Lib    : for Embedded Artists LPCXpresso Base Board peripheral drivers

These library projects must exist in the same workspace in order
for the project to successfully build.

MEMBERS:

Rosian Rad         Module: Joystick, Integration
Tudor Bradescu     Module: OLED, Debouncer
Florin Brumar      Module: Temperature, Pushbutton
Dorin Deac         Module: RGB LED, Rottary button
Ioan Bobar         Module: Buzzer, RGB LED
Vlad Florica       Module: Segment display module

DONE SO FAR:

Integrate RGB module.

TO BE DONe:

Integrate Buzzer and Joystick module.
Integrate OLED, TEMP and PUSH_B modules.
After integration, optimization.