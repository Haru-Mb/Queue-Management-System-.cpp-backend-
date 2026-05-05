#include <iostream>
#include <queue>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

// Ticket struct
struct Ticket {
    string number;
    string service;
};

// Data for Date
void getDate(int &year, int &month, int &day) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    year = (1900 + ltm->tm_year) % 100;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
}

// Ticket
string generateTicket(int year, int month, int count) {
    stringstream ss;
    ss << setw(2) << setfill('0') << year << "-";
    ss << setw(2) << setfill('0') << month;
    ss << setw(4) << setfill('0') << count;
    return ss.str();
}

// Print ticket
void printTicket(string number, string service) {
    cout << "\n\n";
    cout << "====================================\n";
    cout << "        ADMISSION OFFICE\n";
    cout << "====================================\n\n";

    cout << "      Service: " << service << "\n\n";
    cout << "      Ticket Number:\n";
    cout << "         " << number << "\n\n";

    cout << "   Please wait for your turn\n\n";
    cout << "====================================\n\n";
}

// User
void addCustomer(queue<Ticket> &line, int &counter, int &lastDay) {
    int choice;
    string service;

    cout << "\nSelect Service:\n";
    cout << "1. Enrollment\n";
    cout << "2. Document Request\n";
    cout << "3. Submit Documents\n";
    cout << "4. Payment\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: service = "Enrollment"; break;
        case 2: service = "Document Request"; break;
        case 3: service = "Submit Documents"; break;
        case 4: service = "Payment"; break;
        default:
            cout << "Invalid choice.\n";
            return;
    }

    int year, month, day;
    getDate(year, month, day);

    if (day != lastDay) {
        counter = 1;
        lastDay = day;
    }

    Ticket t;
    t.number = generateTicket(year, month, counter);
    t.service = service;

    line.push(t);
    printTicket(t.number, t.service);

    counter++;
}

// Admin
void serveCustomer(queue<Ticket> &line) {
    if (!line.empty()) {
        cout << "\nNow Serving: " << line.front().number
             << " (" << line.front().service << ")\n";
        line.pop();
    } else {
        cout << "\nNo customers in queue.\n";
    }
}

// Queue
void viewQueue(queue<Ticket> line) {
    if (line.empty()) {
        cout << "\nQueue is empty.\n";
        return;
    }

    cout << "\nCurrent Queue:\n";
    while (!line.empty()) {
        cout << line.front().number
             << " (" << line.front().service << ")\n";
        line.pop();
    }
}

// Admin Panel
void adminPanel(queue<Ticket> &line) {
    int choice;
    do {
        cout << "\n===== ADMIN PANEL =====\n";
        cout << "1. Serve Customer\n";
        cout << "2. View Queue\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: serveCustomer(line); break;
            case 2: viewQueue(line); break;
            case 3: cout << "Exiting Admin Panel...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}

// User Panel
void userPanel(queue<Ticket> &line, int &counter, int &lastDay) {
    int choice;
    do {
        cout << "\n===== USER PANEL =====\n";
        cout << "1. Get Ticket\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCustomer(line, counter, lastDay); break;
            case 2: cout << "Exiting User Panel...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 2);
}

// Main
int main() {
    queue<Ticket> line;
    int counter = 1;
    int lastDay = -1;

    int code;

    // Auth
    cout << "Enter system code: ";
    cin >> code;

    if (code != 1111) {
        cout << "Access Denied.\n";
        return 0;
    }

    int role;

    do {
        cout << "\nSelect Mode:\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> role;

        switch (role) {
            case 1: adminPanel(line); break;
            case 2: userPanel(line, counter, lastDay); break;
            case 3: cout << "System Closed.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (role != 3);

    return 0;
}