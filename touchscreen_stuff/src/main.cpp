// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor1               motor         1               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// To complete the VEXcode V5 Text project upgrade process, please follow the
// steps below.
// 
// 1. You can use the Robot Configuration window to recreate your V5 devices
//   - including any motors, sensors, 3-wire devices, and controllers.
// 
// 2. All previous code located in main.cpp has now been commented out. You
//   will need to migrate this code to the new "int main" structure created
//   below and keep in mind any new device names you may have set from the
//   Robot Configuration window. 
// 
// If you would like to go back to your original project, a complete backup
// of your original (pre-upgraded) project was created in a backup folder
// inside of this project's folder.

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\aranjello                                        */
/*    Created:      Thu Nov 14 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "vex_color.h"

using namespace vex;
using namespace std;

// A global instance of vex::brain used for printing to the V5 brain screen
/*defined screen width and height through trial and error, values may not be 100%
correct but are close enought to not be notible when drawing to the screen
|---------------------------|
|*(0,0)                     |
|                           |
|                           |
|                           |
|                           |
|(screenWidth,ScreenHeight)*|
|---------------------------|*/
int screenHeight = 225;
int screenWidth = 475;

/* this function takes in a quadrant number (1-4), a color, and a string and creates
a rectangle of the color in the quadrant specified with the string printed on top.
If a quadrant that is not defined is passed in, an error message will appear on screen*/
void drawQuadrantRect(int quad,color c, string text){

int x,y,bWidth,bHeight,px,py;
bWidth = screenWidth/2;
bHeight = screenHeight/2;
switch(quad){
  case 1:
    x = 0;
    y = 0;
    px = 0;
    py = screenHeight/4;
    break;
  case 2:
    x = screenWidth/2;
    y = 0;
    px = screenWidth/2;
    py = screenHeight/4;
    break;
  case 3:
    x = 0;
    y = screenHeight/2;
    px = 0;
    py = screenHeight/4*3;
    break;
  case 4:
    x = screenWidth/2;
    y = screenHeight/2;
    px = screenWidth/2;
    py = screenHeight/4*3;
    break;
  default:
    x = screenWidth/4;
    y = screenHeight/4;
    px = screenWidth/4;
    py = screenHeight/2;
    text = "error passed in value that was not 1-4 for quadrant";
    c = color::red;
  }
  Brain.Screen.setFillColor(c);
  Brain.Screen.drawRectangle(x,y,bWidth,bHeight);
  char cs[text.length()];
  strcpy(cs, text.c_str()); 
  Brain.Screen.printAt(px,py,cs);
}

int checkTouch(){
  while(!Brain.Screen.pressing());
  int x = Brain.Screen.xPosition();
  int y = Brain.Screen.yPosition();
  if(x<screenWidth/2&&y<screenHeight/2){
    return 1;
  }else if(x>screenWidth/2&&y<screenHeight/2){
    return 2;
  }else if(x<screenWidth/2&&y>screenHeight/2){
    return 3;
  }else if(x>screenWidth/2&&y>screenHeight/2){
    return 4;
  }
  return 0;
}

int main() {   
    Brain.Screen.clearScreen();
    drawQuadrantRect(1,color::red,"quad 1");
    drawQuadrantRect(2,color::green,"quad 2");
    drawQuadrantRect(3,color::blue,"quad 3");
    drawQuadrantRect(4,color::yellow,"quad 4");
    color c;
    while(1){
      switch(checkTouch()){
        case 1:
        c = color::red;
        break;
        case 2:
        c = color::green;
        break;
        case 3:
        c = color::blue;
        break;
        case 4:
        c = color::yellow;
        break;
        default:
        c = color::orange;
        break;
      }
      Brain.Screen.setFillColor(c);
      Brain.Screen.drawRectangle(0,0,screenWidth,screenHeight);
      while(Brain.Screen.pressing());
      drawQuadrantRect(1,color::red,"quad 1");
      drawQuadrantRect(2,color::green,"quad 2");
      drawQuadrantRect(3,color::blue,"quad 3");
      drawQuadrantRect(4,color::yellow,"quad 4");
    }
    
}