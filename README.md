# 🎫 Ticket Booking System using Linked Lists

> A dynamic ticket booking system implemented in C using linked lists. This system simulates booking and cancellation of tickets for buses, flights, or movies with an integrated waiting list feature.

## 📋 Table of Contents
- [Features](#features)
- [Data Structures](#data-structures)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Usage](#usage)
- [Program Flow](#program-flow)
- [Key Functions](#key-functions)
- [How It Works](#how-it-works)
- [Constraints](#constraints)
- [Example Output](#example-output)
- [License](#license)

## ✨ Features

- **Seat Management**: Each seat is represented as a node in a linked list
- **Waiting List**: Queue implementation using linked list for passengers when all seats are booked
- **Booking System**: Book seats by passenger name with automatic waiting list management
- **Cancellation System**: Cancel bookings with automatic seat assignment from waiting list
- **Display Functions**: View all seats and waiting list status
- **Menu-Driven Interface**: Easy-to-use command-line interface
- **Memory Management**: Proper dynamic memory allocation and deallocation

## 🏗️ Data Structures

### Seat Node Structure
```c
typedef struct Seat {
    int seatNumber;
    char passengerName[100];
    int isBooked;  // 0 for available, 1 for booked
    struct Seat *next;
} Seat;
```

### Waiting List Node (Queue) Structure
```c
typedef struct WaitingPassenger {
    char passengerName[100];
    struct WaitingPassenger *next;
} WaitingPassenger;
```

## 📦 Requirements

- C compiler (GCC recommended)
- Standard C library (stdio.h, stdlib.h, string.h)

## 🔧 Compilation

### On Linux/Mac:
```bash
gcc -o ticketbookingsystem ticket_booking_system.c -Wall -Wextra
```

### On Windows:
```bash
gcc -o ticketbookingsystem.exe ticket_booking_system.c -Wall -Wextra
```

Or using any C compiler like:
```bash
clang -o ticketbookingsystem ticket_booking_system.c
```

## 🚀 Usage

### Running the Program

**Linux/Mac:**
```bash
./ticketbookingsystem
```

**Windows:**
```bash
ticketbookingsystem.exe
```

## 📝 Program Flow

### Menu Options
1. **Display Seats** - View all seats with their status and passenger names
2. **Book Seat** - Book a seat by entering passenger name
3. **Cancel Seat** - Cancel a booking by seat number
4. **Display Waiting List** - View all passengers in the waiting list
5. **Exit** - Exit the program and free all memory

### Example Session
```
TICKET BOOKING SYSTEM
Enter the number of seats: 5
System initialized with 5 seats

MENU
1. Display Seats
2. Book Seat
3. Cancel Seat
4. Display Waiting List
5. Exit
Enter your choice: 2
Enter passenger name: John Doe
Seat 1 has been booked for John Doe

MENU
... (more options) ...
Enter your choice: 1

=== SEAT STATUS ===
  Seat No.        Passenger Name     Status
----------------------------------------
         1             John Doe      Booked
         2           Available      Available
         3           Available      Available
         4           Available      Available
         5           Available      Available
```

## 🔑 Key Functions

| Function | Purpose |
|----------|----------|
| `initializeSeats(int numSeats)` | Initializes the seat linked list |
| `displaySeats()` | Displays all seats with their status |
| `bookSeat()` | Books an available seat or adds to waiting list |
| `cancelSeat()` | Cancels a booking and assigns to waiting list passenger |
| `addToWaitingList(const char *name)` | Adds passenger to waiting queue (enqueue) |
| `removeFromWaitingList()` | Removes first passenger from waiting queue (dequeue) |
| `displayWaitingList()` | Displays all passengers in waiting list |
| `findAvailableSeat()` | Finds the first available seat |
| `findSeatByNumber(int seatNum)` | Finds a seat by its number |
| `cleanup()` | Frees all allocated memory |

## ⚙️ How It Works

### Booking Process
1. User enters passenger name
2. System searches for first available seat
3. If found:
   - Seat is marked as booked
   - Passenger name is assigned to the seat
4. If all seats are booked:
   - Passenger is added to waiting list (FIFO queue)
   - System notifies passenger of waiting list status

### Cancellation Process
1. User enters seat number to cancel
2. Seat is marked as available
3. If waiting list exists:
   - First passenger from waiting list is automatically assigned
   - Waiting list is updated (FIFO principle)
4. System notifies of cancellation and automatic assignment

### Memory Management
- All nodes are dynamically allocated using `malloc`
- Memory is properly freed on program exit
- No memory leaks

## ⚠️ Constraints

- Seat numbers start from 1
- Passenger names can contain spaces (max 99 characters)
- Waiting list follows FIFO (First In First Out) principle
- The system automatically handles seat assignment from waiting list upon cancellation
- All operations are performed using pointer manipulation
- No built-in C data structures (vectors, queues) - linked lists only

## 📊 Example Output

```
*** TICKET BOOKING SYSTEM ***
Enter the number of seats: 3
System initialized with 3 seats

=== MENU ===
1. Display Seats
2. Book Seat
3. Cancel Seat
4. Display Waiting List
5. Exit
Enter your choice: 2

Enter passenger name: Alice
Seat 1 has been booked for Alice

=== MENU ===
1. Display Seats
... (show menu) ...
Enter your choice: 1

=== SEAT STATUS ===
  Seat No.        Passenger Name     Status
----------------------------------------
         1             Alice        Booked
         2           Available      Available
         3           Available      Available
```

## 📚 Learning Concepts

This project demonstrates:
- **Linked Lists**: Dynamic data structure with pointer manipulation
- **Queue Implementation**: FIFO waiting list using linked lists
- **Pointer Manipulation**: Extensive use of pointers for node management
- **Dynamic Memory**: malloc and free functions
- **Data Structure Design**: Custom structures for seats and passengers
- **Algorithm Design**: Booking and cancellation logic
- **Menu-Driven Programming**: User interaction patterns

## 🎓 Academic Use

This is a college-level Data Structures project designed to teach:
- Implementation of linked lists from scratch
- Queue operations (enqueue/dequeue)
- Practical applications of linked data structures
- Memory management in C
- System design and user interaction

## 📄 License

This project is open source and available for educational purposes.

---

**Author**: SRM University AP CSE Student  
**Course**: Data Structures  
**Date**: December 2025  
**Language**: C
