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

//units


vex::brain Brain = vex::brain();
vex::controller Controller = vex::controller();

vex::motor driveLeftFront = vex::motor(vex::PORT19,vex::gearSetting::ratio18_1);
vex::motor driveRightFront = vex::motor(vex::PORT9,vex::gearSetting::ratio18_1,true);


vex::motor lift1 = vex::motor(vex::PORT10,vex::gearSetting::ratio18_1);
vex::motor lift2 = vex::motor(vex::PORT18,vex::gearSetting::ratio18_1,true);
vex::motor raise = vex::motor(vex::PORT2,vex::gearSetting::ratio18_1,true);