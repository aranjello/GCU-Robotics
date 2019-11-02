/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\aranjello                                        */
/*    Created:      Wed Oct 16 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;
competition Comp;

int divisor = 1;
int speed = 50;
int grabSpeed = 50;
// A global instance of vex::brain used for printing to the V5 brain screen

// define your global instances of motors and other devices here

void grab(int v){
  grabberLeft.spin(fwd,v,pct);
  grabberRight.spin(fwd,v,pct);
}

void release(int v){
  grabberLeft.spin(fwd,-v,pct);
  grabberRight.spin(fwd,-v,pct);

}

void stop(){
  grabberLeft.spin(fwd,0,pct);
  grabberRight.spin(fwd,0,pct);
}

void buttonADown(){
  grab(grabSpeed);
}
void buttonAUp(){
  stop();
}

void buttonBDown(){
  release(grabSpeed);
}

void buttonBUp(){
  stop();
}

void leftWheels(int speed){
    frontLeft.spin(fwd,speed/divisor,pct);
    backLeft.spin(fwd,speed/divisor,pct);
}
void rightWheels(int speed){
    frontRight.spin(fwd,speed/divisor,pct);
    backRight.spin(fwd,speed/divisor,pct);
}

void buttonUpDown(){
  armRaise1.spin(fwd,speed,pct);
  armRaise2.spin(fwd,speed,pct);
}

void buttonUpUp(){
  armRaise1.spin(fwd,0,pct);
  armRaise2.spin(fwd,0,pct);
}

void buttonDownDown(){
  armRaise1.spin(directionType::rev,speed,pct);
  armRaise2.spin(directionType::rev,speed,pct);
}

void buttonDownUp(){
  armRaise1.spin(fwd,0,pct);
  armRaise2.spin(fwd,0,pct);
}

void sensitivityUp(){
  divisor++;
}
void sensitivityDown(){
  if(divisor>1){
    divisor--;
  }
}

void usercontrol(){
  Controller.ButtonR1.pressed(buttonADown);
    Controller.ButtonR1.released(buttonAUp);
    Controller.ButtonR2.pressed(buttonBDown);
    Controller.ButtonR2.released(buttonBUp);
    Controller.ButtonL1.pressed(buttonUpDown);
    Controller.ButtonL1.released(buttonUpUp);
    Controller.ButtonL2.pressed(buttonDownDown);
    Controller.ButtonL2.released(buttonDownUp);
    Controller.ButtonA.pressed(sensitivityUp);
    Controller.ButtonB.pressed(sensitivityDown);
    int count = 0;
    while(1) {
        
        // Allow other tasks to run
        rightWheels(Controller.Axis2.value());
        leftWheels(Controller.Axis3.value());
        if(count > 5){
          Controller.Screen.clearScreen();
          count = 0;
        }
        count++;
        Controller.Screen.print("sensititviy: %d",divisor);
    }
}

void autonomous(){

}

void pre_auton(){
  
}

int main() {
  pre_auton();

  Comp.autonomous(autonomous);
  Comp.drivercontrol(usercontrol);
    
}
