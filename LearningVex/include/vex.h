/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

vex::brain Brain = vex::brain();
vex::controller Controller = vex::controller();



vex::motor frontRight = vex::motor(vex::PORT19,vex::gearSetting::ratio18_1,true);
vex::motor frontLeft = vex::motor(vex::PORT2,vex::gearSetting::ratio18_1);
vex::motor backRight = vex::motor(vex::PORT20,vex::gearSetting::ratio18_1,true);
vex::motor backLeft = vex::motor(vex::PORT11,vex::gearSetting::ratio18_1);
vex::motor armRaise1 = vex::motor(vex::PORT13,vex::gearSetting::ratio18_1);
vex::motor armRaise2 = vex::motor(vex::PORT15,vex::gearSetting::ratio36_1);
vex::motor grabberLeft = vex::motor(vex::PORT9,vex::gearSetting::ratio18_1,true);
vex::motor grabberRight = vex::motor(vex::PORT10,vex::gearSetting::ratio18_1);

