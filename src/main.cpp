/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cosmo                                            */
/*    Created:      Wed Oct 11 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// front_left           motor         1              
// front_right          motor         10             
// back_left            motor         11             
// back_right           motor         20             
// Controller1          controller                   
// catapult             motor         3              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"

using namespace vex;

int main() {
    // Initializing Robot Configuration. DO NOT REMOVE!
    vexcodeInit();

    while (true) {
        // Drive control
        front_left.spin(forward, Controller1.Axis3.position(percent), percent);
        back_left.spin(reverse, Controller1.Axis3.position(percent), percent);
        front_right.spin(forward, Controller1.Axis2.position(percent), percent);
        back_right.spin(reverse, Controller1.Axis2.position(percent), percent);

        // Catapult control
        if (Controller1.ButtonL1.pressing()) {
            catapult.spin(reverse);
        } else {
            catapult.stop();
        }
    }

    // Ensuring motors are stopped at the end of the program
    front_left.stop();
    back_left.stop();
    front_right.stop();
    back_right.stop();
}
