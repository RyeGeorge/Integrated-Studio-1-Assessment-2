#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>  //Allows us to use "System("CLS") to clear the console"

using namespace std;

//Data structures
struct Customer { 
  string customerName; 
  int customerPhoneNumber;

Customer() {  //Default Constructor
    customerName = "CustomerNameNULL";
    customerPhoneNumber = NULL;
}

Customer(string cN, int cPN){
    customerName = cN;
    customerPhoneNumber = cPN;
}

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

vector <Customer> registerNewUser(vector<Customer> &customer);
void writeToFile(vector<Customer>& customer);

void Login();
bool ReadFromFile(fstream&, string, string, string);
void RegisterNewUser();
void CheckInput(char);
void CompanyHeader();

void CustomerMenu();
void DriverMenu();
void AdminMenu();


int main()
{
    vector<Customer> customer;
    vector<Customer> customerFromFile;
    vector <Customer> registerNewUser(vector<Customer> &customer);

    CompanyHeader();

    cout << "Please choose one of the following options:\n";
    cout << "a) Login\n";
    cout << "b) Register a new account\n";
    cout << "c) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }
    

    switch (input) {
    case 'a': Login();
        break;

    case 'b': registerNewUser(customer);
        break;

    case 'c': break;
        break;
    }
}

void Login() {
    
    //Rye George
    
    system("CLS");
    CompanyHeader();

    cout << "                Login Menu                   \n";

    string tempEmail, tempPassword;

    cout << "Please choose one of the following options:\n";
    cout << "a) Customer login\n";
    cout << "b) Driver login\n";
    cout << "c) Admin login\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }

    fstream customerFile, driverFile, adminFile;

    cout << "Enter your Email: ";
    cin >> tempEmail;

    cout << "\nEnter your password: ";
    cin >> tempPassword;

    switch (input) {
    case 'a': 
        if (ReadFromFile(customerFile, "customerDetails.txt", tempPassword, tempEmail)) {
            CustomerMenu();
        }
        else {
            cout << "\nIncorrect info";
        }
        break;

    case 'b': 
        if (ReadFromFile(driverFile, "driverDetails.txt", tempPassword, tempEmail)) {
            DriverMenu();
        }
        else {
            cout << "\nIncorrect info";
        }
        break;

    case 'c': 
        if (ReadFromFile(adminFile, "adminDetails.txt", tempPassword, tempEmail)) {
            AdminMenu();
        }
        else {
            cout << "\nIncorrect info";
        }
        break;
    }

}

bool ReadFromFile(fstream &file, string fileName, string pw, string e) {

    //Rye George

    bool email = false, password = false;

    file.open(fileName, ios::app);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line == e) {
                email = true;
            }
            if (line == pw) {
                password = true;
            }
        }
        file.close();
    }

    if (email && password) {
        return true;
    }
    else {
        cout << "email: " << email << "   " << "password: " << password;
        return false;
    }
}

void RegisterNewUser() {

}

void CheckInput(char input) {

    //  Rye George
    
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Error: Incorrect Input\n";
    cout << "Please re-enter your choice: ";
    
}

void CompanyHeader() {
    cout << "------------------------------------------------\n";
    cout << "            Taxi Booking Service\n";
    cout << "------------------------------------------------\n\n";
   
};


//registerNewUser to take user input
vector <Customer> registerNewUser(vector<Customer> &customer) {
    cout << "\nFrom registerNewUser Function";
    cout << "\n***************************";
    Customer m;//we receive one user data at any given time
    char answer = 'y';
    while (tolower(answer) == 'y') {
        cout << "\nPlease enter your full name: ";
        getline(cin,m.customerName);
        cout << "\nPlease enter the price of the marker: ";
        cin >> m.customerPhoneNumber;
        customer.push_back(m);
        
        cout << "\nDo you wish to continue inputting data?";
        cin >> answer;
    }

    return (customer);

}

//writeToFile function facilitates the storing of customer detials
void writeToFile(vector<Customer>& customer){
    cout << "\nWriting to file ";
    cout << "\n***************************";
    int i;
    fstream myFile("customerDetails.csv", ios::app);
    for (i = 0; i < customer.size(); i++) {
        myFile << customer[i].customerName << "," << customer[i].customerPhoneNumber << endl;
    }
    myFile.close();
}



//
//Menu functions
//


void CustomerMenu() {

    // Rye George

    system("CLS");  //Clears console

    CompanyHeader();
    cout << "               Customer Menu                 \n\n";

    cout << "Please choose one of the following options:\n";
    cout << "a) Enter new trip\n";
    cout << "b) Update account details\n";
    cout << "c) Search trip history\n";
    cout << "d) Report lost property\n";
    cout << "e) Report complaint\n";
    cout << "f) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }

    switch (input) {
    case 'a': //Enter New Trip
        break;

    case 'b': //Update user details
        break;

    case 'c': //Search trip history
        break;

    case 'd': //Report lost propery 
        break;

    case 'e': //Report complaint
        break;

    case 'f': break;
        break;
    }
}

void DriverMenu() {

    // Rye George

    system("CLS");  //Clears console

    CompanyHeader();
    cout << "                Driver Menu                 \n\n";

    cout << "Please choose one of the following options:\n";
    cout << "a) Find new trip\n";
    cout << "b) Search trip history\n";
    cout << "c) Report found property\n";
    cout << "d) Update account details\n";
    cout << "e) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }

    switch (input) {
    case 'a': //Find new trip
        break;

    case 'b': //Search trip history
        break;

    case 'c': //Report found property
        break;

    case 'd': //Update Account details
        break;

    case 'e': break;
        break;
    }
}

void AdminMenu() {

    // Rye George

    system("CLS");  //Clears console

    CompanyHeader();
    cout << "                 Admin Menu                 \n\n";

    cout << "Please choose one of the following options:\n";
    cout << "a) Search all trip history\n";
    cout << "b) Manage drivers\n";
    cout << "c) Manage customers\n";
    cout << "d) Search lost/found property\n";
    cout << "e) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }

    switch (input) {
    case 'a': //Search all trip history
        break;

    case 'b': //Manage drivers
        break;

    case 'c': //Mange customers
        break;

    case 'd': //Search lost/found property
        break;

    case 'e': break;
        break;
    }
}