
# Simple Operating System – HCMUT (CO2018)

This repository contains the implementation of a simulated operating system developed as part of the Operating Systems course at Ho Chi Minh City University of Technology (HCMUT) in March 2025.

## 🔧 Features
- Multilevel Queue (MLQ) Scheduler
- Paging-based Memory Management
- Memory Swapping and Frame Allocation
- Synchronization using Mutex Locks
- Custom System Calls (e.g., `killall`, `memmap`)
- Full simulation of CPU and RAM via Virtual Hardware

## 📁 Structure
- `src/`: Source code implementation (C files)
- `include/`: Header files
- `input/`: Configuration and process input files
- `output/`: Sample simulation outputs

## 📌 How to Run
```bash
chmod +x tc4u.sh

# Step 1: Download input files listed in the manifest
./tc4u.sh install

# Step 2: Run the test cases
./tc4u.sh run

# Step 3: Clean up downloaded files
./tc4u.sh clean
