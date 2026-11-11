/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void north(double seconds){
  FR.spin(forward, 50, pct);
  FL.spin(forward, 55, pct);
  RR.spin(forward, 55, pct);
  RL.spin(forward, 50, pct);

  wait(seconds, sec);

  FR.stop();
  FL.stop();
  RR.stop();
  RL.stop();
}
void south(double seconds){
  FR.spin(reverse, 50, pct);
  FL.spin(reverse, 55, pct);
  RR.spin(reverse, 55, pct);
  RL.spin(reverse, 50, pct);

  wait(seconds, sec);

  FR.stop();
  FL.stop();
  RR.stop();
  RL.stop();
}
void east(double seconds){
  FR.spin(reverse, 50, pct);
  FL.spin(forward, 55, pct);
  RR.spin(forward, 55, pct);
  RL.spin(reverse, 50, pct);

  wait(seconds, sec);

  FR.stop();
  FL.stop();
  RR.stop();
  RL.stop();
}
void west(double seconds){
  FR.spin(forward, 50, pct);
  FL.spin(reverse, 55, pct);
  RR.spin(reverse, 55, pct);
  RL.spin(forward, 50, pct);

  wait(seconds, sec);

  FR.stop();
  FL.stop();
  RR.stop();
  RL.stop();
}
void northeast(double seconds){
  FL.spin(forward, 55, pct);
  RR.spin(forward, 55, pct);

  wait(seconds, sec);

  FR.stop();
  FL.stop();
  RR.stop();
  RL.stop();
}
void southwest(double seconds){
  FL.spin(reverse, 55, pct);
  RR.spin(reverse, 55, pct);

  wait(seconds, sec);

  FL.stop();
  RR.stop();
}
void northwest(double seconds){
  FR.spin(forward, 50, pct);
  RL.spin(forward, 50, pct);

  wait(seconds, sec);

  FR.stop();
  RL.stop();
}
void southeast(double seconds){
  FR.spin(reverse, 50, pct);
  RL.spin(reverse, 50, pct);

  wait(seconds, sec);

  FR.stop();
  RL.stop();
}
void rotateCW(double seconds){
  FR.spin(reverse, 50, pct);
  FL.spin(forward, 55, pct);
  RR.spin(reverse, 55, pct);
  RL.spin(forward, 50, pct);

  wait(seconds, sec);

  FR.stop();
  FL.stop();
  RR.stop();
  RL.stop();
}
void rotateCCW(double seconds){
  FR.spin(forward, 50, pct);
  FL.spin(reverse, 55, pct);
  RR.spin(forward, 55, pct);
  RL.spin(reverse, 50, pct);

  wait(seconds, sec);

  FR.stop();
  FL.stop();
  RR.stop();
  RL.stop();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  north(1);
  wait(0.5, sec);
  south(1);
  wait(0.5, sec);
  east(1);
  wait(0.5, sec);
  west(1);
  wait(0.5, sec);
  northeast(1);
  wait(0.5, sec);
  southwest(1);
  wait(0.5, sec);
  southeast(1);
  wait(0.5, sec);
  northwest(1);
  wait(0.5, sec);
  rotateCW(1);
  wait(0.5, sec);
  rotateCCW(1);

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  autonomous();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
