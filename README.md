# air

A C++ airline management system with two interfaces sharing one data core : a terminal UI and a browser-based GUI, built on top of custom Linked List, Stack, and Queue template data structures. The website has a login page and an admin-only user registration page written in PHP, with the users saved in MySQL. Fully containerized with Docker so the C++ server runs identically on any machine.

Originally built as a Data Structures course project at Majmaah University, extended with a web backend, JSON persistence, and Docker packaging for the Software Engineering and Web Development courses. Then extended again for the IT313 Multimedia and Web Design mini project (College of Computer and Information Sciences) with a new website, a PHP login and registration system, and MySQL.


## Team

| Name | Role | Work |
|------|------|------|
| Mohammed Al-Badiah | Leader |  |
| Othman Al-Thabit | Developer |  |
| Rakan Al-Harbi | Developer |  |


## Features

- **Two interfaces, one core** : a terminal UI and a web GUI, both driven by the same underlying engine and the same data file. Nothing built twice.
- **Custom generic data structures** : Linked List, Stack, and Queue implemented from scratch as C++ templates, each supporting the same four data types.
- **JSON persistence** : all airline data is saved to a single JSON file, shared live between whichever interface you're using.
- **Seeded demo data** : the app ships with a sample dataset, so it shows real data immediately with zero setup.
- **One-click reset** : restore the sample dataset or wipe to a clean slate, from either interface.
- **Import / export** : download the data as a JSON file or load one back, from the Settings page.
- **Login** : the website opens on a login page. The built-in account `admin` / `admin` is always there.
- **User registration (admin only)** : admin creates new users from the Register page. Users are saved in MySQL and still work after a restart.
- **One-command setup** : `./install.sh` installs everything, `./run.sh` starts everything, `./uninstall.sh` removes everything.
- **Dockerized** : one image for the C++ server, no local toolchain required.


## How it fits together

```
 Browser
   │
   ├── http://localhost:8080  ──►  ./air -gui   (C++ Crow server)
   │                                 ├── web/        website pages, style.css, app.js
   │                                 └── data/airline.json   flights, tickets, passengers, offices
   │
   └── http://localhost:8000  ──►  php -S localhost:8000   (PHP server)
                                     ├── php/login.php , register.php , logout.php
                                     └── MySQL : air_registration.users   (login accounts)
```

- The C++ server can not run PHP , so the login and register pages run on a second server (PHP on port 8000).
  `./run.sh` starts both for you.
- Airline data (flights , tickets , passengers , offices) lives in `data/airline.json`.
  Only the login accounts are in MySQL.
- After you log in , PHP sets a small cookie. `app.js` checks it on the 8080 pages and sends you to the login page if it is missing.
  This is fine for a class project , but it is not real security (the C++ server itself does not check logins).
  The PHP pages do check the login properly.


## Quick Install (CachyOS / Arch or macOS)

Run these from the project folder :

```bash
chmod +x install.sh run.sh uninstall.sh
./install.sh
./run.sh
```

Then open **http://localhost:8080** and log in with **admin / admin**.

| Script | When to run it | What it does |
|--------|----------------|--------------|
| `./install.sh` | One time | Installs the compiler , Asio , Crow , PHP and MySQL , turns MySQL on at every boot , creates the database from `php/setup.sql` , runs `make` and installs the global `air` command |
| `./run.sh` | Every time you use the project (also after a restart) | Starts MySQL if it is off , checks PHP , starts PHP on port 8000 and `./air -gui` on port 8080. Ctrl+C stops PHP and air |
| `./uninstall.sh` | Only to remove everything | Asks y/n once , deletes the database , removes only what `install.sh` added , runs `make clean`. Your project files stay |

How MySQL is installed :

- **CachyOS / Arch** : MySQL is not in the Arch repos , so `install.sh` installs Docker and runs the official MySQL 8.4 image
  (container `air-mysql` , data in the Docker volume `air-mysql-data`). It starts by itself after every restart.
  The first install downloads about 600 MB.
- **macOS** : MySQL from Homebrew (`brew install mysql`) , started with `brew services`.

`install.sh` writes everything it adds into `.install-state`. `uninstall.sh` reads that file , so programs you
already had (for example `base-devel`) are never removed. It is safe to run `install.sh` again , it skips what is already done.


## Usage

```bash
air           # Launch the terminal UI (default if no flag is provided)
air -tui      # Explicitly launch the terminal UI
air -gui      # Launch the web GUI backend and print the local URL
```

The flags have **one dash** (`-gui` , not `--gui`). Run `./air` from the project folder , or use the `air` command
that `install.sh` installed.

