# CS4532 - Parallel and Concurrent Programming 

This repository contains implementations and simulations designed to explore **concurrent programming concepts** using synchronization primitives such as **mutexes**, **semaphores**, and **read-write locks**.

---

## Lab 1 - Linked List Implementations

This project demonstrates different approaches to implementing a linked list:

### 1. Serial Program  
- A standard single-threaded implementation of a linked list.  
- Operations such as insert, delete, and member are executed sequentially.  

### 2. Parallel Program with Mutex  
- A multithreaded implementation using **Pthreads**.  
- A single **mutex lock** is used to control access to the entire linked list.  
- Ensures thread safety but limits concurrency since only one thread can access the list at a time.  

### 3. Parallel Program with Read-Write Locks  
- A multithreaded implementation using **Pthreads**.  
- A single **read-write lock** is used for the entire linked list.  
- Allows multiple concurrent readers while ensuring exclusive access for writers, improving parallel performance for read-heavy workloads.  

---

## Lab 2 - The Senate Bus Problem (Synchronization using Semaphores and Mutexes)

This lab focuses on solving a **real-world synchronization problem** using **Java**, based on the “Senate Bus Problem” described in *The Little Book of Semaphores*.

### **Scenario Overview**
Riders arrive at a bus stop and wait for a bus.  
When the bus arrives:
- All waiting riders board the bus (up to a maximum of 50).
- Riders arriving **during boarding** must wait for the **next bus**.
- If the bus arrives when no riders are waiting, it **departs immediately**.

### **Synchronization Constraints**
- The **bus** should not leave until all boarded riders have finished boarding.  
- **Riders** arriving while a bus is boarding cannot board that bus.  
- The **bus** and **riders** continue to arrive throughout the day.  
- Rider and bus arrivals follow **exponential inter-arrival times** (mean 30s and 20min respectively).

### **Implementation Details**
- Implemented in **Java** using:
  - `Semaphore` for signaling (`bus`, `allAboard`)
  - `Mutex` (binary semaphore) for protecting shared counters
- Two main thread types:
  - `Rider` threads simulate passengers arriving at random intervals.
  - `Bus` threads simulate buses arriving and departing.
