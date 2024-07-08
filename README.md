# Process Scheduler Simulation

## Project Overview
This project simulates the operation of a process scheduler in a multiprocessor system. The scheduler aims to optimize resource use, maximize CPU utilization, and minimize response and waiting times. The project implements three scheduling algorithms: First Come First Serve (FCFS), Shortest Job First (SJF), Round Robin (RR), and Earliest Deadline First (EDF) .

## Objectives
- Understand and derive appropriate designs from unstructured problem descriptions.
- Modularize design into independent components.
- Implement and use data structures.
- Write a complete object-oriented C++ program.

## Features
- Simulates process scheduling across multiple processors.
- Calculates processor load and utilization.
- Implements FCFS, SJF, RR, and EDF scheduling algorithms.

## System Design
### Architecture
- **Scheduler**: Manages process execution.
- **Processor**: Represents each CPU unit.
- **Process**: Represents tasks to be scheduled.

### Data Structures
- **LinkedList**: Used for ready queues.
- **Node**: Represents elements in the linked list.

## Scheduling Algorithms
1. **First Come First Serve (FCFS)**: Processes are scheduled in the order they arrive.
2. **Shortest Job First (SJF)**: Schedules the process with the smallest remaining CPU time.
3. **Round Robin (RR)**: Each process is assigned a fixed time slot in a cyclic order.
4. **Earliest Deadline First (EDF)**: Each process has a deadline that it expexts to be completed before EDF assigns priorities to processes based on their absolute deadlines. The process with the earliest deadline gets higher priority and runs on the CPU.

## Contribution
Feel free to fork the repository, create a new branch, and submit a pull request. Make sure to follow the contribution guidelines.


---
