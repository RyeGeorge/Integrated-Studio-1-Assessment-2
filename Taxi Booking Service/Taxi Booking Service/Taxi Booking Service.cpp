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
    string firstName;
    string lastName;
    string emailAddress;
    string phoneNumber;
    string homeAddress;
    string licensePlate;
    string vehicleMake;
    string vehicleModel;
    char password[20];

    Driver() {
        firstName = "firstName";
        lastName = "lastName";
        emailAddress = "emailAddress";
        phoneNumber = "phoneNumber";
        homeAddress = "homeAddress";
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
    string pickupTime;
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

struct LostProperty {
    string itemType;
    string identifyingFeature;
    float value;
};

struct FoundProperty {
    string itemType;
    string identifyingFeature;
    float value;
};

vector <Customer> RegisterNewCustomer(vector<Customer>& customer);
vector <Trip> NewTrip(vector<Trip>& trip);
//vector <LostProperty> ReportLostProperty(vector<LostProperty>& lProperty);
void WriteToFile(vector<Customer>& customer);
void OutputDetails(vector<Customer>& customer);

int CheckPassword(char passwd[]);
int Re_enterPassword(char  passwd[]);

void Login();
bool ReadFromLoginFile(string, string, string);
void CheckInput(char);
void CompanyHeader();

void FileComplaint();
void DisplayComplaints();

void ViewCustomerDetails();
void ViewDriverDetails();
void PrintAccountDetails(string);
void SearchAccountDetails(string);
void UpdateUserDetails(string);

void CustomerMenu();
void DriverMenu();
void AdminMenu();
void ManageCustomersMenu();
void ManageDriversMenu();


int main()
{
    vector<Customer> customer;
    vector<Customer> customerFromFile;
    vector<Trip> trip;
    vector<Trip> tripFromFile;
    //NewTrip(trip);
    vector<LostProperty> lProperty;
    //ReportLostProperty(lProperty);


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

    cin.clear();
    cin.ignore(100, '\n');

    switch (input) {
    case 'a': AdminMenu(); //Login();
        break;

    case 'b': RegisterNewCustomer(customer);
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

    string tempEmail;
    string tempPassword;

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


    switch (input) {
    case 'a':
        for (int i = 3; i > 0; i--) {

            cout << "Enter your Email: ";
            cin >> tempEmail;

            cout << "\nEnter your password: ";
            cin >> tempPassword;

            if (ReadFromLoginFile("customerDetails.csv", tempPassword, tempEmail)) {
                CustomerMenu();
                break;
            }

            cout << "\nPassword or Email are incorrect, you have " << i - 1 << " attemps left\n\n\n";
        }
        break;
    }

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
vector <Customer> RegisterNewCustomer(vector<Customer>& customer) {

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

    fstream myFile;
    myFile.open("customerDetails.csv", ios::app);

    myFile << m.firstName << "," << m.lastName << "," << m.emailAddress << "," << m.homeAddress << "," << m.phoneNumber << "," << m.password << "," << endl;
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


bool ReadFromLoginFile(string fileName, string pw, string e) {

    //Rye George

    fstream myFile;
    myFile.open(fileName, ios::in);

    if (myFile.is_open()) {

        string line;
        string firstName, lastName, email, address, phoneNumber, password;

        while (getline(myFile, line))
        {
            stringstream ss(line);
            getline(ss, firstName, ',');
            getline(ss, lastName, ',');
            getline(ss, email, ',');
            getline(ss, address, ',');
            getline(ss, phoneNumber, ',');
            getline(ss, password, ',');

            if ((password == pw) && (email == e))
                return true;
        }
        myFile.close();
    }
    else {
        cout << "File not open";
    }
    return 0;
}


void FileComplaint() {

    //Rye George

    string driverFirstName, driverLastName, complaint;

    cout << "\nFill out the below information to file a complaint against a driver\n\n";

    cout << "Enter drivers first name: ";
    cin >> driverFirstName;
    cout << endl;

    cout << "Enter drivers last name: ";
    cin >> driverLastName;
    cout << endl;

    //Clears console input
    cin.clear();
    cin.ignore(100, '\n');

    cout << "What is your complaint: ";
    getline(cin, complaint);
    cout << endl << endl;


    //Write complaint into file
    fstream myFile;

    myFile.open("driverComplaints.csv", ios::app);
    if (myFile.is_open()) {

        myFile << driverFirstName << "," << driverLastName << "," << complaint << "," << endl;
    }
}

void DisplayComplaints() {

    //Rye George

    fstream myFile;

    myFile.open("driverComplaints.csv", ios::in);
    if (myFile.is_open()) {
        string line;
        string driverFirstName, driverLastName, complaint;
        int complaintNum = 0;

        while (getline(myFile, line)) {

            stringstream ss(line);
            getline(ss, driverFirstName, ',');
            getline(ss, driverLastName, ',');
            getline(ss, complaint, ',');
            complaintNum++;

            //Print complaint to console
            cout << endl << complaintNum << ":   Driver:     " << driverFirstName << " " << driverLastName << endl;
            cout << "     Complaint:  " << complaint << endl << endl;
        }
    }
}

void ViewCustomerDetails() {

    //Rye George

    cout << "\nTo view customer details, please choose one of the following options:\n";

    cout << "a) Search customer details\n";
    cout << "b) View all customer details\n";
    cout << "c) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }


    switch (input) {
    case 'a': SearchAccountDetails("customerDetails.csv");
        break;
    case 'b': PrintAccountDetails("customerDetails.csv");
        break;
    case 'c': break;
        break;
    }
}

void ViewDriverDetails() {

    //Rye George

    cout << "\nTo view driver details, please choose one of the following options:\n";

    cout << "a) Search driver details\n";
    cout << "b) View all driver details\n";
    cout << "c) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }


    switch (input) {
    case 'a': //SearchAccountDetails("driverDetails.csv");
        break;
    case 'b': //PrintAccountDetails("driverDetails.csv");
        break;
    case 'c': break;
        break;
    }
}

void SearchAccountDetails(string fileName) {

    //Rye George

    fstream myFile;
    string fName, lName;

    cout << "\nEnter users first name: ";
    cin >> fName;

    cout << "Enter users last name: ";
    cin >> lName;

    myFile.open(fileName, ios::in);
    if (myFile.is_open()) {

        string line;
        string firstName, lastName, email, address, phoneNumber, password;

        while (getline(myFile, line)) {

            stringstream ss(line);

            getline(ss, firstName, ',');
            getline(ss, lastName, ',');
            getline(ss, email, ',');
            getline(ss, address, ',');
            getline(ss, phoneNumber, ',');
            getline(ss, password, ',');

            if (firstName == fName && lastName == lName) {
                cout << endl << firstName << " " << lastName << endl;
                cout << "Email: \t\t" << email << "\nAddress: \t" << address << "\nPhoneNumber: \t" << phoneNumber << "\nPassword: \t" << password << endl;
                break;
            }
        }
        if (firstName != fName && lastName != lName)
            cout << "\nERROR: Accout does not exist\n";
    }
}

void PrintAccountDetails(string fileName) {

    //Rye George

    fstream myFile;

    myFile.open(fileName, ios::in);

    if (myFile.is_open()) {

        string line;
        string firstName, lastName, email, address, phoneNumber, password;

        while (getline(myFile, line)) {

            stringstream ss(line);

            getline(ss, firstName, ',');
            getline(ss, lastName, ',');
            getline(ss, email, ',');
            getline(ss, address, ',');
            getline(ss, phoneNumber, ',');
            getline(ss, password, ',');

            cout << endl << firstName << " " << lastName << endl;
            cout << "Email: \t\t" << email << "\nAddress: \t" << address << "\nPhoneNumber: \t" << phoneNumber << "\nPassword: \t" << password << endl << endl;
        }
    }
}


void UpdateUserDetails(string fileName) {

    //Rye George

    fstream myFile;
    fstream tempFile;

    string line, email, pass, password;
    Customer customerInfo;

    bool nameCheck = false;

    cout << "To Update your accout details please confirm your name: \n";

    cout << "Enter your email: ";
    cin >> email;

    cout << "Enter your password: ";
    cin >> pass;
    cout << endl;


    tempFile.open("tempAccountDetails.csv", ios::out);

    myFile.open(fileName, ios::in);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            stringstream ss(line);

            getline(ss, customerInfo.firstName, ',');
            getline(ss, customerInfo.lastName, ',');
            getline(ss, customerInfo.emailAddress, ',');
            getline(ss, customerInfo.homeAddress, ',');
            getline(ss, customerInfo.phoneNumber, ',');
            getline(ss, password, ',');

            if (customerInfo.emailAddress != email && password != pass) { //If the line has the account registered with the same email and password

                //Copy accoutDetails into tempFile
                tempFile << customerInfo.firstName << "," << customerInfo.lastName << "," << customerInfo.emailAddress << "," << customerInfo.homeAddress << "," << customerInfo.phoneNumber << "," << password << "," << endl;
            }
            else if (customerInfo.emailAddress == email && password == pass) { //If the info the user enters matches with an existing account
                nameCheck = true;
            }
        }
    }


    if (nameCheck) {

        myFile.close();
        tempFile.close();

        myFile.open(fileName, ios::out);
        tempFile.open("tempAccountDetails.csv", ios::in);

        while (getline(tempFile, line)) { //Copies contents of tempFile into main file
            myFile << line << endl;
        }
        myFile.close();
        tempFile.close();

        cout << "Please enter your new account information: \n";

        cout << "Enter first name: ";
        cin >> customerInfo.firstName;

        cout << "Enter last name: ";
        cin >> customerInfo.lastName;

        cout << "Enter email: ";
        cin >> customerInfo.emailAddress;

        cout << "Enter address: ";
        cin >> customerInfo.homeAddress;

        cout << "Enter phone number: ";
        cin >> customerInfo.phoneNumber;

        char pw[20];

        //Check password
        int length = strlen(pw);
        while (1) {
            cout << "\nPlease enter a password which should contain :" << endl;
            cout << " * at least 8 characters" << endl;
            cout << " * at least one upper and lowercase letter " << endl;
            cout << " * at least one digit " << endl;
            cout << "Enter password: ";
            do {
                cin.getline(pw, 20);
                length = strlen(pw);
            } while (length < 8);
            if (CheckPassword(pw)) //if return 1 pass below
                continue;
            if (Re_enterPassword(pw))
                continue;

            break;
        }

        //Adding new account details into file
        myFile.open(fileName, ios::app);
        myFile << customerInfo.firstName << "," << customerInfo.lastName << "," << customerInfo.emailAddress << "," << customerInfo.homeAddress << "," << customerInfo.phoneNumber << "," << pw << "," << endl;
    }
    else {
        cout << "ERROR: account with that name does not exists\n";
    }
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
    case 'a': //NewTrip();
        break;

    case 'b': //Update user details
        break;

    case 'c': //Search trip history
        break;

    case 'd': //Report lost property
        break;

    case 'e': FileComplaint();
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
    case 'a': UpdateUserDetails("customerDetails.csv"); //Search all trip history
        break;

    case 'b': ManageDriversMenu();
        break;

    case 'c': ManageCustomersMenu();
        break;

    case 'd': //Search lost/found property
        break;

    case 'e': break;
        break;
    }
}

void ManageCustomersMenu() {

    //Rye George

    cout << "--------------------------" << endl;
    cout << "     Manage Customers     " << endl;
    cout << "--------------------------" << endl;

    cout << "Please choose one of the following options:\n";
    cout << "a) View customer details\n";
    cout << "b) Delete a customers account\n";
    cout << "e) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }

    switch (input) {
    case 'a': ViewCustomerDetails();
        break;

    case 'b': //RemoveCustomer();
        break;

    case 'c': break;
        break;
    }
}

void ManageDriversMenu() {

    //Rye George

    cout << "--------------------------" << endl;
    cout << "      Manage Drivers      " << endl;
    cout << "--------------------------" << endl;

    cout << "Please choose one of the following options:\n";
    cout << "a) View driver details\n";
    cout << "b) Delete a drivers account\n";
    cout << "e) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }

    switch (input) {
    case 'a': ViewDriverDetails();
        break;

    case 'b': //RemoveDriver();
        break;

    case 'c': break;
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

    //Write trip details to database
    int i;
    fstream myFile("tripDetails.csv", ios::app);
    for (i = 0; i < trip.size(); i++) {
        myFile << trip[i].customerName << "," << trip[i].tripDate << "," << trip[i].pickupTime << "," << trip[i].pickupLocation << "," << trip[i].destinationAddress << "," << trip[i].tripTime << "," << trip[i].passengers << "," << trip[i].price << endl;
    }
    myFile.close();

    return (trip);
}

/*
vector <LostProperty> ReportLostProperty(vector<LostProperty>& lProperty) { //Report lost property
    //Shaun Cooper

    cout << "--------------------------" << endl;
    cout << "   Report Lost Property   " << endl;
    cout << "--------------------------" << endl;

    LostProperty m;
    cout << "\nEnter the item type\n"; //Will force to choose an option for easier search function
    cout << "Please choose one of the following options:\n";
    cout << "a) Clothing\n";
    cout << "b) Wallet\n";
    cout << "c) Mobile Phone\n";
    cout << "d) Bag\n";
    cout << "e) Other accesory\n";
    cout << "f) Other\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }

    switch (input) { //Switch to describe the item type
    case 'a': m.itemType = "Clothing";
        break;

    case 'b': m.itemType = "Wallet";
        break;

    case 'c': m.itemType = "Mobile Phone";
        break;

    case 'd': m.itemType = "Bag";
        break;

    case 'e': m.itemType = "Other accessory";
        break;

    case 'f': m.itemType = "Other";
        break;
    }

    cout << "\nDescribe any identifying features: ";
    getline(cin, m.identifyingFeature);
    cout << "Enter the property value: $";
    cin >> m.value;

    property.push_back(m);

    //Write trip details to database
    int i;
    fstream myFile("lostProperty.csv", ios::app);
    for (i = 0; i < property.size(); i++) {
        myFile << property[i].itemType << "," << property[i].identifyingFeature << "," << property[i].value << endl;
    }
    myFile.close();

    return (property);
}
*/