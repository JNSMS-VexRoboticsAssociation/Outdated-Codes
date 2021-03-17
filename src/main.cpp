/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor1               motor         1               
// Motor2               motor         2               
// Motor3               motor         3               
// Motor4               motor         4               
// Motor5               motor         5               
// Motor6               motor         6               
// Motor7               motor         7               
// Motor8               motor         8               
// Vision15             vision        15              
// Inertial             inertial      20              
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

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int speed = 80;
int stoptime = 300;

void stop() {
    Motor1.stop();
    Motor2.stop();
    Motor3.stop();
    Motor4.stop();
}

void ds(int ldegrees, int rdegrees, int speed) {   //按照度数前进
    Motor1.rotateTo(ldegrees, rotationUnits::deg, speed, velocityUnits::pct, false);
    Motor2.rotateTo(ldegrees, rotationUnits::deg, speed, velocityUnits::pct, false);
    Motor3.rotateTo(rdegrees, rotationUnits::deg, speed, velocityUnits::pct, false);
    Motor4.rotateTo(rdegrees, rotationUnits::deg, speed, velocityUnits::pct, false);
}

void sj(int time, int l, int r) {     //设置时间
    Motor1.spin(forward, l, velocityUnits::pct);
    Motor2.spin(forward, r, velocityUnits::pct);
    Motor3.spin(forward, l, velocityUnits::pct);
    Motor4.spin(forward, r, velocityUnits::pct);

    task::sleep(time);
    stop();
}

void tly() {    //陀螺仪使用
    vexcodeInit();//初始化机器人配置

    Inertial.calibrate();//校准陀螺仪
    waitUntil(!Inertial.isCalibrating());

    Inertial.setRotation(0, degrees);//将陀螺仪的航向设置为0
    //Inertial.heading(0,degrees);

}

void xi(int time, int L, int R) {
    Motor5.spin(forward, L, velocityUnits::pct);
    Motor6.spin(forward, R, velocityUnits::pct);
    Motor7.spin(reverse, L, velocityUnits::pct);
    Motor8.spin(reverse, R, velocityUnits::pct);
    task::sleep(time);
    Motor5.stop();
    Motor6.stop();
    Motor7.stop();
    Motor8.stop();
    //下吸上吐
}

void tui(int time, int a, int b) {
    Motor1.spin(reverse, a, velocityUnits::pct);
    Motor2.spin(reverse, b, velocityUnits::pct);
    Motor3.spin(reverse, a, velocityUnits::pct);
    Motor4.spin(reverse, b, velocityUnits::pct);
    Motor5.spin(reverse, a, velocityUnits::pct);
    Motor6.spin(reverse, b, velocityUnits::pct);
    task::sleep(time);
    Motor1.stop();
    Motor2.stop();
    Motor3.stop();
    Motor4.stop();
    Motor5.stop();
    Motor6.stop();
    //四轮退，前吐
}

void hou(int time, int c, int d) {
    Motor7.spin(reverse, c, velocityUnits::pct);
    Motor8.spin(forward, d, velocityUnits::pct);
    task::sleep(time);
    Motor7.stop();
    Motor8.stop();
    //向后吐
}


