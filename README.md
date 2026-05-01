# PID Control Simulation Project

This project contains a few C/C++ programs that demonstrate PID-based control and visualization.

## Main files

- `0.5.3.cpp` - main PID simulation with auto-tuning and graph display
- `0.5.1.cpp` - earlier PID simulation variant with console and Windows-specific code
- `0.4.2.cpp` - earlier PID simulation variant with simpler console output
- `graph.cpp` - PID simulation that prints an ASCII graph
- `temperature.cpp` - PID simulation for a temperature control example

Explanation:
● PID Controller Parameters:
Kp, Ki, and Kd are the proportional, integral, and derivative gains,
respectively.
tempKd is a temporary variable for initializing Kd.
dt is the time step used in the simulation.
● Function Definitions:
computePID function:
Takes the setpoint, current position, previous error, and integral as input.
Computes the PID control output based on the PID equation.
Updates the previous error and returns the control output.
● simulateSystem function:
Simulates the system dynamics based on the control output.
Updates the position and velocity of the system.
displayGraph function:
Displays a graphical representation of the system's position using ASCII
characters.
The graph is printed on the console, and the '#' character represents the
current position.
● Main Function:
Initialization:
Initializes the PID controller parameters, system initial conditions, and other
variables.
Asks the user to input the desired time to reach the setpoint (am) and adjusts
Kd accordingly.
● Simulation Loop:
Runs a simulation loop to compute the PID control output and simulate the
system's response over time.
Prints the time, position, and control output at each iteration.
Uses usleep to introduce a delay for better visualization.
● Auto-Tuning:
Prints the auto-tuned values of Kp, Ki, and Kd after the initial simulation.
User Input for Graph Display:
Asks the user to input new values for Kp, Ki, and Kd for a second simulation
and graph display.
● Graph Display Loop:
Runs a loop to compute the PID control output, simulate the system, and display
the graph.
Uses the displayGraph function to visually represent the system's position.

## Build

Use your C/C++ compiler to build any of the source files. Example:

```bash
g++ 0.5.3.cpp -o 0.5.3.exe
```

For the graph and temperature demos:

```bash
g++ graph.cpp -o graph.exe
g++ temperature.cpp -o temperature.exe
```
