/*
  Joemama 2019
  See the readme for credit to other people.
  
  Training mode file template.
  This file explains the current organization 
  and structure of most files as of 3/3/2019
  However, there are many problems with this
  template and I plan to change it ASAP. If you
  have suggestions or new ways to organize 
  file structure please let me know or create 
  a PR!
*/

// Include for the nintendo library
#include <Nintendo.h>
// Include for the LCD. The doc can be found here:
// https://github.com/andatche/arduino-lcd03
#include <Wire.h>
#include <LCD03.h>

// Define the pins the console and controller are 
// plugged into
CGamecubeController controller(4);
CGamecubeConsole console(3);

// Create a gamecube object. This is used to 
// write commands to the console.
Gamecube_Data_t d;

int functionIndex = 0;
int numFunctions = 3;

// Create new LCD03 instance
LCD03 lcd;
void setup() {
  // Initialise a 20x4 LCD
  lcd.begin(20, 4);

  // Turn on the backlight
  lcd.backlight();

  // Write to the LCD
  lcd.print("Joemama's Training  Mod... TEMPLATE");
  controller.read();
  pinMode(LED_BUILTIN, OUTPUT);
  d = defaultGamecubeData;
  d.report.origin = 0;
  Serial.begin(9600);
}

void loop() {
  switchFunction();
}

void switchFunction() {
  delay(500);
  if (functionIndex == numFunctions) {
    functionIndex = 0;
  }
  else {
    functionIndex++;
  }
  selectFunction();
}



void noFunction() {
  lcd.clear();
  lcd.home();
  lcd.print("No Function");
  delay(500);
  while (true) {
    controller.read();
    auto report = controller.getReport();
    if (report.dright == 1) {
      break;
    }
  }
  return;
}

void trainingFuncOne() {
  lcd.clear();
  lcd.home();
  lcd.print("Function 1");
  delay(500);
  while (true) {
    controller.read();
    auto report = controller.getReport();
    if (report.dright == 1) {
      break;
    }
    else if (report.ddown == 1) {
      pause();
    }
  }
  return;
}
void trainingFuncTwo() {
  lcd.clear();
  lcd.home();
  lcd.print("Function 2");
  delay(500);
  while (true) {
    controller.read();
    auto report = controller.getReport();
    if (report.dright == 1) {
      break;
    }
    else if (report.ddown == 1) {
      pause();
    }
  }
  return;
}
void trainingFuncThree() {
  lcd.clear();
  lcd.home();
  lcd.print("Function 3");
  delay(500);
  while (true) {
    controller.read();
    auto report = controller.getReport();
    if (report.dright == 1) {
      break;
    }
    else if (report.ddown == 1) {
      pause();
    }
  }
  return;
}

void selectFunction() {
  switch (functionIndex) {
    case 1:
      trainingFuncOne();
      break;
    case 2:
      trainingFuncTwo();
      break;
    case 3:
      trainingFuncThree();
      break;
    default:
      noFunction();
      break;
  }
}

void pause() {
  lcd.clear();
  lcd.home();
  lcd.print("Paused");
  delay(500);
  while (true) {
    controller.read();
    auto report = controller.getReport();
    if (report.ddown == 1) {
      break;
    }
  }
  selectFunction();
  return;
}
