

#include "vex.h"

using namespace vex;

competition Comp;
//determines the sensitivity level of the robot by adjusting speed
int divisor = 1;
//the maximum speed the robot can move at
int speed = 50;
//the speed of the grabbers
int grabspeed = 50;

//When driving forward we should use both sides and devide the values to obtain a accurate value
void DriveForward(double Vel, double Dis)
{
  driveLeftFront.setRotation( 0,vex::rotationUnits::rev);
  driveRightFront.setRotation( 0,vex::rotationUnits::rev);

  if ((driveLeftFront.rotation(vex::rotationUnits::rev) + driveRightFront.rotation(vex::rotationUnits::rev)/2) < Dis)
  {
  driveLeftFront.startRotateFor( vex::directionType::fwd, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct); 
  driveRightFront.startRotateFor( vex::directionType::fwd, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct); 
  }
  else
  //quickstop
  driveLeftFront.isDone();
  driveRightFront.isDone();
  driveLeftFront.stop();
  driveRightFront.stop();
}
void DriveBackward(double Vel, double Dis)
{
  driveLeftFront.setRotation( 0,vex::rotationUnits::rev);
  driveRightFront.setRotation( 0,vex::rotationUnits::rev);

  if ((driveLeftFront.rotation(vex::rotationUnits::rev) + driveRightFront.rotation(vex::rotationUnits::rev)/2) < Dis)
  {
  driveLeftFront.startRotateFor( vex::directionType::rev, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct); 
  driveRightFront.startRotateFor( vex::directionType::rev, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct); 
  }
  else
  //quickstop
  driveLeftFront.isDone();
  driveRightFront.isDone();
  driveLeftFront.stop();
  driveRightFront.stop();
}
void LeftTurn(double Vel, double Dis)
{
  if ((driveLeftFront.rotation(vex::rotationUnits::rev) + driveRightFront.rotation(vex::rotationUnits::rev)/2) < Dis)
  {
  driveLeftFront.startRotateFor( vex::directionType::rev, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct); 
  driveRightFront.startRotateFor( vex::directionType::fwd, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct); 
  }
  //quickstop
  driveLeftFront.isDone();
  driveRightFront.isDone();
  driveLeftFront.stop();
  driveRightFront.stop();
}
void RightTurn(double Vel, double Dis)
{
  if ((driveLeftFront.rotation(vex::rotationUnits::rev) + driveRightFront.rotation(vex::rotationUnits::rev)/2) < Dis)
  {
  driveLeftFront.startRotateFor( vex::directionType::fwd, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct); 
  driveRightFront.startRotateFor( vex::directionType::rev, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct); 
  }
  //quickstop
  driveLeftFront.isDone();
  driveRightFront.isDone();
  driveLeftFront.stop();
  driveRightFront.stop();
}
void Raise(double Vel, double Dis)
{
  raise.startRotateFor( vex::directionType::fwd, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct); 
  raise.isDone();
  raise.stop();
}
void lower(double Vel, double Dis)
{
  raise.startRotateFor( vex::directionType::rev, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct); 
  raise.isDone();
  raise.stop();
}
void lift12(double Vel,double Dis )
{
  lift1.startRotateFor( vex::directionType::rev, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct);
  lift1.startRotateFor( vex::directionType::rev, Dis, vex::rotationUnits::rev,Vel, vex::velocityUnits::pct);  
}
//
//adjusts the sensitivity setting to make it more sensitive to input
void sensitivityUp()
{
  divisor++;
}
//adjust the sensitivity setting to make it less sensitive to movement, will not go below 1
void sensitivityDown()
{
  if(divisor>1)
  {
    divisor--;
  }
}

void UserC()
{
    while(Controller.ButtonA.pressing())
    {
      lift1.spin(fwd,grabspeed,pct);
      lift2.spin(fwd,grabspeed,pct);
    }
    while(Controller.ButtonB.pressing())
    {
      lift1.spin(fwd,grabspeed*-1,pct);
      lift2.spin(fwd,grabspeed*-1,pct);
    }
    while(Controller.ButtonUp.pressing())
    {
      raise.spin(fwd,10,pct);
    }
   
    while(Controller.ButtonDown.pressing())
    {
      raise.spin(fwd,-10,pct);
    }
    Controller.ButtonLeft.pressed(sensitivityUp);
    Controller.ButtonRight.pressed(sensitivityDown);
}

void BlueAuton()
{
  DriveForward(2,100);
  DriveForward(6,100);
  DriveForward(2,100);
  DriveForward(6,100);
  DriveForward(2,100);
}
//Initializtion code to run before autonomous
void pre_auton()
{
}
//Code to run for autonomous
void autonomous()
{
  lower(.5,25);
  Raise(.5,25);
  lift12(.5,25);
}
//Sets up button interupts and movement checks
void usercontrol()
{
 
    int count = 0;
    while (true)
     {
        //drive
        UserC();
        driveLeftFront.spin(directionType::fwd,(Controller.Axis2.value()+ Controller.Axis3.value())/2,velocityUnits::pct);
        driveLeftFront.spin(directionType::rev,(Controller.Axis2.value()+ Controller.Axis3.value())/2,velocityUnits::pct);
        driveRightFront.spin(directionType::fwd,(Controller.Axis2.value()+ Controller.Axis3.value())/2,velocityUnits::pct);
        driveRightFront.spin(directionType::rev,(Controller.Axis2.value()+ Controller.Axis3.value())/2,velocityUnits::pct);
        if(count > 5){
          Controller.Screen.clearScreen();
          count = 0;
        }
        count++;
        Controller.Screen.print("sensititviy: %d",divisor);
    }
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Comp.autonomous( autonomous );
    Comp.drivercontrol( usercontrol);

    //Prevent main from exiting with an infinite loop.                        
    while(1) 
    {
        //Sleep the task for a short amount of time to prevent wasted resources.
        vex::task::sleep(1000);
    }
}
