#include <iostream>
using namespace std;

int main() {
    int balance = 10000; // default balance
    int pin = 0000; // default pin
    int attempts = 0; // counter for pin attempts

    while (true) {
        cout << "Welcome to Mobile Money System" << endl;
        cout << "Please select an option:" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Change PIN" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1) {
            cout << "Please enter your PIN: ";
            int input_pin;
            cin >> input_pin;
            if (input_pin == pin) {
                cout << "Authentication successful." << endl;
            } else {
                cout << "Invalid PIN." << endl;
            }
        } else if (option == 2) {
            cout << "Please enter your current PIN: ";
            int current_pin;
            cin >> current_pin;
            if (current_pin == pin) {
                cout << "Please enter your new PIN: ";
                int new_pin;
                cin >> new_pin;
                pin = new_pin;
                cout << "PIN changed successfully." << endl;
            } else {
                cout << "Invalid PIN." << endl;
            }
        } else if (option == 3) {
            cout << "Please enter your PIN: ";
            int input_pin;
            cin >> input_pin;
            if (input_pin == pin) {
                cout << "Your balance is: " << balance << endl;
            } else {
                cout << "Invalid PIN." << endl;
                attempts++;
                if (attempts >= 3) {
                    cout << "Too many failed attempts. Exiting." << endl;
                    break;
                }
            }
        } else if (option == 4) {
            cout << "Please enter the recipient's phone number: ";
            string recipient;
            cin >> recipient;
            cout << "Please enter the amount to send: ";
            int amount;
            cin >> amount;
            cout << "Please enter your PIN: ";
            int input_pin;
            cin >> input_pin;
            if (input_pin == pin) {
                if (amount <= balance) {
                    balance -= amount;
                    cout << "Sent " << amount << " to " << recipient << " successfully. Your balance is now: " << balance << endl;
                } else {
                    cout << "Insufficient funds." << endl;
                }
            } else {
                cout << "Invalid PIN." << endl;
            }
        } else if (option == 5) {
            cout << "Exiting Mobile Money System. Thank you!" << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

