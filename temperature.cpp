#include <stdio.h>
#include <unistd.h>

// PID parameters
double Kp = 0.1;   // Proportional gain
double Ki = 0.01;  // Integral gain
double Kd = 0.1;  // Derivative gain

// Variables
double setpoint = 100.0;  // Setpoint temperature
double input = 20.0;      // Initial temperature (sensor input)
double output = 0;         // Output value (controller output)

// Error terms
double error = 0;      // Current error (setpoint - input)
double last_error = 0; // Previous error
double integral = 0;   // Integral of error over time

// Function to update the temperature based on the controller output
void updateTemperature() {
    // Simulate the system dynamics (you would replace this with your system behavior)
    double system_gain = 0.5;  // Example system gain
    input += output * system_gain;

    // Print the current temperature
    printf("Current Temperature: %.2f\n", input);
}

int main() {
    // PID algorithm
    for (int i = 0; i < 1000; i++) {  // Simulate iterations we want
        // Calculate error
        error = setpoint - input;

        // Calculate proportional term
        double P = Kp * error;

        // Calculate integral term
        integral += Ki * error;

        // Calculate derivative term
        double derivative = Kd * (error - last_error);

        // Calculate output
        output = P + integral + derivative;

        // Apply the output to your system (update the temperature)
        updateTemperature();

        // Update variables for the next iteration
        last_error = error;


        // Adding a delay (adjust the time interval based on your requirements)
        usleep(10000);  // 100ms delay
    }

    return 0;
}
