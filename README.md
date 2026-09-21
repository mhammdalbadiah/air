#  air

A C++ airline management system with **two interfaces sharing one data core** : a terminal UI and a browser-based GUI, built on top of custom **Linked List**, **Stack**, and **Queue** template data structures. Fully containerized with Docker so it runs identically on any machine.

Originally built as a Data Structures course project at Majmaah University, extended with a web backend, JSON persistence, and Docker packaging for the Software Engineering and Web Development courses.

---

##  Team

| Name | Role |
|---|---|
| Mohammed Al-Badiah | Leader |
| Othman Al-Thabit | Developer |
| Rakan Al-Harbi | Developer |

---

##  Features

- **Two interfaces, one core** : a terminal UI and a web GUI, both driven by the same underlying engine and the same data file. Nothing built twice.
- **Custom generic data structures** : Linked List, Stack, and Queue implemented from scratch as C++ templates, each supporting the same four data types.
- **JSON persistence** : all data is saved to a single JSON file, shared live between whichever interface you're using.
- **Seeded demo data** : the app ships with a sample dataset, so it shows real data immediately with zero setup.
- **One-click reset** : restore the sample dataset or wipe to a clean slate, from either interface.
- **Dockerized** : one image, no local toolchain required. Runs the same way on any device.

---


## Quick Install (Linux / macOS)

Run the automated install script to build the project and configure global binary access (`air`) across your system and shells:

```bash
chmod +x install.sh
./install.sh
```

## Usage 


```bash
air           # Launch the terminal UI (default if no flag is provided)
air -tui      # Explicitly launch the terminal UI
air -gui      # Launch the web GUI backend and print the local URL
```

Running air -gui starts the local web server and prints:

```bash
air GUI running → open http://localhost:8080 in your browser
```

## Running with Docker 

No g++, no make, no local toolchain setup — just Docker.   

```bash
# Build the image
docker build -t air .

# Run the terminal UI
docker run -it air -tui

# Run the web GUI (maps the container's port to your machine)
docker run -it -p 8080:8080 air -gui
```

Then open http://localhost:8080 in your browser for the GUI

   By default, every docker run starts fresh from the seeded sample data — ideal for demos, since nothing carries over between runs. If you want changes to persist across container restarts, mount the data/ folder as a volume:   

```bash
docker run -it -p 8080:8080 -v air-data:/app/data air -gui
```







##  Project Structure

```
air/
│
├── install.sh                # Automated build and binary installation script
├── Makefile                  # Build targets (all, install, clean)[cite: 1]
├── Dockerfile                # Multi-stage Docker container build[cite: 1]
├── README.md                 # Project documentation[cite: 1]
│
├── src/
│   ├── main.cpp              # Entry point — parses -tui / -gui and dispatches[cite: 1]
│   │
│   ├── tui/
│   │   ├── menus.cpp         # Terminal menu logic and run() loop[cite: 1]
│   │   └── menus.h           # TUI and sub-menu function declarations[cite: 1]
│   │
│   └── gui/
│       ├── server.cpp        # Crow web server and API routes[cite: 1]
│       └── server.h          # GUI server declarations[cite: 1]
│
├── core/                     # Shared engine — used by both interfaces[cite: 1]
│   ├── Core.h                # Master umbrella header for all core components
│   ├── ProgressBar.h         # Animated terminal loading bar
│   ├── Passenger.h           # Passenger model[cite: 1]
│   ├── BookingOffice.h       # Booking Office model[cite: 1]
│   ├── Ticket.h              # Ticket model[cite: 1]
│   ├── Flight.h              # Flight model[cite: 1]
│   ├── LinkedList.h          # Generic singly linked list template[cite: 1]
│   ├── Stack.h               # Generic stack template (LIFO)[cite: 1]
│   ├── Queue.h               # Generic queue template (FIFO)[cite: 1]
│   ├── Storage.h             # JSON load / save / seed / reset[cite: 1]
│   └── Storage.cpp           # JSON persistence implementation[cite: 1]
│
├── web/                      # Static frontend served by the GUI[cite: 1]
│   ├── index.html            # Single page web interface[cite: 1]
│   ├── style.css             # Frontend styling[cite: 1]
│   └── app.js                # Frontend API interactions[cite: 1]
│
└── data/
    ├── seed.json             # Baked-in sample dataset (read-only)[cite: 1]
    └── airline.json          # Live data file — created on first run[cite: 1]
```

---

##  Data Types

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

##  Data Structures

### 🔗 Linked List
A singly linked list that supports :
- **Insert** — add a new node at the end
- **Delete** — remove a node by position
- **Modify** — replace data at a given position
- **Find** — search by ID or key field
- **Display** — show all nodes

###  Stack
Follows **LIFO** ( Last In , First Out ) using the same `Node` structure :
- **Push** — add to the top
- **Pop** — remove from the top
- **Peek** — view the top without removing
- **Find** — search from top to bottom
- **Display** — show all items top to bottom

###  Queue
Follows **FIFO** ( First In , First Out ) using `front` and `back` pointers :
- **Enqueue** — add to the back
- **Dequeue** — remove from the front
- **Peek** — view the front without removing
- **Find** — search from front to back
- **Display** — show all items front to back

---

##  Data & Persistence

Both interfaces read and write the same file, `data/airline.json`, so a change made in the TUI is immediately visible in the GUI and vice versa.

- **First run** — if `airline.json` doesn't exist yet, it's created from `data/seed.json`, so there's always something to look at right away.
- **Reset to sample data** — available from the TUI menu and the GUI, restores `airline.json` back to the original seeded dataset.
- **Clear all data** — wipes `airline.json` to an empty state, for starting completely from scratch.
- All data is stored on disk in plain JSON — no external database required.

---



##  Web GUI

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

##  Build & Run ( Without Docker )

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
