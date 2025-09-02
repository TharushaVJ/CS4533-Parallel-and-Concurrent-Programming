# Lab 1 - Linked List Implementations

This project demonstrates different approaches to implementing a linked list:

1. **Serial Program**  
   - A standard single-threaded implementation of a linked list.  

2. **Parallel Program with Mutex**  
   - A multithreaded implementation using **Pthreads**.  
   - A single **mutex lock** is used to control access to the entire linked list.  

3. **Parallel Program with Read-Write Locks**  
   - A multithreaded implementation using **Pthreads**.  
   - A single **read-write lock** is used for the entire linked list, allowing multiple readers but only one writer at a time.  
