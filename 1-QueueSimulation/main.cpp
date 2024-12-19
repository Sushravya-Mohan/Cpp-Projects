#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

struct Ticket{
    int ticketNumber;
    string customerName;
    time_t arrivalTime;
    bool isProcessed;
};

class TicketQueue {
    private:
    static const int MAX_SIZE = 100;
    Ticket* queue;
    int front;
    int rear;
    int currentSize;
    int nextTicketNumber;

    public:
    TicketQueue() {
        queue = new Ticket[MAX_SIZE];
        front = 0;
        rear = -1;
        currentSize = 0;
        nextTicketNumber = 1001;    // Starting ticket number
    }

    ~TicketQueue() {
        delete[] queue;
    }

    bool isFull() {
        return currentSize >= MAX_SIZE;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more customers.\n";
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        queue[rear].ticketNumber = nextTicketNumber++;
        queue[rear].customerName = name;
        queue[rear].arrivalTime = time(nullptr);
        queue[rear].isProcessed = false;
        currentSize++;

        cout << "\nTicket issued successfully!"
             << "\nTicket Number: " << queue[rear].ticketNumber
             << "\nCustomer Name: " << queue[rear].customerName << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No cutomer in queue!\n";
            return;
        }

        cout << "\nProcessing ticket:"
             << "\nTicket Number: " << queue[front].ticketNumber
             << "\nCustomer Name: " << queue[front].customerName
             << "\nWaiting Time: " << difftime(time(nullptr), queue[front].arrivalTime) << "seconds\n";

        queue[front].isProcessed = true;
        front = (front + 1) % MAX_SIZE;
        currentSize--;         
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "\nCurrent Queue Status:\n";
        cout << setw(15) << "Ticket No." << setw(20) << "Customer Name" << setw(15) << "Wait Time\n";
        cout << string(50, '-') << endl;

        int index = front;
        for (int i = 0; i < currentSize; i++){
            cout << setw(15) << queue[index].ticketNumber
                 << setw(20) << queue[index].customerName
                 << setw(15) << difftime(time(nullptr), queue[index].arrivalTime) << "s\n";
            index = (index + 1) % MAX_SIZE;
        }        
    }

    int getQueueSize() {
        return currentSize;
    }
};

int main(){
    TicketQueue ticketSystem;
    int choice;
    string name;

    cout << "Welcome to Ticket Counter Simulation\n";

    while(true) {
        cout << "\n1. Issue New Ticket"
             << "\n2. Process Next Ticket"
             << "\n3. Display Queue"
             << "\n4. Show Queue Size"
             << "\n5. Exit"
             << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin.ignore();
                getline(cin, name);
                ticketSystem.enqueue(name);
                break;
            
            case 2:
                ticketSystem.dequeue();
                break;

            case 3:
                ticketSystem.displayQueue();
                break;
            
            case 4:
                cout << "\nCurrent queue size: " << ticketSystem.getQueueSize() << endl;
                break;

            case 5:
                cout << "\nExiting program. Thank you!\n";
                return 0;
            
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
    return 0;
}