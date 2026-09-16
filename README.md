#  air

A C++ airline management system with **two interfaces sharing one data core** : a terminal UI and a browser-based GUI, built on top of custom **Linked List**, **Stack**, and **Queue** template data structures. Fully containerized with Docker so it runs identically on any machine.

Originally built as a Data Structures course project at Majmaah University, extended with a web backend, JSON persistence, and Docker packaging for the Software Engineering and Web Development courses.

---

## 👥 Team

| Name | Role |
|---|---|
| Mohammed Al-Badiah | Leader |
| Othman Al-Thabit | Developer |
| Rakan Al-Harbi | Developer |

---

## ✨ Features

- **Two interfaces, one core** — a terminal UI and a web GUI, both driven by the same underlying engine and the same data file. Nothing built twice.
- **Custom generic data structures** — Linked List, Stack, and Queue implemented from scratch as C++ templates, each supporting the same four data types.
- **JSON persistence** — all data is saved to a single JSON file, shared live between whichever interface you're using.
- **Seeded demo data** — the app ships with a sample dataset, so it shows real data immediately with zero setup.
- **One-click reset** — restore the sample dataset or wipe to a clean slate, from either interface.
- **Dockerized** — one image, no local toolchain required. Runs the same way on any device.

---

## 🚀 Usage

```bash
air -tui      # Launch the terminal UI (default if no flag is given)
air -gui      # Launch the web GUI and print the local URL to open
```

Running `air -gui` starts a local web server and prints something like :

```
air GUI running → open http://localhost:8080 in your browser
```

---

## 🐳 Running with Docker

No `g++`, no `make`, no setup — just Docker.

```bash
# Build the image
docker build -t air .

# Run the terminal UI
docker run -it air -tui

# Run the web GUI (maps the container's port to your machine)
docker run -it -p 8080:8080 air -gui
```

Then open **http://localhost:8080** in your browser for the GUI.

By default, every `docker run` starts fresh from the seeded sample data — ideal for demos, since nothing carries over between runs. If you want changes to persist across container restarts, mount the `data/` folder as a volume :

```bash
docker run -it -p 8080:8080 -v air-data:/app/data air -gui
```

---

## 📁 Project Structure

```
air/
│
├── src/
│   ├── main.cpp              # Entry point — parses -tui / -gui and dispatches
│   │
│   ├── tui/
│   │   ├── menus.cpp         # Terminal menu logic (Linked List, Stack, Queue)
│   │   └── menus.h
│   │
│   └── gui/
│       ├── server.cpp        # Crow web server and API routes
│       └── server.h
│
├── core/                     # Shared engine — used by both interfaces
│   ├── Passenger.h
│   ├── BookingOffice.h
│   ├── Ticket.h
│   ├── Flight.h
│   ├── LinkedList.h          # Generic singly linked list template
│   ├── Stack.h                # Generic stack template (LIFO)
│   ├── Queue.h                # Generic queue template (FIFO)
│   ├── Storage.h              # JSON load / save / seed / reset
│   └── Storage.cpp
│
├── web/                       # Static frontend served by the GUI
│   ├── index.html
│   ├── style.css
│   └── app.js
│
├── data/
│   ├── seed.json              # Baked-in sample dataset (read-only)
│   └── airline.json           # Live data file — created on first run
│
├── tests/                     # Unit tests for the core library
│
├── Dockerfile
├── Makefile
└── README.md
```

---

## 🗂️ Data Types

The system manages 4 data types, shared across all data structures and both interfaces :

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

### 🔗 Linked List
A singly linked list that supports :
- **Insert** — add a new node at the end
- **Delete** — remove a node by position
- **Modify** — replace data at a given position
- **Find** — search by ID or key field
- **Display** — show all nodes

### 📚 Stack
Follows **LIFO** ( Last In , First Out ) using the same `Node` structure :
- **Push** — add to the top
- **Pop** — remove from the top
- **Peek** — view the top without removing
- **Find** — search from top to bottom
- **Display** — show all items top to bottom

### 🚦 Queue
Follows **FIFO** ( First In , First Out ) using `front` and `back` pointers :
- **Enqueue** — add to the back
- **Dequeue** — remove from the front
- **Peek** — view the front without removing
- **Find** — search from front to back
- **Display** — show all items front to back

---

## 💾 Data & Persistence

Both interfaces read and write the same file, `data/airline.json`, so a change made in the TUI is immediately visible in the GUI and vice versa.

- **First run** — if `airline.json` doesn't exist yet, it's created from `data/seed.json`, so there's always something to look at right away.
- **Reset to sample data** — available from the TUI menu and the GUI, restores `airline.json` back to the original seeded dataset.
- **Clear all data** — wipes `airline.json` to an empty state, for starting completely from scratch.
- All data is stored on disk in plain JSON — no external database required.

---

## 🖥️ Terminal UI — Menu Structure

```
Main Menu
├── 1) Linked Lists
│   ├── 1) Passengers
│   ├── 2) Flights
│   ├── 3) Booking Offices
│   └── 4) Tickets
│
├── 2) Stacks
│   ├── 1) Passengers
│   ├── 2) Flights
│   ├── 3) Booking Offices
│   └── 4) Tickets
│
├── 3) Queues
│   ├── 1) Passengers
│   ├── 2) Flights
│   ├── 3) Booking Offices
│   └── 4) Tickets
│
├── 4) Reset to Sample Data
├── 5) Clear All Data
└── 0) Exit
```

Each sub-menu offers : Display , Insert / Push / Enqueue , Delete / Pop / Dequeue , Peek / Modify , Find , and Back.

---

## 🌐 Web GUI

The GUI is served by an embedded [Crow](https://crowcpp.org/) web server and a lightweight HTML / CSS / JS frontend, talking to the same core engine as the TUI through a small JSON API.

| Endpoint | Method | Description |
|---|---|---|
| `/api/passengers` | GET / POST / DELETE | List, add, or remove passengers |
| `/api/flights` | GET / POST / DELETE | List, add, or remove flights |
| `/api/tickets` | GET / POST / DELETE | List, add, or remove tickets |
| `/api/offices` | GET / POST / DELETE | List, add, or remove booking offices |
| `/api/reset` | POST | Restore sample data |
| `/api/clear` | POST | Clear all data |

---

## 🔨 Build & Run ( Without Docker )

### Requirements
- `g++` with C++17 support
- `make`
- [Crow](https://crowcpp.org/) ( header-only, required for `-gui` mode )

### Build
```bash
make
```

### Run
```bash
./air -tui
./air -gui
```

### Clean
```bash
make clean
```

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

- All data structures are **generic templates** ( `template <typename T>` ) and work with any of the 4 data types.
- The core engine has no knowledge of either interface — the TUI and GUI are both thin layers on top of it.
- Header files use `#pragma once` to prevent double inclusion.
- Data persists to `data/airline.json` between runs when the `data/` folder is mounted as a volume ; otherwise each run starts fresh from the seed.
- `cin.ignore()` is used after `cin >>` to prevent input buffer issues with `getline` in the TUI.
- The project builds and runs identically on any machine with Docker installed, regardless of host OS.