Running `air -gui` starts the local web server and prints where it is :

```
  air - Airline Management System (web GUI)
  ------------------------------------------
  Web files : .../web
  Data file : .../data/airline.json
  Listening : 127.0.0.1:8080

  Open http://localhost:8080 in your browser  (Ctrl+C to stop)
```

For the full website with login use `./run.sh` instead , it starts the PHP server too.


## Login and Registration

| Page | Address |
|------|---------|
| Login (first page) | http://localhost:8000/php/login.php |
| Register (admin only) | http://localhost:8000/php/register.php |
| Logout | http://localhost:8000/php/logout.php |

- Opening http://localhost:8080 sends you to the login page if you are not logged in.
- Default account : username **admin** , password **admin**. If it is deleted from the database , it comes back the next time a page opens.
- Only admin can create users. The Register page shows the form (Username first) and a table of all users.
- New users can log in and use the website , but they can not create users.
- Use **localhost** in the address , not `127.0.0.1` , or the login cookie will not match.

The registration form has 11 fields , each checked in JavaScript (before sending) and again in PHP , with the error shown next to the field :

| Field | Rule |
|-------|------|
| Username | 3 – 20 letters , digits or _ , must not be taken |
| Full Name | 3 – 50 English letters (spaces , ' and - allowed) |
| Email | Valid email , must not be taken |
| Password | At least 8 characters (saved with `password_hash`) |
| Confirm Password | Same as Password |
| Phone | Exactly 10 digits |
| National ID | Exactly 10 digits |
| Date of Birth | A real date in the past |
| Gender | Male or Female |
| Nationality | Chosen from the list |
| Address | Optional , up to 200 characters |


## The Database (MySQL)

- Database : `air_registration` , table : `users` (created by `php/setup.sql`)
- Connection settings are in `php/config.php` : host `127.0.0.1` , user `root` , no password
  (`127.0.0.1` makes PHP use port 3306 , which works with Docker MySQL , Homebrew MySQL and XAMPP)

### See the records

CachyOS / Arch (MySQL in Docker) :

```bash
sudo docker exec -it air-mysql mysql -u root -e "SELECT id, username, role, full_name, email, phone, national_id, date_of_birth, gender, nationality, created_at FROM air_registration.users;"
```

Put `\G` instead of the last `;` to show each user as a list. To open the MySQL prompt :

```bash
sudo docker exec -it air-mysql mysql -u root air_registration
```

Then type `SHOW TABLES;` or `SELECT * FROM users;` , and `exit` to leave.

macOS (Homebrew MySQL) :

```bash
mysql -u root -e "SELECT id, username, role, full_name, email FROM air_registration.users;"
```

Logged in as admin , the Register page also lists every user.


## Running with Docker

No g++ , no make , no local toolchain setup — just Docker. The image has only the C++ server (port 8080).

```bash
# Build the image
docker build -t air .

# Run the web GUI (the default , maps the container's port to your machine)
docker run -it -p 8080:8080 air

# Run the terminal UI
docker run -it air -tui
```

Then open http://localhost:8080 in your browser for the GUI.

By default , every `docker run` starts fresh from the seeded sample data — ideal for demos , since nothing carries over
between runs. If you want changes to persist across container restarts , mount the `data/` folder as a volume :

```bash
docker run -it -p 8080:8080 -v air-data:/app/data air
```

The Docker image does not include PHP or MySQL. For the login and register pages , `php -S localhost:8000` and MySQL
still have to run on your machine , so for the full website `./run.sh` is the easier way.


## Project Structure

```
air/
│
├── install.sh                # Installs everything (compiler , Crow , PHP , MySQL) and runs make
├── run.sh                    # Starts MySQL , PHP (port 8000) and the web GUI (port 8080)
├── uninstall.sh              # Removes what install.sh added and runs make clean
├── Makefile                  # Build targets (all , clean , install , uninstall)
├── Dockerfile                # Docker container build configuration
├── README.md                 # Project documentation
│
├── src/
│   ├── main.cpp              # Entry point — parses -tui / -gui and dispatches
│   │
│   ├── tui/
│   │   ├── menus.cpp         # Terminal menu logic and implementation
│   │   └── menus.h           # Terminal menu function declarations
│   │
│   └── gui/
│       ├── server.cpp        # Crow web server and API routes
│       └── server.h          # GUI server declarations
│
├── core/                     # Shared core components used by the system
│   ├── BookingOffice.h       # Booking Office model
│   ├── Core.h                # Main core header
│   ├── Flight.h              # Flight model
│   ├── LinkedList.h          # Generic singly linked list template
│   ├── Passenger.h           # Passenger model
│   ├── ProgressBar.h         # Terminal progress/loading bar
│   ├── Queue.h               # Generic queue template (FIFO)
│   ├── Stack.h               # Generic stack template (LIFO)
│   ├── Storage.h             # Storage engine declarations (JSON load / save)
│   ├── Storage.cpp           # Storage engine (shared by the TUI and the GUI)
│   └── Ticket.h              # Ticket model
│
├── data/
│   ├── airline.json          # Airline system data (created from seed.json on first run)
│   └── seed.json             # Initial/sample dataset
│
├── php/                      # Login and registration (runs on port 8000)
│   ├── config.php            # MySQL connection , adds the admin account
│   ├── login.php             # Login page (first page of the website)
│   ├── logout.php            # Logs out and goes back to login
│   ├── register.php          # Create users (admin only) + list of all users
│   ├── register.html         # Opens register.php
│   └── setup.sql             # Creates the air_registration database and users table
│
├── report/
│   └── report.md             # Project report
│
└── web/                      # Frontend files served by the GUI
    │
    ├── html/                 # HTML pages for the web interface
    │   ├── dashboard.html    # Main dashboard page (counts of each type)
    │   ├── data-structures.html # Stack and Queue demo page
    │   ├── flights.html      # Flight management page
    │   ├── index.html        # Home page
    │   ├── offices.html      # Booking Office management page
    │   ├── passengers.html   # Passenger management page
    │   ├── settings.html     # Reset , clear , import and export
    │   └── tickets.html      # Ticket management page
    │
    ├── images/               # Images used by the frontend (add your own 3 photos)
    │   ├── Airplane.jpg
    │   ├── Airport.jpg
    │   └── Travel.jpg
    │
    ├── app.js                # Frontend logic , API calls , form checks , login check
    └── style.css             # Shared frontend styling
```

Files made while running (not part of the source) : `air` , `*.o` , `php-server.log` , `.install-state`.


## Data Types

The system manages 4 data types , shared across all data structures and both interfaces :

### Passenger

| Field | Type | Rules |
|-------|------|-------|
| ID | string | Exactly 10 digits |
| Name | string | 3 – 20 characters |
| Passport No | string | 5 – 15 alphanumeric characters |

### Booking Office

| Field | Type | Rules |
|-------|------|-------|
| Office ID | string | Exactly 10 digits |
| Office Name | string | 3 – 20 characters |
| Office Location | string | 3 – 20 characters |

### Ticket

| Field | Type | Rules |
|-------|------|-------|
| Ticket Number | string | 2 – 20 characters |
| Flight Number | string | 2 – 20 characters |
| Office Name | string | 2 – 20 characters |
| Passenger List | LinkedList&lt;Passenger&gt; | Cannot be empty |

### Flight

| Field | Type | Rules |
|-------|------|-------|
| Flight ID | string | 2 – 25 characters |
| Destination | string | 2 – 25 characters |
| Gate | string | 2 – 25 characters |
| Departure Time | string | 3 – 20 characters |
| Ticket List | LinkedList&lt;Ticket&gt; | Cannot be empty |

Because a flight's ticket list can not be empty , create at least one ticket before you add a flight.


## Data Structures

### 🔗 Linked List

A singly linked list that supports :

- **Insert** — add a new node at the end
- **Delete** — remove a node by position
- **Modify** — replace data at a given position
- **Find** — search by ID or key field
- **Display** — show all nodes

### Stack

Follows LIFO ( Last In , First Out ) using the same Node structure :

- **Push** — add to the top
- **Pop** — remove from the top
- **Peek** — view the top without removing
- **Find** — search from top to bottom
- **Display** — show all items top to bottom

### Queue

Follows FIFO ( First In , First Out ) using front and back pointers :

- **Enqueue** — add to the back
- **Dequeue** — remove from the front
- **Peek** — view the front without removing
- **Find** — search from front to back
- **Display** — show all items front to back

The Data Structures page of the website shows the Stack and Queue of each type and lets you push , pop , enqueue and dequeue.


## Data & Persistence

Both interfaces read and write the same file , `data/airline.json` , so a change made in the TUI is immediately visible in the GUI and vice versa.

- **First run** — if `airline.json` doesn't exist yet , it's created from `data/seed.json` , so there's always something to look at right away.
- **Reset to sample data** — available from the TUI menu and the GUI , restores `airline.json` back to the original seeded dataset.
- **Clear all data** — wipes `airline.json` to an empty state , for starting completely from scratch.
- **Import / Export** — the Settings page downloads `airline.json` or loads a JSON file back (up to 5 MB).
- Airline data is stored on disk in plain JSON. MySQL is used only for the login accounts.


## Web GUI

The GUI is served by an embedded Crow web server and a lightweight HTML / CSS / JS frontend , talking to the same core engine as the TUI through a small JSON API.

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/api/passengers` | GET / POST / PUT / DELETE | List , add , edit or remove passengers |
| `/api/flights` | GET / POST / PUT / DELETE | List , add , edit or remove flights |
| `/api/tickets` | GET / POST / PUT / DELETE | List , add , edit or remove tickets |
| `/api/offices` | GET / POST / PUT / DELETE | List , add , edit or remove booking offices |
| `/api/stats` | GET | Number of records of each type |
| `/api/health` | GET | Check that the server is running |
| `/api/reset` | POST | Restore sample data |
| `/api/clear` | POST | Clear all data |
| `/api/import` | POST | Load data from an uploaded JSON file |
| `/api/export` | GET | Download the data as `airline.json` |
| `/api/structures?type=...` | GET | Stack and Queue of one type (passengers , flights , tickets or offices) |
| `/api/structures/<type>/<op>` | POST | Stack / Queue action : push , pop , enqueue , dequeue , stack-clear , queue-clear , sync |


## Build & Run ( Without the scripts )

`./install.sh` already does all of this.

### Requirements

- g++ (Linux) or clang (macOS) with C++17 support
- make
- Asio and Crow ( header-only , required for `-gui` mode )
- PHP 8 with mysqli and MySQL ( only for the login and register pages )

### Install the libraries

CachyOS / Arch :

```bash
sudo pacman -S base-devel asio
sudo mkdir -p /usr/local/include
sudo curl -L -o /usr/local/include/crow_all.h https://github.com/CrowCpp/Crow/releases/download/v1.3.4/crow_all.h
```

macOS :

```bash
xcode-select --install
brew install asio
curl -L -o "$(brew --prefix)/include/crow_all.h" https://github.com/CrowCpp/Crow/releases/download/v1.3.4/crow_all.h
```

The Makefile uses g++ on Linux and clang on macOS , and it adds the Homebrew include folder by itself.
Without Crow , `make` still works , but `./air -gui` only prints how to install it.

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

### PHP and MySQL by hand

CachyOS / Arch (MySQL in Docker) :

```bash
sudo pacman -S php docker
sudo systemctl enable --now docker
sudo docker run -d --name air-mysql --restart unless-stopped -p 127.0.0.1:3306:3306 -e MYSQL_ALLOW_EMPTY_PASSWORD=yes -v air-mysql-data:/var/lib/mysql mysql:8.4
sudo docker exec -i air-mysql mysql -u root < php/setup.sql
```

Then open `/etc/php/php.ini` and remove the `;` before `extension=mysqli`.

macOS (Homebrew) :

```bash
brew install php mysql
brew services start mysql
mysql -u root < php/setup.sql
```

Then start both servers from the project folder , each in its own terminal :

```bash
php -S localhost:8000
./air -gui
```

MAMP / XAMPP also work : copy the project into `htdocs` , run `php/setup.sql` in phpMyAdmin , and set the password
in `php/config.php` (MAMP uses `root` / `root`). The 8080 pages still point to port 8000 for login , so `./run.sh` is easier.


## Troubleshooting

| Problem | Fix |
|---------|-----|
| `Unknown flag '--gui'` | Use one dash : `./air -gui` |
| Firefox : Unable to connect to localhost:8000 | Start the site with `./run.sh` , not only `./air -gui` |
| The login does not stick | Open `http://localhost:8080` , not `127.0.0.1` |
| `./air was not built` | Run `./install.sh` (it runs `make`) |
| `install.sh` says MariaDB is still running | An older version of this project used MariaDB. Run `./uninstall.sh` (answer y) , then `./install.sh` |
| `MySQL is not answering` | Run `./install.sh` again. On Arch check `sudo docker ps -a` and `sudo systemctl status docker` |
| pacman 404 errors for `.sig` files (CachyOS) | A broken mirror : `sudo cachyos-rate-mirrors` , then `sudo pacman -Syyu` , then run `./install.sh` again |
| A flight can not be saved | Add a ticket first , a flight needs at least one ticket |


## Technologies

- C++17 , Crow , Asio
- HTML , CSS , JavaScript
- PHP 8 (mysqli)
- MySQL 8
- Docker
- Bash (install , run and uninstall scripts)
