#include "vex.h"
#include "math.h"

using namespace vex;

int PID(double target, double current, double kP, double kI, double kD, double &integral, double &previousError, double dt) {
  // Calculate the error
  double error = target - current;

  // Calculate the integral
  integral += error * dt;

  // Calculate the derivative
  double derivative = (error - previousError) / dt;

  // Calculate the output
  int output = (kP * error) + (kI * integral) + (kD * derivative);

  // Update the previous error
  previousError = error;

  return output;
}

int J1(double &integral, double target, double current, double dt){             // Integral squared error (ISE). Cost function is the integral of the squared error.
  double error = target - current;                                              // J = ∫ e(t)^2 dt
                                                                              
  integral += pow(error, 2) * dt;                 
  double cost = integral;    
  
  return cost;
}

int J2(double &integral, double target, double current, double dt){             // Integral absolute error (IAE). Cost function is the integral of the absolute error.
  double error = target - current;                                              // J = ∫ |e(t)| dt
  
  integral += fabs(error) * dt; 
  double cost = integral;

  return cost;
}

// int J3(double &integral, double target, double current, double dt){              // Integral time absolute error (ITAE)
//                                                                                  // J = ∫ t |e(t)| dt

// }

int coord_desc(double cost, double Kp, double Ki, double Kd){                // Coordinate descent (uses control statements to find the best kP, kI, and kD values)
  
}

int grad_desc(){                // Gradient descent (uses gradient of cost function to find the best kP, kI, and kD values)
                                // \mathbf K_{n+1}=\mathbf K_n-\eta\nabla J(\mathbf K_n)
                                // K is the vector of PID parameters, n is the iteration number, and η is the learning rate

}
