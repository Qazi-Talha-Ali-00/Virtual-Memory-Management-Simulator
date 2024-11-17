# Virtual Memory Simulator

## Project Description

The **Virtual Memory Simulator** is a simulation of an operating system's memory management unit (MMU). It replicates key features of virtual memory, including page replacement policies, logical-to-physical address translation, and handling of page faults. The simulator supports multiple processes, threading, and configurable memory parameters, providing an in-depth look into how virtual memory operates in real-world systems.

---

## Table of Contents
1. [Project Description](#project-description)
2. [Technologies Used](#technologies-used)
3. [Requirements](#requirements)
4. [Usage Instructions](#usage-instructions)
5. [Documentation](#documentation)
    - [Key Features](#key-features)
    - [Source File Overview](#source-file-overview)
6. [Acknowledgements](#acknowledgements)
7. [Conclusion](#conclusion)

---

## Technologies Used

- **C++17** for the implementation of the simulator.
- **POSIX Threads** for multi-threading support.
- Standard Template Library (**STL**) for efficient data handling.
- **File I/O** for managing input and output operations.

---

## Requirements

- A **C++17** compatible compiler (e.g., GCC, Clang).
- A **Linux/Unix** environment for threading compatibility.
- Basic knowledge of virtual memory concepts.
---

## Usage Instructions

1. **Run the simulator** and follow the prompts:
   - Enter **Page Size**, **Logical Address Space (LAS)** and **Physical Address Space (PAS)**.
   - Choose a **Page Replacement Policy** (default is LRU).
   - Provide access sequences if using the **Optimal Policy**.

2. **Outputs:**
   - Memory access data and statistics (hits and misses) are saved in:
     - `output1.txt` for Process 1.
     - `output2.txt` for Process 2.

3. **Generate Random Access Data:**
   - Use the `rand.cpp` utility to create randomized test inputs:
     ```bash
     g++ -std=c++17 -o rand rand.cpp
     ./rand
     ```

---

## Documentation

### Key Features

- **Threaded Simulation:** Concurrent memory access by multiple processes.
- **Page Replacement Algorithms:**
  - Least Recently Used (LRU)
  - First In First Out (FIFO)
  - Most Recently Used (MRU)
  - Optimal
- **Configurable Parameters:** Page size, logical/physical address space, and replacement policy.
- **Efficient Memory Management:** Handles main and secondary memory using frame and page tables.

### Source File Overview

- **`frameTable.cpp`:**
  - Manages frame-to-page mappings in main memory.
- **`main.cpp`:**
  - Implements the core logic of the simulator, including page fault handling.
- **`memory.cpp`:**
  - Simulates main and secondary memory, handling initialization and random data generation.
- **`input.cpp`:**
  - Captures user inputs for simulator configuration.
- **`replace_init.cpp`:**
  - Handles the selection and configuration of page replacement policies.
- **`rand.cpp`:**
  - Generates random access patterns for testing.
- **`try.cpp`:**
  - Provides a utility for reading and debugging input files.

---

## Acknowledgements

This project is inspired by operating system concepts.

Special thanks to contributors 
- Qazi Talha Ali
- Avanti Mittal
- A. Rahul Reddy
- Binay Suman

---

## Conclusion

The **Virtual Memory Simulator** is a powerful tool to understand and visualize virtual memory management. By supporting multiple page replacement policies, it provides insight into the trade-offs and mechanics of modern memory systems. This simulator offers a hands-on way to deepen the understanding of operating systems.

---