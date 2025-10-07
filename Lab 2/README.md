# Lab 2: Senate Bus Synchronization Problem

## 🧭 Course Information

**CS4532 – Concurrent Programming**
**Take Home Lab 2**

---

## 📘 Overview

This program simulates the **Senate Bus Problem** using **Java threads**, **mutexes**, and **semaphores**.

The simulation models a bus stop where:

* **Riders** arrive at exponentially distributed intervals (**mean = 30 seconds**)
* **Buses** arrive at exponentially distributed intervals (**mean = 20 minutes**)

### Simulation Rules

* When a bus arrives, **all waiting riders** can board (up to a **maximum capacity of 50**).
* Riders who arrive **while boarding is in progress** must wait for the **next bus**.
* Once all selected riders have boarded, the bus **departs**.
* If the bus arrives and **no riders** are waiting, it **departs immediately**.

This problem is based on the original Senate Bus Problem from *"The Little Book of Semaphores"* (p.211).

---

## 🚀 How to Run

### 1. Open Terminal

Navigate to the directory containing the source file:

```bash
cd "Lab 2"
```

### 2. Compile the Program

```bash
javac BusStopSimulation.java
```

### 3. Run the Simulation

```bash
java BusStopSimulation
```

The program runs continuously, simulating bus and rider arrivals.
Use `Ctrl + C` to stop execution.

---

## 🖥️ Output

The console displays events in real time, including:

* Rider arrivals and waiting counts
* Bus arrivals
* Boarding events
* Bus departures (with number of riders)

---

## ⚙️ Requirements

* **Java 8** or higher
* **Operating System:** Any (Windows / macOS / Linux)

---

## 👥 Authors

* **Meddepola M.A.C.T.** 
* **Wijewardana L.T.I.** 

---

## 📚 References

* Allen B. Downey, *“The Little Book of Semaphores”*, 2nd Edition, p. 211
* CS4532 Course Materials – University of Moratuwa

---

## 🧩 Sample Console Output (Preview)

```
Bus 1 arrived.
Bus 1 departed with 0 riders.
Rider 1 arrived. Waiting riders: 1
Rider 2 arrived. Waiting riders: 2
Rider 3 arrived. Waiting riders: 3
Rider 4 arrived. Waiting riders: 4
Rider 5 arrived. Waiting riders: 5
Rider 6 arrived. Waiting riders: 6
Rider 7 arrived. Waiting riders: 7
Rider 8 arrived. Waiting riders: 8
Rider 9 arrived. Waiting riders: 9
Rider 10 arrived. Waiting riders: 10
Rider 11 arrived. Waiting riders: 11
Rider 12 arrived. Waiting riders: 12
Rider 13 arrived. Waiting riders: 13
Rider 14 arrived. Waiting riders: 14
Rider 15 arrived. Waiting riders: 15
Rider 16 arrived. Waiting riders: 16
Rider 17 arrived. Waiting riders: 17
Rider 18 arrived. Waiting riders: 18
Rider 19 arrived. Waiting riders: 19
Bus 2 arrived.
Rider 1 boarded. Riders left to board: 18
Rider 2 boarded. Riders left to board: 17
Rider 3 boarded. Riders left to board: 16
Rider 4 boarded. Riders left to board: 15
Rider 5 boarded. Riders left to board: 14
Rider 6 boarded. Riders left to board: 13
Rider 7 boarded. Riders left to board: 12
Rider 8 boarded. Riders left to board: 11
Rider 9 boarded. Riders left to board: 10
Rider 10 boarded. Riders left to board: 9
Rider 11 boarded. Riders left to board: 8
Rider 12 boarded. Riders left to board: 7
Rider 13 boarded. Riders left to board: 6
Rider 14 boarded. Riders left to board: 5
Rider 20 arrived. Waiting riders: 6
Rider 15 boarded. Riders left to board: 4
Rider 16 boarded. Riders left to board: 3
Rider 17 boarded. Riders left to board: 2
Rider 18 boarded. Riders left to board: 1
Rider 19 boarded. Riders left to board: 0
Bus 2 departed with 19 riders. 
...
```

