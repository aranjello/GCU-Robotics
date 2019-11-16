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
vex::brain       Brain;
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
Brain.Screen.setFillColor(c);
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
  Brain.Screen.drawRectangle(x,y,bWidth,bHeight);
  char p[text.length()];
  int i; 
  for (i = 0; i < sizeof(p); i++) { 
    p[i] = text[i]; 
  } 
  Brain.Screen.printAt(px,py,p);
}

int main() {   
      do {
        Brain.Screen.clearScreen();
        /*
        color c = color(255,0,0);
        Brain.Screen.setFillColor(c);
        Brain.Screen.drawRectangle(0, 0, screenWidth/2, screenHeight/2);
        Brain.Screen.printAt(0,screenHeight/4,"Section 1");

        c = color(0,255,0);
        Brain.Screen.setFillColor(c);
        Brain.Screen.drawRectangle(screenWidth/2, 0, screenWidth/2, screenHeight/2);
        Brain.Screen.printAt(0,screenHeight/4*3,"section 2");

        c = color(0,0,255);
        Brain.Screen.setFillColor(c);
        Brain.Screen.drawRectangle(0, screenHeight/2, screenWidth/2, screenHeight/2);
        Brain.Screen.printAt(screenWidth/2,screenHeight/4,"Section 3");

        c = color(255,255,0);
        Brain.Screen.setFillColor(c);
        Brain.Screen.drawRectangle(screenWidth/2, screenHeight/2, screenWidth/2, screenHeight/2);
        Brain.Screen.printAt(screenWidth/2,screenHeight/4*3,"Section 4");
        Brain.Screen.drawLine(0, screenHeight/2, screenWidth, screenHeight/2);
        Brain.Screen.drawLine(screenWidth/2,0,screenWidth/2,screenHeight);
        */
        drawQuadrantRect(1,color::red,"quad 1");
        drawQuadrantRect(2,color::green,"quad 2");
        drawQuadrantRect(3,color::blue,"quad 3");
        drawQuadrantRect(4,color::yellow,"quad 4");
        drawQuadrantRect(5, color::white, "quad 5");
    }while(0);
}


