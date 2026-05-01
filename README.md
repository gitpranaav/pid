# PID Control Simulation Project

This project contains a few C/C++ programs that demonstrate PID-based control and visualization.

## Main files

- `0.5.3.cpp` - main PID simulation with auto-tuning and graph display
- `0.5.1.cpp` - earlier PID simulation variant with console and Windows-specific code
- `0.4.2.cpp` - earlier PID simulation variant with simpler console output
- `graph.cpp` - PID simulation that prints an ASCII graph
- `temperature.cpp` - PID simulation for a temperature control example

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
