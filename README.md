# Ticket Booking System using Linked Lists

A dynamic ticket booking system implemented in C using linked lists. This system simulates booking and cancellation of tickets for buses, flights, or movies with an integrated waiting list feature.

## Features

### Core Functionality
- Add new seat records
- Book seat by entering passenger name
- Cancel seat booking
- View all seats and their status
- Automatic waiting list management
- FIFO queue for waiting passengers

### Advanced Features
- Automatic seat assignment from waiting list upon cancellation
- Dynamic memory allocation and deallocation
- Menu-driven command-line interface
- Input validation and error handling

## Data Structures

### Seat Node
```c
typedef struct Seat {
    int seatNumber;
    char passengerName[100];
    int isBooked;  // 0 for available, 1 for booked
    struct Seat *next;
} Seat;
```

### Waiting List Node (Queue)
```c
typedef struct WaitingPassenger {
    char passengerName[100];
    struct WaitingPassenger *next;
} WaitingPassenger;
```

## How It Works

### Booking Process
1. User enters passenger name
2. System searches for first available seat
3. If seat available: Seat is booked and assigned to passenger
4. If all seats booked: Passenger is added to waiting list

### Cancellation Process
1. User enters seat number to cancel
2. Seat is marked as available
3. If waiting list exists: First passenger is automatically assigned to freed seat
4. Waiting list is updated (FIFO principle)

### Memory Management
- All nodes dynamically allocated using `malloc`
- Memory properly freed on program exit
- No memory leaks

## How to Run

### Compilation

**On Linux/Mac:**
```bash
gcc -o ticketbookingsystem ticket_booking_system.c -Wall -Wextra
```

**On Windows:**
```bash
gcc -o ticketbookingsystem.exe ticket_booking_system.c -Wall -Wextra
```

### Running

**Linux/Mac:**
```bash
./ticketbookingsystem
```

**Windows:**
```bash
ticketbookingsystem.exe
```

## Menu Options

1. **Display Seats** - View all seats with their status
2. **Book Seat** - Book a seat by entering passenger name
3. **Cancel Seat** - Cancel a booking by seat number
4. **Display Waiting List** - View all passengers in waiting list
5. **Exit** - Exit program and free all memory

## Key Functions

- `initializeSeats()` - Initialize the seat linked list
- `displaySeats()` - Display all seats with status
- `bookSeat()` - Book an available seat
- `cancelSeat()` - Cancel a booking
- `addToWaitingList()` - Add passenger to waiting queue
- `removeFromWaitingList()` - Remove passenger from waiting queue
- `displayWaitingList()` - Display all waiting passengers
- `cleanup()` - Free all allocated memory

## Requirements

- C compiler (GCC recommended)
- Standard C library (stdio.h, stdlib.h, string.h)

## Project Details

This is a college-level Data Structures project that demonstrates:
- Implementation of linked lists from scratch
- Queue operations (enqueue/dequeue)
- Pointer manipulation in C
- Dynamic memory management
- Practical data structure applications

## Author

**SRM University AP - Second Year CSE Student**

December 2025

## License

This project is open source and available for educational purposes.
