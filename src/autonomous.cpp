#include "vex.h"

using namespace vex;

int main() {
    // Initializing the VEX V5 components
    brain Brain;
    motor leftMotor = motor(PORT1);
    motor rightMotor = motor(PORT2);

    // Set motor velocity and acceleration
    leftMotor.setVelocity(50, velocityUnits::pct);
    rightMotor.setVelocity(50, velocityUnits::pct);
    leftMotor.setStopping(brakeType::brake);
    rightMotor.setStopping(brakeType::brake);

    // Move the robot forward for 2 seconds
    leftMotor.spin(directionType::fwd);
    rightMotor.spin(directionType::fwd);
    wait(2000, msec);

    // Stop the motors
    leftMotor.stop();
    rightMotor.stop();

    // Additional autonomous actions can be added here

    return 0;
}
