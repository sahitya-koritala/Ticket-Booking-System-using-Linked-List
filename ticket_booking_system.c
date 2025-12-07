#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a seat node
typedef struct Seat {
    int seatNumber;
    char passengerName[100];
    int isBooked;  // 0 for available, 1 for booked
    struct Seat *next;
} Seat;

// Structure for waiting list node (queue)
typedef struct WaitingPassenger {
    char passengerName[100];
    struct WaitingPassenger *next;
} WaitingPassenger;

// Global pointers
Seat *seatList = NULL;
WaitingPassenger *waitingListFront = NULL;
WaitingPassenger *waitingListRear = NULL;
int totalSeats = 0;

// Function to initialize seats
void initializeSeats(int numSeats) {
    totalSeats = numSeats;
    seatList = NULL;
    
    // Create linked list of seats
    for (int i = numSeats; i >= 1; i--) {
        Seat *newSeat = (Seat *)malloc(sizeof(Seat));
        newSeat->seatNumber = i;
        strcpy(newSeat->passengerName, "");
        newSeat->isBooked = 0;
        newSeat->next = seatList;
        seatList = newSeat;
    }
}

// Function to display all seats
void displaySeats() {
    printf("\n=== SEAT STATUS ===\n");
    printf("%10s %20s %10s\n", "Seat No.", "Passenger Name", "Status");
    printf("----------------------------------------\n");
    
    Seat *current = seatList;
    while (current != NULL) {
        printf("%10d %20s %10s\n", current->seatNumber, 
               current->isBooked ? current->passengerName : "Available",
               current->isBooked ? "Booked" : "Available");
        current = current->next;
    }
    printf("\n");
}

// Function to find an available seat
Seat *findAvailableSeat() {
    Seat *current = seatList;
    while (current != NULL) {
        if (current->isBooked == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to add passenger to waiting list (enqueue)
void addToWaitingList(const char *name) {
    WaitingPassenger *newPassenger = (WaitingPassenger *)malloc(sizeof(WaitingPassenger));
    strcpy(newPassenger->passengerName, name);
    newPassenger->next = NULL;
    
    if (waitingListRear == NULL) {  // First passenger in waiting list
        waitingListFront = waitingListRear = newPassenger;
    } else {
        waitingListRear->next = newPassenger;
        waitingListRear = newPassenger;
    }
}

// Function to remove passenger from waiting list (dequeue)
char *removeFromWaitingList() {
    if (waitingListFront == NULL) {
        return NULL;  // Waiting list is empty
    }
    
    WaitingPassenger *temp = waitingListFront;
    char *name = (char *)malloc(100 * sizeof(char));
    strcpy(name, temp->passengerName);
    
    waitingListFront = waitingListFront->next;
    if (waitingListFront == NULL) {
        waitingListRear = NULL;  // Waiting list is now empty
    }
    
    free(temp);
    return name;
}

// Function to book a seat
void bookSeat() {
    char name[100];
    printf("\nEnter passenger name: ");
    scanf("%99s", name);
    
    Seat *availableSeat = findAvailableSeat();
    if (availableSeat != NULL) {  // Seat is available
        availableSeat->isBooked = 1;
        strcpy(availableSeat->passengerName, name);
        printf("Seat %d has been booked for %s\n", availableSeat->seatNumber, name);
    } else {  // All seats are booked, add to waiting list
        addToWaitingList(name);
        printf("All seats are booked. %s has been added to the waiting list.\n", name);
    }
}

// Function to find seat by seat number
Seat *findSeatByNumber(int seatNum) {
    Seat *current = seatList;
    while (current != NULL) {
        if (current->seatNumber == seatNum) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to cancel a seat
void cancelSeat() {
    int seatNum;
    printf("\nEnter seat number to cancel: ");
    scanf("%d", &seatNum);
    
    Seat *seat = findSeatByNumber(seatNum);
    if (seat == NULL) {
        printf("Invalid seat number!\n");
        return;
    }
    
    if (seat->isBooked == 0) {
        printf("Seat %d is already available!\n", seatNum);
        return;
    }
    
    char cancelledName[100];
    strcpy(cancelledName, seat->passengerName);
    
    // Free the seat
    seat->isBooked = 0;
    strcpy(seat->passengerName, "");
    printf("Seat %d booking cancelled for %s\n", seatNum, cancelledName);
    
    // Check if there's someone in the waiting list
    if (waitingListFront != NULL) {
        char *waitingName = removeFromWaitingList();
        if (waitingName != NULL) {
            seat->isBooked = 1;
            strcpy(seat->passengerName, waitingName);
            printf("Seat %d has been automatically assigned to %s from waiting list\n", seatNum, waitingName);
            free(waitingName);
        }
    }
}

// Function to display waiting list
void displayWaitingList() {
    printf("\n=== WAITING LIST ===\n");
    if (waitingListFront == NULL) {
        printf("Waiting list is empty.\n");
        return;
    }
    
    printf("%5s %20s\n", "No.", "Passenger Name");
    printf("---------------------------\n");
    
    WaitingPassenger *current = waitingListFront;
    int position = 1;
    while (current != NULL) {
        printf("%5d %20s\n", position, current->passengerName);
        current = current->next;
        position++;
    }
    printf("\n");
}

// Function to free all memory
void cleanup() {
    // Free seat list
    Seat *currentSeat = seatList;
    while (currentSeat != NULL) {
        Seat *temp = currentSeat;
        currentSeat = currentSeat->next;
        free(temp);
    }
    
    // Free waiting list
    while (waitingListFront != NULL) {
        WaitingPassenger *temp = waitingListFront;
        waitingListFront = waitingListFront->next;
        free(temp);
    }
    waitingListRear = NULL;
}

// Main function with menu
int main() {
    int numSeats;
    int choice;
    
    printf("\n*** TICKET BOOKING SYSTEM ***\n");
    printf("Enter the number of seats: ");
    scanf("%d", &numSeats);
    
    if (numSeats <= 0) {
        printf("Invalid number of seats!\n");
        return 1;
    }
    
    initializeSeats(numSeats);
    printf("System initialized with %d seats\n", numSeats);
    
    while (1) {
        printf("\n=== MENU ===");
        printf("\n1. Display Seats\n2. Book Seat\n3. Cancel Seat\n4. Display Waiting List\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelSeat();
                break;
            case 4:
                displayWaitingList();
                break;
            case 5:
                printf("\nExiting system...\n");
                cleanup();
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
