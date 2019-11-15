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
int screenHeight = 225;
int screenWidth = 475;
// define your global instances of motors and other devices here


int main() {   
      do {
        Brain.Screen.clearScreen();
        /*
        for(int i = 0; i < 1000;i++){
            for(int j = 0; j < 500;j++){
              vex::color c;
              c = color(i%50,0,0);
              Brain.Screen.setPenColor(c);
              Brain.Screen.drawPixel(i,j);
              
            }
        }
        // Allow other tasks to run
        //this_thread::sleep_for(100);
        */
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
        
    }while(0);
}
