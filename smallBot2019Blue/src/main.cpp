/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\aranjello                                        */
/*    Created:      Sat Oct 26 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

competition Comp;
//determines the sensitivity level of the robot by adjusting speed
int divisor = 1;
//the maximum speed the robot can move at
int speed = 50;
//the speed of the grabbers
int grabspeed = 50;

//When the A button is pressed, spin the grabbers at grabspeed
void APressed(){
  lift1.spin(fwd,grabspeed,pct);
  lift2.spin(fwd,grabspeed,pct);
}
//When the A button is released, stop the grabber motors
void AReleased(){
  lift1.spin(fwd,0,pct);
  lift2.spin(fwd,0,pct);
}
//When the B button is pressed, spin the grabbers in reverse at grabspeed
void BPressed(){
  lift1.spin(fwd,grabspeed*-1,pct);
  lift2.spin(fwd,grabspeed*-1,pct);
}
//When the B button is released, stop the grab motors
void BReleased(){
  lift1.spin(fwd,0,pct);
  lift2.spin(fwd,0,pct);
}
//When the Up button is pressed, spin the raise motor at 10% speed
void UPPressed(){
  raise.spin(fwd,10,pct);
}
//When the Up button is released, stop the raise motor
void UPReleased(){
  raise.spin(fwd,0,pct);
}
//When the Down button is pressed, spin the raise motor in reverse at 10% speed
void DownPressed(){
  raise.spin(fwd,-10,pct);
}
//When the Down button is released, stop the raise motor
void DownReleased(){
  raise.spin(fwd,0,pct);
}
//Initializtion code to run before autonomous
void pre_auton(){

}
//Code to run for autonomous
void autonomous(){
  raise.startRotateFor(-.5,vex::rotationUnits::rev);
  driveLeftFront.startRotateFor(2, vex::rotationUnits::rev);
  driveRightFront.rotateFor(2, vex::rotationUnits::rev);
  driveLeftFront.startRotateFor(-.6,vex::rotationUnits::rev);
  driveRightFront.rotateFor(.6, vex::rotationUnits::rev);
  driveLeftFront.startRotateFor(2,vex::rotationUnits::rev);
  driveRightFront.rotateFor(2,vex::rotationUnits::rev);\
  driveLeftFront.startRotateFor(-.6,vex::rotationUnits::rev);
  driveRightFront.rotateFor(.6, vex::rotationUnits::rev);
  driveLeftFront.startRotateFor(2, vex::rotationUnits::rev);
  driveRightFront.rotateFor(2, vex::rotationUnits::rev);
  raise.startRotateFor(.5, vex::rotationUnits::rev);
  lift1.startRotateFor(-5,vex::rotationUnits::rev);
  lift2.startRotateFor(-5,vex::rotationUnits::rev);

}
//Spin the left wheels at a speed that represents a % of full speed(100 = full speed, 50 = half speed)
void leftWheels(int speed){
    driveLeftFront.spin(fwd,speed/divisor,pct);
}
//Spin the right wheels at a speed that represents a % of full speed(100 = full speed, 50 = half speed)
void rightWheels(int speed){
    driveRightFront.spin(fwd,speed/divisor,pct);
}
//adjusts the sensitivity setting to make it more sensitive to input
void sensitivityUp(){
  divisor++;
}
//adjust the sensitivity setting to make it less sensitive to movement, will not go below 1
void sensitivityDown(){
  if(divisor>1){
    divisor--;
  }
}
//Sets up button interupts and movement checks
void usercontrol(){
  Controller.ButtonA.pressed(APressed);
    Controller.ButtonA.released(AReleased);
    Controller.ButtonB.pressed(BPressed);
    Controller.ButtonB.released(BReleased);
    Controller.ButtonUp.pressed(UPPressed);
    Controller.ButtonUp.released(UPReleased);
    Controller.ButtonDown.pressed(DownPressed);
    Controller.ButtonDown.released(DownReleased);
    Controller.ButtonLeft.pressed(sensitivityUp);
    Controller.ButtonRight.pressed(sensitivityDown);
    int count = 0;
    while (true) {
        //drive
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

int main() {
    
     //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Comp.autonomous( autonomous );
    Comp.drivercontrol( usercontrol);

    //Prevent main from exiting with an infinite loop.                        
    while(1) {
        //Sleep the task for a short amount of time to prevent wasted resources.
        vex::task::sleep(1000);
    }
}