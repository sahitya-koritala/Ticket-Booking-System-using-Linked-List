# Ticket Booking System

A dynamic ticket booking system implemented in C using linked lists. This system simulates booking and cancellation of tickets for buses, flights, or movies with an integrated waiting list feature.

## Features

- **Seat Management**: Each seat is represented as a node in a linked list
- **Waiting List**: Queue implementation using linked list for passengers when all seats are booked
- **Booking System**: Book seats by passenger name with automatic waiting list management
- **Cancellation System**: Cancel bookings with automatic seat assignment from waiting list
- **Display Functions**: View all seats and waiting list status
- **Menu-Driven Interface**: Easy-to-use command-line interface

## Data Structures

### Seat Node
```c
typedef struct Seat {
    int seatNumber;
    char passengerName[100];
    int isBooked;  // 0 for available, 1 for booked
    struct Seat* next;
} Seat;
```

### Waiting List Node
```c
typedef struct WaitingPassenger {
    char passengerName[100];
    struct WaitingPassenger* next;
} WaitingPassenger;
```

## Requirements

- C compiler (GCC recommended)
- Standard C library

## Compilation

Compile the program using GCC:

```bash
gcc -o ticket_booking_system ticket_booking_system.c -Wall -Wextra
```

Or on Windows:

```bash
gcc -o ticket_booking_system.exe ticket_booking_system.c -Wall -Wextra
```

## Usage

### Running the Program

```bash
./ticket_booking_system
```

Or on Windows:

```bash
ticket_booking_system.exe
```

### Program Flow

1. **Initialization**: Enter the number of seats when prompted
2. **Menu Options**: Choose from the following options:
   - `1` - Display Seats: View all seats with their status and passenger names
   - `2` - Book Seat: Book a seat by entering passenger name
   - `3` - Cancel Seat: Cancel a booking by seat number
   - `4` - Display Waiting List: View all passengers in the waiting list
   - `5` - Exit: Exit the program and free all memory

## Example Usage

```
=== TICKET BOOKING SYSTEM ===
Enter the number of seats: 5

✓ System initialized with 5 seats

=== MENU ===
1. Display Seats
2. Book Seat
3. Cancel Seat
4. Display Waiting List
5. Exit
Enter your choice: 2

Enter passenger name: John Doe

✓ Seat 1 has been booked for John Doe

=== MENU ===
1. Display Seats
2. Book Seat
3. Cancel Seat
4. Display Waiting List
5. Exit
Enter your choice: 1

=== SEAT STATUS ===
Seat No.   Passenger Name       Status    
----------------------------------------
1          John Doe             Booked    
2          Available            Available 
3          Available            Available 
4          Available            Available 
5          Available            Available 
```

## Key Functions

- `initializeSeats(int numSeats)`: Initializes the seat linked list
- `displaySeats()`: Displays all seats with their status
- `bookSeat()`: Books an available seat or adds to waiting list
- `cancelSeat()`: Cancels a booking and assigns to waiting list passenger
- `addToWaitingList(const char* name)`: Adds passenger to waiting queue
- `removeFromWaitingList()`: Removes first passenger from waiting queue
- `displayWaitingList()`: Displays all passengers in waiting list
- `cleanup()`: Frees all allocated memory

## How It Works

1. **Booking Process**:
   - User enters passenger name
   - System searches for first available seat
   - If found, seat is booked and assigned to passenger
   - If all seats are booked, passenger is added to waiting list

2. **Cancellation Process**:
   - User enters seat number to cancel
   - Seat is marked as available
   - If waiting list exists, first passenger is automatically assigned to freed seat
   - Waiting list is updated (FIFO queue)

3. **Memory Management**:
   - All nodes are dynamically allocated using `malloc()`
   - Memory is properly freed on program exit
   - No memory leaks

## Constraints

- Uses linked lists exclusively for seat management (no arrays)
- Uses linked list for queue implementation (waiting list)
- No built-in C data structures for seat management or queue logic
- All operations are performed using pointer manipulation

## Notes

- Seat numbers start from 1
- Passenger names can contain spaces
- Waiting list follows FIFO (First In First Out) principle
- The system automatically handles seat assignment from waiting list upon cancellation

## License

This project is open source and available for educational purposes.

