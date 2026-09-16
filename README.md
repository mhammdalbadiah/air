# ✈️ Airline Management System

A C++ console application for managing airline data using three core data structures: **Linked Lists**, **Stacks**, and **Queues**. Built as a Data Structures course project at Majmaah University.

---

## 👥 Team

| Name | Role |
|---|---|
| Mohammed Al-Badiah | Leader |
| Othman Al-Thabit | Developer |
| Rakan Al-Harbi | Developer |

---

## 📁 Project Structure

```
AirlineSystem/
│
├── src/
│   ├── main.cpp          # Entry point, main menu, all data structure declarations
│   ├── menus.cpp         # All menu logic (Linked List, Stack, Queue)
│   └── menus.h           # Function prototypes for all menus
│
├── include/
│   ├── Passenger.h       # Passenger class
│   ├── BookingOffice.h   # Booking_Office class
│   ├── Ticket.h          # Ticket class (holds list of Passengers)
│   └── Flight.h          # Flight class (holds list of Tickets)
│
├── data_structures/
│   ├── LinkedList.h      # Generic singly linked list template
│   ├── Stack.h           # Generic stack template (LIFO)
│   └── Queue.h           # Generic queue template (FIFO)
│
└── Makefile              # Build configuration
```

---

## 🗂️ Data Types

The system manages 4 data types across all data structures :

### Passenger
| Field | Type | Rules |
|---|---|---|
| ID | string | Exactly 10 digits |
| Name | string | 3 – 20 characters |
| Passport No | string | 5 – 15 alphanumeric characters |

### Booking Office
| Field | Type | Rules |
|---|---|---|
| Office ID | string | Exactly 10 digits |
| Office Name | string | 3 – 20 characters |
| Office Location | string | 3 – 20 characters |

### Ticket
| Field | Type | Rules |
|---|---|---|
| Ticket Number | string | 2 – 20 characters |
| Flight Number | string | 2 – 20 characters |
| Office Name | string | 2 – 20 characters |
| Passenger List | LinkedList\<Passenger\> | Cannot be empty |

### Flight
| Field | Type | Rules |
|---|---|---|
| Flight ID | string | 2 – 25 characters |
| Destination | string | 2 – 25 characters |
| Gate | string | 2 – 25 characters |
| Departure Time | string | 3 – 20 characters |
| Ticket List | LinkedList\<Ticket\> | Cannot be empty |

---

## 🧱 Data Structures

### 🔗 Linked List — Part 1
A singly linked list that supports :
- **Insert** — add a new node at the end
- **Delete** — remove a node by position
- **Modify** — replace data at a given position
- **Find** — search by ID or key field
- **Display** — show all nodes

### 📚 Stack — Part 2
Follows **LIFO** ( Last In , First Out ) using the same `Node` structure :
- **Push** — add to the top
- **Pop** — remove from the top
- **Peek** — view the top without removing
- **Find** — search from top to bottom
- **Display** — show all items top to bottom

### 🚦 Queue — Part 3
Follows **FIFO** ( First In , First Out ) using `front` and `back` pointers :
- **Enqueue** — add to the back
- **Dequeue** — remove from the front
- **Peek** — view the front without removing
- **Find** — search from front to back
- **Display** — show all items front to back

---

## 🔨 Build & Run

### Requirements
- `g++` with C++17 support
- `make`

### Build
```bash
make
```

### Run
```bash
./AirlineSystem
```

### Clean
```bash
make clean
```

---

## 🗺️ Menu Structure

```
Main Menu
├── 1) Part 1 : Linked Lists
│   ├── 1) Passengers
│   ├── 2) Flights
│   ├── 3) Booking Offices
│   └── 4) Tickets
│
├── 2) Part 2 : Stacks
│   ├── 1) Passengers
│   ├── 2) Flights
│   ├── 3) Booking Offices
│   └── 4) Tickets
│
├── 3) Part 3 : Queues
│   ├── 1) Passengers
│   ├── 2) Flights
│   ├── 3) Booking Offices
│   └── 4) Tickets
│
└── 0) Exit
```

Each sub-menu offers : Display , Insert / Push / Enqueue , Delete / Pop / Dequeue , Peek / Modify , Find , and Back.

---

## ✅ Input Validation

All setter functions include validation before accepting input :
- Empty input is rejected
- Spaces-only input is rejected
- Length limits are enforced per field
- IDs must be digits only
- Passport numbers must be alphanumeric
- Invalid input loops back and asks again

---

## 📝 Notes

- All data structures are **generic templates** ( `template <typename T>` ) and work with any of the 4 data types
- Header files use `#pragma once` to prevent double inclusion
- All data is stored **in memory only** — nothing is saved to disk between runs
- The project uses `cin.ignore()` after `cin >>` to prevent input buffer issues with `getline`
- Built and tested on **Visual Studio** ( Windows )
