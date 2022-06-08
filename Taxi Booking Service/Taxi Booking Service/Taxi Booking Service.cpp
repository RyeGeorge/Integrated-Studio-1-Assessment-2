#include <iostream>
#include <string> //For using string variable types
#include <fstream> //To handle file operations
#include <sstream> //To handle string stream conversion
#include <vector> //To handle unlimited structure array
#include <stdlib.h>  //Allows us to use "System("CLS") to clear the console"

using namespace std;

//Data structures
struct Customer {
    string firstName;
    string lastName;
    string emailAddress;
    string phoneNumber;
    string homeAddress;
    char password[20];

    Customer() {  //Default Constructor
        firstName = "firstName";
        lastName = "lastName";
        emailAddress = "emailAddress";
        phoneNumber = "phoneNumber";
        homeAddress = "homeAddress";
    }
};

struct Driver {
    string driverName;
    string licensePlate;
    string vehicleMake;
    string vehicleModel;

    Driver() {
        driverName = "driverName";
        licensePlate = "licensePlate";
        vehicleMake = "vehicleMake";
        vehicleModel = "vehicleModel";
    }
};

struct Trip {
    string customerName;
    string customerPhoneNumber;
    string destinationAddress;
    int tripTime; //Minutes
    string pickupTime; //Confirm varibale type
    string tripDate;
    float price;
    string pickupLocation;
    int passengers;
    bool tripCompleted;

    Trip() {
        customerName = "customerName";
        customerPhoneNumber = "customerPhoneNumber";
        destinationAddress = "destinationAddress";
        tripTime = 1;
        pickupTime = "pickupTime";
        tripDate = "tripDate";
        price = 1;
        pickupLocation = "pickupLocation";
        passengers = 1;
        tripCompleted = true;
    }
};

vector <Customer> RegisterNewUser(vector<Customer>& customer);
vector <Trip> NewTrip(vector<Trip>& trip);
void WriteToFile(vector<Customer>& customer);
void OutputDetails(vector<Customer>& customer);

int CheckPassword(char passwd[]);
int Re_enterPassword(char  passwd[]);

void Login();
void CheckInput(char);
void CompanyHeader();

void CustomerMenu();
void DriverMenu();
void AdminMenu();


int main()
{
    vector<Customer> customer;
    vector<Customer> customerFromFile;
    vector<Trip> trip;
    vector<Trip> tripFromFile;
    NewTrip(trip);


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
    case 'a': AdminMenu(); //Login();
        break;

    case 'b': //RegisterNewUser();
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

    cout << "Enter your Email: ";
    cin >> tempEmail;
    //Check email in file

    cout << "\nEnter your password: ";
    cin >> tempPassword;
    //Check password in file

    //If user is customer
    CustomerMenu();

    //If user is driver
    DriverMenu();

    //If user is admin
    AdminMenu();

}

void CheckInput(char input) {

    //  Rye George

    cin.clear();
    cin.ignore(100, '\n');
    cout << "Error: Incorrect Input\n";
    cout << "Please re-enter your choice: ";

}

void CompanyHeader() {
    // system("CLS");
    cout << "------------------------------------------------\n";
    cout << "            Taxi Booking Service\n";
    cout << "------------------------------------------------\n\n";

};


//registerNewUser to take user input
vector <Customer> RegisterNewUser(vector<Customer>& customer) {

    // Shaun Cooper
    CompanyHeader();

    cout << "\nFrom registerNewUser Function";
    cout << "\n***************************";
    Customer m;//we receive one user data at any given time

    cout << "\nPlease enter your First Name(s): ";
    getline(cin, m.firstName);
    cout << "Please enter your Last Name(s): ";
    getline(cin, m.lastName);
    cout << "Please enter your Home Address: ";
    getline(cin, m.homeAddress);
    cout << "Please enter your Email Address: ";
    cin >> m.emailAddress;
    cout << "Please enter your Phone Number: ";
    cin >> m.phoneNumber;
    cin.ignore();

    int length = strlen(m.password);
    while (1) {
        do {
            cout << "\nPlease enter a password which should contain :" << endl;
            cout << " * at least 8 characters" << endl;
            cout << " * at least one upper and lowercase letter " << endl;
            cout << " * at least one digit " << endl;
            cout << "Enter password: ";
            cin.getline(m.password, 20);
            length = strlen(m.password);
        } while (length < 8);
        if (CheckPassword(m.password)) //if return 1 pass below
            continue;
        if (Re_enterPassword(m.password))
            continue;

        break;
    }

    customer.push_back(m);

    cout << "\ntest output: " << m.firstName << ", " << m.lastName << ", " << m.emailAddress << ", " << m.homeAddress << ", " << m.phoneNumber << ", " << m.password;
    cout << endl;
    //outputDetails(customer);

    return (customer);

}

