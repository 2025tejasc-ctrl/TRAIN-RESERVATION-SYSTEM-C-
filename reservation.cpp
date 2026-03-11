#include <iostream>
using namespace std;

int main() {

    // Train Data
    int trainNo[2] = {12951, 12002};
    string trainName[2] = {"Mumbai Rajdhani", "Shatabdi Express"};
    int totalSeats[2] = {25, 30};
    int availableSeats[2] = {25, 30};
    int pricePerSeat[2] = {1500, 1200};

    int choice, number, seats;

    cout << "===== Railway Reservation System =====\n";

    do {
        cout << "\n1. View Trains";
        cout << "\n2. Book Seat";
        cout << "\n3. Cancel Seat";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1: // View trains
            for(int i = 0; i < 2; i++) {
                cout << "\nTrain No: " << trainNo[i];
                cout << "\nTrain Name: " << trainName[i];
                cout << "\nAvailable Seats: " << availableSeats[i];
                cout << "\nPrice per Seat: Rs." << pricePerSeat[i];
                cout << "\n---------------------------\n";
            }
            break;

        case 2: // Book seat
            cout << "Enter Train Number: ";
            cin >> number;

            for(int i = 0; i < 2; i++) {
                if(trainNo[i] == number) {

                    cout << "Enter Seats to Book: ";
                    cin >> seats;

                    if(seats <= availableSeats[i] && seats > 0) {

                        availableSeats[i] -= seats;
                        int totalBill = seats * pricePerSeat[i];

                        cout << "\n----- BILL -----\n";
                        cout << "Train: " << trainName[i] << endl;
                        cout << "Seats Booked: " << seats << endl;
                        cout << "Price per Seat: Rs." << pricePerSeat[i] << endl;
                        cout << "Total Amount: Rs." << totalBill << endl;
                        cout << "Booking Successful!\n";
                    }
                    else {
                        cout << "Not enough seats available!\n";
                    }
                }
            }
            break;

        case 3: // Cancel seat
            cout << "Enter Train Number: ";
            cin >> number;

            for(int i = 0; i < 2; i++) {
                if(trainNo[i] == number) {

                    cout << "Enter Seats to Cancel: ";
                    cin >> seats;

                    if(seats > 0 && availableSeats[i] + seats <= totalSeats[i]) {

                        availableSeats[i] += seats;
                        cout << "Cancellation Successful!\n";
                    }
                    else {
                        cout << "Invalid Cancellation!\n";
                    }
                }
            }
            break;

        case 4:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}