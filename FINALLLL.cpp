
#include <iostream>
#include <list>
#include <string>


using namespace std;

// Structer to represent a room
struct Room {
    string id;
    string type;
    bool isBooked;
    string guestName;
    double pricePerNight;
};

// Function prototypes
bool login();
void displayMenu();
void checkRoomAvailability(const list<Room>& rooms);
void bookRoom(list<Room>& rooms);
void displayBookings(const list<Room>& rooms);
void prepareBill(list<Room>& rooms);

int main() {
    // Initialize rooms with their details (with prices)
    list<Room> rooms = {
        {"101", "Single Room", false, "", 10000},
        {"102", "Double Room", false, "", 18000},
        {"103", "Twin Room", false, "", 12000},
        {"104", "Family Room", false, "", 45000},
        {"105", "Standard Room", false, "", 30000},
        {"106", "Deluxe Room", false, "", 36000},
        {"107", "AC Room  ", false, "", 25000},
        {"108", "NON-AC Room", false, "", 20000}
    };


    // Login
    if (!login()) {
        cout << "Incorrect username or ID. Please try again..." << endl;
        return 0;
    }


    //WELCOME NOTE
    cout << "* - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
    cout << "|            WELCOME TO MOON HOTEL!!!             |" << endl;
    cout << "* - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
    cout << " " << endl; 

    cout << " " << endl;
    cout << "|||_ _ _ Successfull Logged In _ _ _|||" << endl;
    cout << " " << endl;

    // Main menu loop
    while (true) {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            checkRoomAvailability(rooms);
            break;
        case 2:
            bookRoom(rooms);
            break;
        case 3:
            displayBookings(rooms);
            break;
        case 4:
            prepareBill(rooms);
            break;
        case 5:
            cout << "You're Logging Out. Thank you for visiting us.Come Again!!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            cout << " " << endl;
        }
    }

    return 0;
}

// Function to handle user login
bool login() {
    string username, password;
    cout << "| ------------ LOGIN ------------ |"<<endl;
    cout << " " << endl;
    cout << "Enter Your Username: ";
    cin >> username;
    cout << "Enter Your Password: ";
    cin >> password;
    cout << " " << endl;

    return (username == "sas51" && password == "kavee");
    
}

// Function to display the main menu
void displayMenu() {
    
    cout << "| ------------ MAIN MENU ------------ |" << endl;
    cout << "1. Check Room Availability" << endl;
    cout << "2. Book Room" << endl;
    cout << "3. Display Bookings" << endl;
    cout << "4. Prepare Bill" << endl;
    cout << "5. Logout" << endl;
}

// Function for checking room availability
void checkRoomAvailability(const list<Room>& rooms) {
    cout << "| ------------ ROOM AVAILABILITY ------------ |" << endl;
    cout << " " << endl;
    cout << "ID\tType\t\tPrice/Night\tStatus" << endl;
    for (const Room& room : rooms) {
        cout << room.id << "\t" << room.type << "\t" << room.pricePerNight << "\t\t";
        if (room.isBooked) {
            cout << "Booked by: " << room.guestName;
        }
        else {
            cout << "This Room is Available";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to book a room
void bookRoom(list<Room>& rooms) {
    cout << "| ------------ BOOK ROOM ------------ |" << endl;
    cout << " " << endl;
    cout << "Enter room ID to book: ";
    string roomId;
    cin >> roomId;

    for (Room& room : rooms) {
        if (room.id == roomId) {
            if (room.isBooked) {
                cout << "Room " << roomId << " is already booked." << endl;
            }
            else {
                cout << "Enter guest name for the room " << roomId << ": ";
                cin >> room.guestName;
                room.isBooked = true;

                // Get number of nights to stay
                int numNightsStayed;
                cout << "Enter number of nights you staying: ";
                cin >> numNightsStayed;

                // Calculate total price
                double totalPrice = numNightsStayed * room.pricePerNight;
                cout << "Room " << roomId << " booked successfully by Mr/Mrs " << room.guestName << " for " << numNightsStayed << " nights." << endl;
               
            }
            return;
        }
    }
    cout << "Invalid room ID. Please try again." << endl;
}

// Function to display bookings
void displayBookings(const list<Room>& rooms) {
    cout << "| ------------ BOOKINGS ------------ |" << endl;
    cout << " " << endl;
    for (const Room& room : rooms) {
        if (room.isBooked) {
            cout << "Room " << room.id <<" is Booked by"<< " - Guest: " << room.guestName << endl;
        }
    }
    cout << endl;
}

    

// Function to prepare bill
void prepareBill(list<Room>& rooms) {
    cout << "| ------------ PREPARE BILL ------------ |" << endl;
    cout << " " << endl;
    cout << "Enter room ID to prepare bill: ";
    string roomId;
    cin >> roomId;

    for (Room& room : rooms) {
        if (room.id == roomId && room.isBooked) {

            // Get number of nights to stay
            int numNightsStayed;
            cout << "Enter number of nights stayed: ";
            cin >> numNightsStayed;

            // Calculate total price
            double totalPrice = numNightsStayed * room.pricePerNight;
            cout << "Bill for room " << roomId << " prepared successfully. Total: Rs." << totalPrice << endl;
            return;
        }
    }
    cout << "Invalid room ID or room is not booked. Please try again." << endl;
}
