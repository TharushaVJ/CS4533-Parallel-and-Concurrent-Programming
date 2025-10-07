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

A **screenshot of sample output** is included in the submission.

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
Rider 1 arrived. Waiting riders: 1  
Rider 2 arrived. Waiting riders: 2  
Bus 1 arrived.  
Rider 1 boarded. Riders left to board: 1  
Rider 2 boarded. Riders left to board: 0  
Bus 1 departed with 2 riders.  
Rider 3 arrived. Waiting riders: 1  
...
```

