# Queue-Management-System-.cpp-backend-

A simple Queue Management System developed in C++ that simulates an Admission Office ticketing and customer servicing process using the Queue Data Structure.

The system applies the FIFO (First In, First Out) principle where the first customer to enter the queue is also the first customer to be served.

---

# Features

## User Panel

* Generate queue tickets
* Select service type
* Automatically enter the waiting queue
* Receive unique ticket numbers

## Admin Panel

* Secure admin access using access code
* Serve customers
* View current queue
* Manage customer flow

## Services Available

* Enrollment
* Document Request
* Submit Documents
* Payment

---

# Main Data Structure and Algorithm (DSA)

The core DSA used in this project is the Queue Data Structure implemented using the C++ STL Queue Library.

```cpp id="d8zp2m"
queue<Ticket> line;
```

The queue follows the FIFO (First In, First Out) algorithm:

* The first customer to get a ticket will also be the first customer to be served.

---

# Queue Operations Used

## Enqueue Operation

Adds customers into the queue.

```cpp id="l7qf2w"
line.push(t);
```

This inserts the customer ticket at the back of the queue.

---

## Front Operation

Accesses the customer currently waiting at the front.

```cpp id="x2me6c"
line.front()
```

---

## Dequeue Operation

Removes the served customer from the queue.

```cpp id="r5pk9y"
line.pop();
```

This follows the FIFO principle.

---

# Program Flow

## User Side

1. User selects the User Panel
2. User chooses a service
3. System generates a ticket number
4. Ticket is inserted into the queue
5. Ticket details are printed

## Admin Side

1. Admin enters the access code
2. Admin can:

   * View queue
   * Serve customers
3. The first customer in queue is removed after servicing

---

# Ticket Number Format

Example:

```txt id="9ah3rm"
26-050001
```

Meaning:

* 26 → Year
* 05 → Month
* 0001 → Queue Counter

---

# Concepts Applied

* Queue Data Structure
* FIFO Algorithm
* Structures in C++
* Functions and Modularity
* Input Validation
* Menu-Driven Programming
* STL Queue Library

---

# Input Validation

The system prevents invalid inputs using:

```cpp id="m6re2k"
if (cin.fail())
```

This avoids crashes when users enter incorrect data types.

---

# Technologies Used

* C++
* STL Queue Library
* Functions
* Structures
* Console-based UI

---

# How to Run

## Compile

```bash id="m4we8s"
g++ QMS_v2.cpp -o QMS
```

## Run

### Mac/Linux

```bash id="y7ot1n"
./QMS
```

### Windows

```bash id="f3ze6m"
QMS.exe
```

---

# Sample System Flow

```txt id="s1kg7r"
User → Generate Ticket → Queue
Admin → Serve Customer → Remove from Queue
```

---

# Learning Outcomes

Through this project, I learned:

* How Queue works in real-world systems
* FIFO processing implementation
* Basic system flow design
* Input validation handling
* Function-based modular programming in C++

---

# Author

Developed as a Data Structures and Algorithms (DSA) project using C++.

