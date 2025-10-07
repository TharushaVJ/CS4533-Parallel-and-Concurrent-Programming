# Lab 2: Senate Bus Synchronization Problem

## How to Run

1. **Compile:**
   - Open a terminal in the `Lab 2` directory.
   - Run: `javac BusStopSimulation.java`

2. **Run:**
   - Run: `java BusStopSimulation`

## Description
This program simulates the Senate Bus problem using Java threads, mutexes, and semaphores. Riders and buses arrive at random intervals. Riders wait for the bus, and only up to 50 can board each bus. The bus departs when all waiting riders have boarded or immediately if no riders are present.

## Output
The program prints the sequence of rider arrivals, bus arrivals, boarding events, and departures. See the screenshot for a sample output.

## Requirements
- Java 8 or higher

## Authors
- Meddepola MACT, Wijewardana LTI

## References
- "Little Book of Semaphores", page 211