void autonomous(void) {
    xi(100, 80, 80);
    sj(500, 80, 80);
    xi(1400, 80, 80);
    Motor7.spin(reverse, 80, velocityUnits::pct);
    Motor8.spin(reverse, 80, velocityUnits::pct);
    task::sleep(500);
    Motor7.stop();
    Motor8.stop();
    Motor5.spin(reverse, 80, velocityUnits::pct);
    Motor6.spin(reverse, 80, velocityUnits::pct);
    task::sleep(500);
    Motor5.stop();
    Motor6.stop();

    Motor7.spin(forward, 80, velocityUnits::pct);
    Motor8.spin(forward, 80, velocityUnits::pct);
    task::sleep(500);
    Motor7.stop();
    Motor8.stop();

    wait(0.5, seconds);
    tui(500, 80, 80);
    hou(1000, 80, 80);
    ////一坨自动程序·····


    // ..........................................................................
    // Insert autonomous user code here.
    // ..........................................................................
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
        int a = Controller1.Axis3.value();
        int b = Controller1.Axis2.value();
        if (abs(a) > 15 || abs(b) > 15) {
            if (abs(a) <= 15)
                a = 0;
            if (abs(b) <= 15)
                b = 0;

            Motor1.spin(directionType::fwd, a, velocityUnits::pct);
            Motor3.spin(directionType::fwd, a, velocityUnits::pct);
            Motor2.spin(directionType::fwd, b, velocityUnits::pct);
            Motor4.spin(directionType::fwd, b, velocityUnits::pct);


        } else {
            Motor1.stop();
            Motor3.stop();
            Motor2.stop();
            Motor4.stop();
        }



        /*if (Controller1.ButtonL1.pressing()){
           Motor5.spin(directionType::fwd,100,velocityUnits::pct);
           Motor6.spin(directionType::fwd,100,velocityUnits::pct)
           }
          else if(Controller1.ButtonL2.pressing()){
           Motor5.spin(directionType::rev,100,velocityUnits::pct);
           Motor6.spin(directionType::rev,100,velocityUnits::pct);
           }
          else{
            Motor5.stop();
            Motor6.stop();
          }*/

        if (Controller1.ButtonL1.pressing()) {
            Motor5.spin(forward, 100, velocityUnits::pct);

        } else if (Controller1.ButtonL2.pressing()) {
            Motor5.spin(reverse, 100, velocityUnits::pct);
        } else {
            Motor5.stop();
        }

        Controller1.ButtonL1.pressing() ? Motor5.spin(directionType::fwd, 100, velocityUnits::pct) : \
    Controller1.ButtonL2.pressing() ? Motor5.spin(directionType::rev, 100, velocityUnits::pct) : Motor5.stop();

        Controller1.ButtonL1.pressing() ? Motor6.spin(directionType::fwd, 100, velocityUnits::pct) : \
    Controller1.ButtonL2.pressing() ? Motor6.spin(directionType::rev, 100, velocityUnits::pct) : Motor6.stop();


        Controller1.ButtonR2.pressing() ? Motor7.spin(directionType::fwd, 100, velocityUnits::pct) : \
    Controller1.ButtonR1.pressing() ? Motor7.spin(directionType::rev, 100, velocityUnits::pct) : \
    Controller1.ButtonDown.pressing() ? Motor7.spin(directionType::rev, 100, velocityUnits::pct) : Motor7.stop();

        Controller1.ButtonR2.pressing() ? Motor8.spin(directionType::fwd, 100, velocityUnits::pct) : \
    Controller1.ButtonR1.pressing() ? Motor8.spin(directionType::rev, 100, velocityUnits::pct) : \
    Controller1.ButtonDown.pressing() ? Motor8.spin(directionType::fwd, 100, velocityUnits::pct) : Motor8.stop();


        if (Controller1.ButtonY.pressing()) {
            xi(100, 80, 80);
            tui(600, -80, -80);
            xi(1400, 80, 80);
            Motor7.spin(reverse, 80, velocityUnits::pct);
            Motor8.spin(reverse, 80, velocityUnits::pct);
            task::sleep(500);
            Motor7.stop();
            Motor8.stop();
            /*Motor5.spin(reverse,80,velocityUnits::pct);
            Motor6.spin(reverse,80,velocityUnits::pct);
            task::sleep(500);
            Motor5.stop();
            Motor6.stop();*/

            Motor7.spin(forward, 80, velocityUnits::pct);
            Motor8.spin(forward, 80, velocityUnits::pct);
            task::sleep(500);
            Motor7.stop();
            Motor8.stop();

            wait(0.5, seconds);
            tui(500, 80, 80);
            hou(1000, 80, 80);
            ////一坨自动程序·····
        }

        /* if(Controller1.ButtonA.pressing()){
          xi(100,80,80);
          tui(500,-80,-80);
          xi(1400,80,80);
          Motor7.spin(reverse,80,velocityUnits::pct);
          Motor8.spin(reverse,80,velocityUnits::pct);
          task::sleep(500);
          Motor7.stop();
          Motor8.stop();
          Motor5.spin(reverse,80,velocityUnits::pct);
          Motor6.spin(reverse,80,velocityUnits::pct);
          task::sleep(500);
          Motor5.stop();
          Motor6.stop();

          Motor7.spin(forward,80,velocityUnits::pct);
          Motor8.spin(forward,80,velocityUnits::pct);
          task::sleep(500);
          Motor7.stop();
          Motor8.stop();

          wait(0.5, seconds);
          tui(1900,80,80);
          sj(270,80,-80);//转弯
          hou(1000,80,80);
          sj(1000,80,80);
          xi(400,80,80);
          sj(200,-80,-80);
          tui(250,-80,-80);
          xi(1000,80,80);
          Motor7.spin(reverse,80,velocityUnits::pct);
          Motor8.spin(reverse,80,velocityUnits::pct);
          task::sleep(800);
          Motor7.stop();
          Motor8.stop();
          tui(500,80,80);

         }


         if(Controller1.ButtonX.pressing()){
          xi(100,80,80);
          sj(500,80,80);
          xi(1400,80,80);
          Motor7.spin(reverse,80,velocityUnits::pct);
          Motor8.spin(reverse,80,velocityUnits::pct);
          task::sleep(500);
          Motor7.stop();
          Motor8.stop();
          Motor5.spin(reverse,80,velocityUnits::pct);
          Motor6.spin(reverse,80,velocityUnits::pct);
          task::sleep(500);
          Motor5.stop();
          Motor6.stop();

          Motor7.spin(forward,80,velocityUnits::pct);
          Motor8.spin(forward,80,velocityUnits::pct);
          task::sleep(500);
          Motor7.stop();
          Motor8.stop();

          wait(0.5, seconds);
          tui(1900,80,80);
          sj(230,-80,80);//转弯
          hou(1000,80,80);
          sj(1000,80,80);
          xi(400,80,80);
          sj(200,-80,-80);
          tui(250,-80,-80);
          xi(1000,80,80);
          Motor7.spin(reverse,80,velocityUnits::pct);
          Motor8.spin(reverse,80,velocityUnits::pct);
          task::sleep(800);
          Motor7.stop();
          Motor8.stop();
          tui(500,80,80);

         }*/

        /*while(Inertial.rotation() < 90){
           Motor1.spin(forward,100,velocityUnits::pct);
           Motor2.spin(forward,100,velocityUnits::pct);
           Motor3.spin(forward,100,velocityUnits::pct);
           Motor4.spin(forward,100,velocityUnits::pct);
         }

          Motor1.stop();
          Motor2.stop();
          Motor3.stop();
          Motor4.stop();*/



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

int main() {



    // Set up callbacks for autonomous and driver control periods.
    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);

    // Run the pre-autonomous function.
    pre_auton();

    // Prevent main from exiting with an infinite loop.
    while (true) {
        wait(100, msec);
    }
}

//
// Main will set up the competition functions and callbacks.
