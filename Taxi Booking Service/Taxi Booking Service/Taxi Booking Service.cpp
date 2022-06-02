#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//Data structures
struct Customer {
    char customerFirstName[15], customerLastName[15], customerPassword[15], customerEmail[30], customerAddress[30];
    int customerPhoneNumber;
};

struct Driver {
    char driverName[30];
    char licensePlate[6];
    string vehicleMake;
    string vehicleModel;
};

struct Trip {
    char customerName[30];
    char customerPhoneNumber[30];
    char destinationAddress[100];
    int tripTime; //Minutes
    // pickupTime; //Confirm varibale type
    string tripDate;
    float price;
    char pickupLocation[100];
    int passengers;
    bool tripCompleted;
};


void Login();
void RegisterNewUser();
void CheckInput();
void CompanyHeader();


int main()
{

    CompanyHeader();

    cout << "Please choose one of the following options:\n";
    cout << "a) Login\n";
    cout << "b) Register a new account\n";
    cout << "c) Exit\n";

    char input;
    cin >> input;
    CheckInput();

    switch (input) {
    case 'a': Login();
        break;
    case 'b': RegisterNewUser(); 
        break;
    case 'c': break;
        break;
    }
}

void Login() {

}

void RegisterNewUser() {

}

void CheckInput() {

}

void CompanyHeader() {
    cout << "------------------------------------------------\n";
    cout << "            Taxi Booking Service\n";
    cout << "------------------------------------------------\n\n";
}

