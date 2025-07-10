#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(const string& username) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) return true;
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "Register New User\nUsername: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    cout << "Registration successful.\n";
}

bool loginUser() {
    string username, password;
    cout << "Login\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username && p == password) {
            cout << "Login successful!\n";
            return true;
        }
    }

    cout << "Invalid credentials.\n";
    return false;
}

int main() {
    int choice;
    do {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose option: ";
        cin >> choice;
        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 3);
    return 0;
}

