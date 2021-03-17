using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern motor Motor1;
extern motor Motor2;
extern motor Motor3;
extern motor Motor4;
extern motor Motor5;
extern motor Motor6;
extern motor Motor7;
extern motor Motor8;
extern signature Vision15__SIG_RED;
extern signature Vision15__SIG_BLUE;
extern signature Vision15__SIG_3;
extern signature Vision15__SIG_4;
extern signature Vision15__SIG_5;
extern signature Vision15__SIG_6;
extern signature Vision15__SIG_7;
extern vision Vision15;
extern inertial Inertial;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );