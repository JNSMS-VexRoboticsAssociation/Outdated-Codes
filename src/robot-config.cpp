#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor Motor1 = motor(PORT1, ratio18_1, false);
motor Motor2 = motor(PORT2, ratio18_1, true);
motor Motor3 = motor(PORT3, ratio18_1, false);
motor Motor4 = motor(PORT4, ratio18_1, true);
motor Motor5 = motor(PORT5, ratio18_1, false);
motor Motor6 = motor(PORT6, ratio18_1, true);
motor Motor7 = motor(PORT7, ratio36_1, false);
motor Motor8 = motor(PORT8, ratio36_1, false);
/*vex-vision-config:begin*/
signature Vision15__SIG_RED = signature(1, 1455, 6721, 4088, -1499, -217, -858, 0.7, 0);
signature Vision15__SIG_BLUE = signature(2, -3933, -1665, -2799, 3959, 10019, 6989, 0.8, 0);
vision Vision15 = vision(PORT15, 150, Vision15__SIG_RED, Vision15__SIG_BLUE);
/*vex-vision-config:end*/
inertial Inertial = inertial(PORT20);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
    // nothing to initialize
}