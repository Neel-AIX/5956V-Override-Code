#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

motor FR = motor(PORT10, ratio18_1, true);
motor FL = motor(PORT9, ratio18_1, false);
motor RR = motor(PORT1, ratio18_1, true);
motor RL = motor(PORT2, ratio18_1, false);

void vexcodeInit(void) {
  // Nothing to initialize
}