# Coalition Race Simulation

## Project Overview

This project simulates a political coalition formation process in a fictional country called SPLand. It models how different political parties form coalitions through the actions of agents, with the goal of reaching a coalition with at least 61 mandates.

## Features

- Graph-based representation of the political landscape
- Agent-based simulation of coalition formation
- Multiple party joining policies
- Multiple agent selection policies
- JSON input for simulation configuration
- JSON output for simulation results
- Optional visualization of results using Python

## Requirements

- C++11 compatible compiler (e.g., GCC)
- Make
- Python 3 (for visualization)
- Python libraries: networkx, matplotlib (for visualization)

## Project Structure

- `src/`: Contains all source (.cpp) files
- `include/`: Contains all header (.h) files
- `bin/`: Directory for compiled output
- `makefile`: For compiling the project

## Compilation

To compile the project, run: make
This will create an executable named `cRace` in the `bin/` directory.

## Running the Simulation

To run the simulation, use: ./bin/cRace <path_to_config_file>
For example: ./bin/cRace config/01.json
This will run the simulation and produce an output file with the same name as the input file but with a `.out` extension.

## Visualization

To visualize the results, first ensure you have the required Python libraries installed: pip3 install networkx matplotlib
Then run: python3 visualization.py <path_to_output_file>
For example: python3 visualization.py 01.out
## Testing

To run tests, compare the output of your simulation with the provided expected output: diff -s <expected_output_file> <your_output_file>
## Class Structure

- `Simulation`: Manages the overall simulation process
- `Graph`: Represents the political landscape
- `Party`: Represents individual political parties
- `Agent`: Represents coalition negotiators
- `SelectionPolicy`: Abstract base class for party selection strategies
- `JoinPolicy`: Abstract base class for coalition joining strategies