int CheckPassword(char passwd[]) //Check complexity of password
{
    //Shaun Cooper

    int count;
    bool upper_flag = 0, lower_flag = 0, digit_flag = 0;
    for (count = 0; count < strlen(passwd); count++)
    {
        if (isupper(passwd[count]))
            upper_flag = 1;
        else if (islower(passwd[count]))
            lower_flag = 1;
        else if (isdigit(passwd[count]))
            digit_flag = 1;
    }
    if (!upper_flag)
    {
        cout << "The password does not contain an uppercase letter.\n";
    }

    if (!lower_flag)
    {
        cout << "The password does not contain a lowercase letter.\n";
    }
    if (!digit_flag)
    {
        cout << "The password does not contain a digit.\n";
    }
    if (upper_flag && lower_flag && digit_flag)
        return 0;   //if all pass
    else
        return 1;
}

int Re_enterPassword(char  passwd[]) //Check the 'Re-enter' password is the same as the first password entered
{
    //Shaun Cooper

    char compare_password[20] = { 0, };
    cout << "Re Enter Your password" << endl;
    cin.getline(compare_password, 20);
    if (strcmp(passwd, compare_password))
    {
        cout << "Password does not match!" << endl;
        return 1;
    }
    return 0;
}


void OutputDetails(vector<Customer>& customer) { //outputMarker to produce the output on the console
    //Shaun Cooper

    cout << "\nFrom outputDetails Function";
    cout << "\n***************************";
    int i;
    for (i = 0; i < customer.size(); i++) {
        cout << "\nThe name you entered is: " << customer[i].firstName;
        cout << "\nThe phone number you entered is: " << customer[i].phoneNumber;
    }
}


void WriteToFile(vector<Customer>& customer) { //writeToFile function facilitates the storing of customer detials
    //Shaun Cooper

    cout << "\nWriting to file ";
    cout << "\n***************************";
    int i;
    fstream myFile("customerDetails.csv", ios::app);
    for (i = 0; i < customer.size(); i++) {
        myFile << customer[i].firstName << "," << customer[i].lastName << "," << customer[i].emailAddress << "," << customer[i].homeAddress << "," << customer[i].phoneNumber << "," << customer[i].password << endl;
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

vector <Trip> NewTrip(vector<Trip>& trip) { //Enter a new trip
    //Shaun Cooper

    cout << "--------------------------" << endl;
    cout << "     New Trip Details     " << endl;
    cout << "--------------------------" << endl;

    Trip m;//we receive one user data at any given time
    cout << "\nEnter the destination address: ";
    getline(cin, m.destinationAddress);
    cout << "Enter your pickup address: ";
    getline(cin, m.pickupLocation);
    cout << "Enter the date for the trip (dd/mm/yyyy): ";
    getline(cin, m.tripDate);
    cout << "Enter the time you would like to be picked up: ";
    getline(cin, m.pickupTime);
    cout << "Enter customer name: ";
    getline(cin, m.customerName);
    cout << "How many passengers will there be?: ";
    cin >> m.passengers;
    cout << "How long will the trip take? (mins): ";
    cin >> m.tripTime;
    m.price = (m.tripTime * 1.5) * (m.passengers * 1.15 + 1); // $1.50 per min + 15% for 1 passenger, then adding 15% for each successive passenger.
    cout << "\nThe price of your trip is: $" << m.price << endl;
    cout << endl;

    trip.push_back(m);

    //Write trip details to databse
    int i;
    fstream myFile("tripDetails.csv", ios::app);
    for (i = 0; i < trip.size(); i++) {
        myFile << trip[i].customerName << "," << trip[i].tripDate << "," << trip[i].pickupTime << "," << trip[i].pickupLocation << "," << trip[i].destinationAddress << "," << trip[i].tripTime << "," << trip[i].passengers << "," << trip[i].price << endl;
    }
    myFile.close();

    return (trip);
}