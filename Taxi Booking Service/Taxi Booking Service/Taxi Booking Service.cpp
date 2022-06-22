#include <iostream>
#include <string> //For using string variable types
#include <fstream> //To handle file operations
#include <sstream> //To handle string stream conversion
#include <vector> //To handle unlimited structure array
#include <stdlib.h>  //Allows us to use "System("CLS") to clear the console"

using namespace std;

//Data structures
struct User {
    string firstName;
    string lastName;
    string emailAddress;
    string phoneNumber;
    string homeAddress;
    char password[20];

    User() {  //Default Constructor
        firstName = "firstName";
        lastName = "lastName";
        emailAddress = "emailAddress";
        phoneNumber = "phoneNumber";
        homeAddress = "homeAddress";
    }
};


struct Trip {
    string emailAddress;
    string customerPhoneNumber;
    string destinationAddress;
    int tripTime; //Minutes
    string pickupTime;
    string tripDate;
    float price;
    string pickupLocation;
    int passengers;
    bool tripCompleted;
    int tripIdNumber;

    Trip() {
        emailAddress = "emailAddress";
        customerPhoneNumber = "customerPhoneNumber";
        destinationAddress = "destinationAddress";
        tripTime = 1;
        pickupTime = "pickupTime";
        tripDate = "tripDate";
        price = 1;
        pickupLocation = "pickupLocation";
        passengers = 1;
        tripCompleted = false;
        tripIdNumber = 0;
    }
};

struct CarDetails {
    string firstName;
    string lastName;
    string licensePlate;
    string vehicalMake;
    string vehicalModel;
};


struct Property {
    string email;
    string itemType;
    string itemDescription;
    string identifyingFeature;
};

void RegisterNewUser(string fileName);
void NewTrip();
void YourTripHistory();
void ReportProperty(string fileName, string type);
void DisplayProperty(string fileName, string type);

int CheckPassword(char passwd[]);
int Re_enterPassword(char  passwd[]);

void Login();
bool LoginLoop(string, string, string);
bool ReadFromLoginFile(string, string, string);
void CheckInput(char);
void CompanyHeader();
void RegisterCar(string, string);

void FileComplaint();
void DisplayComplaints();

void DisplayCarDetails();
void PrintCarDetails();
void SearchCarDetails();

void ViewCustomerDetails();
void UpdateAccountDetails(string);
void ViewDriverDetails();
void PrintAccountDetails(string);
void SearchAccountDetails(string);
void DeleteAccount(string, string, string);

void CustomerMenu();
void DriverMenu();
void AdminMenu();
void ManageCustomersMenu();
void ManageDriversMenu();

//Keeps track of current account the user is logged into
string currentPassword;
string currentEmail;

int main()
{

    CompanyHeader();
    cout << "                 Main Menu                    \n";
    cout << "------------------------------------------------\n\n";

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
    case 'a': Login(); //AdminMenu(); 
        break;

    case 'b': {
        cout << "What type of registration are you making?:" << endl;
        cout << "a) Customer\n";
        cout << "b) Driver\n";
        cout << "?: ";
        char choice;
        cin >> choice;
        while (choice != 'a' && choice != 'b') { //Validates if input is an acceptable value
            CheckInput(choice);
            cin >> choice;
            cout << endl;
        }
        string fileName; //switch to pass correct database file to RegisterNewUser function
        switch (choice) {
        case 'a': fileName = "customerDetails.csv";
            break;

        case 'b': fileName = "driverDetails.csv";
            break;
        }

        RegisterNewUser(fileName);

        Login();

        break;
    }

    case 'c': break;
        break;
    }
}

void Login() {

    //Rye George

    system("CLS");
    CompanyHeader();
    cout << "                 Login Menu                    \n";
    cout << "------------------------------------------------\n\n";

    
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
    case 'a': if (LoginLoop("customerDetails.csv", tempPassword, tempEmail)) { CustomerMenu(); }
            break;

    case 'b': if (LoginLoop("driverDetails.csv", tempPassword, tempEmail)) { DriverMenu(); }//pass then email
            break;

    case 'c': if (LoginLoop("adminDetails.csv", tempPassword, tempEmail)) { AdminMenu(); }//Pass then email
            break;
    }

}

bool LoginLoop(string file, string password, string email) {
    for (int i = 3; i > 0; i--) {

        cout << "Enter your Email: ";
        cin >> email;

        cout << "\nEnter your password: ";
        cin >> password;

        if (ReadFromLoginFile(file, password, email)) {
            currentPassword = password;
            currentEmail = email;
            return true;
        }

        cout << "\nPassword or Email are incorrect, you have " << i - 1 << " attemps left\n\n\n";
    }
    return false;
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

};


void RegisterNewUser(string fileName) {
    // Shaun Cooper

    cout << "             Register New User" << endl;
    cout << "------------------------------------------------" << endl;
    cin.clear();
    cin.ignore(1000, '\n');

    User m;//we receive one user data at any given time

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

    RegisterCar(m.firstName, m.lastName);

    cin.clear();
    cin.ignore(1000, '\n');

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
        if (CheckPassword(m.password)) //if return 1/true pass below
            continue;
        if (Re_enterPassword(m.password))
            continue;

        break;
    }

    //Write details to database
    fstream myFile(fileName, ios::app);
    myFile << m.firstName << "," << m.lastName << "," << m.homeAddress << "," << m.emailAddress << "," << m.phoneNumber << "," << m.password << endl;
    
    myFile.close();

    cout << "\nYou have successfully registered.\n\n";

    return;
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


void RegisterCar(string firstName, string lastName) {

    //Rye George

    CarDetails carDetails;
    fstream myFile;

    carDetails.firstName = firstName;
    carDetails.lastName = lastName;

    cout << "Please enter your vehicals license plate: ";
    cin >> carDetails.licensePlate;

    cout << "Please enter your vehicals make: ";
    cin >> carDetails.vehicalMake;

    cout << "Please enter your vehicals model: ";
    cin >> carDetails.vehicalModel;

    myFile.open("carDetails.csv", ios::app);
    if (myFile.is_open()) {
        myFile << firstName << "," << lastName << "," << carDetails.licensePlate << "," << carDetails.vehicalMake << "," << carDetails.vehicalModel << "," << endl;
    }
    myFile.close();
}

void DisplayCarDetails() {

    //Rye George
    CompanyHeader();
    cout << "                 Car Details                    \n";
    cout << "------------------------------------------------\n\n";

    cout << "\nTo view car details, please choose one of the following options:\n";

    cout << "a) Search car details\n";
    cout << "b) View all car details\n";
    cout << "c) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }


    switch (input) {
    case 'a': SearchCarDetails();
        break;
    case 'b': PrintCarDetails();
        break;
    case 'c': break;
        break;
    }
}

void PrintCarDetails() {

    fstream myFile;
    CarDetails carDetails;
    string line;

    myFile.open("carDetails.csv", ios::in);

    while (getline(myFile, line))
    {
        stringstream ss(line);

        getline(ss, carDetails.firstName, ',');
        getline(ss, carDetails.lastName, ',');
        getline(ss, carDetails.licensePlate, ',');
        getline(ss, carDetails.vehicalMake, ',');
        getline(ss, carDetails.vehicalModel, ',');

        cout << "\nFirst Name: \t" << carDetails.firstName << "\nLast Name: \t" << carDetails.lastName << "\nLicense Plate: \t" << carDetails.licensePlate << "\nVehical Make: \t" << carDetails.vehicalMake << "\nVehical Model: \t" << carDetails.vehicalModel << "\n";
    }
    myFile.close();
}

void SearchCarDetails() {

    //Rye George

    CarDetails carDetails;
    fstream myFile;
    string line, fName, lName;

    cout << "To search a cars details, please enter the name of the driver: \n";

    cout << "Please enter the drivers first name: ";
    cin >> fName;

    cout << "Please enter the drivers last name: ";
    cin >> lName;

    myFile.open("carDetails.csv", ios::in);

    while (getline(myFile, line))
    {
        stringstream ss(line);

        getline(ss, carDetails.firstName, ',');
        getline(ss, carDetails.lastName, ',');
        getline(ss, carDetails.licensePlate, ',');
        getline(ss, carDetails.vehicalMake, ',');
        getline(ss, carDetails.vehicalModel, ',');

        if (fName == carDetails.firstName && lName == carDetails.lastName) {
            cout << "\nFirst Name: \t" << carDetails.firstName << "\nLast Name: \t" << carDetails.lastName << "\nLicense Plate: \t" << carDetails.licensePlate << "\nVehical Make: \t" << carDetails.vehicalMake << "\nVehical Model: \t" << carDetails.vehicalModel << "\n";
        }
    }
    myFile.close();
}

bool ReadFromLoginFile(string fileName, string pw, string e) {

    //Rye George

    fstream myFile;

    myFile.open(fileName, ios::in);

    if (myFile.is_open()) {

        string line, password;
        User userDetails;

        while (getline(myFile, line))
        {
            stringstream ss(line);
            getline(ss, userDetails.firstName, ',');
            getline(ss, userDetails.lastName, ',');
            getline(ss, userDetails.homeAddress, ',');
            getline(ss, userDetails.emailAddress, ',');
            getline(ss, userDetails.phoneNumber, ',');
            getline(ss, password, ',');

            if ((password == pw) && (userDetails.emailAddress == e))
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

    CompanyHeader();
    cout << "               File Complaint                 \n";
    cout << "------------------------------------------------\n\n";

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

    CompanyHeader();
    cout << "               View Complaints                \n";
    cout << "------------------------------------------------\n\n";

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

    CompanyHeader();
    cout << "              Customer Details                \n";
    cout << "------------------------------------------------\n\n";

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

    CompanyHeader();
    cout << "               Driver Details                \n";
    cout << "------------------------------------------------\n\n";

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
    case 'a': SearchAccountDetails("driverDetails.csv");
        break;
    case 'b': PrintAccountDetails("driverDetails.csv");
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
        string password;
        User userDetails;

        while (getline(myFile, line)) {

            stringstream ss(line);

            getline(ss, userDetails.firstName, ',');
            getline(ss, userDetails.lastName, ',');
            getline(ss, userDetails.homeAddress, ',');
            getline(ss, userDetails.emailAddress, ',');
            getline(ss, userDetails.phoneNumber, ',');
            getline(ss, password, ',');

            if (userDetails.firstName == fName && userDetails.lastName == lName) {
                cout << endl << userDetails.firstName << " " << userDetails.lastName << endl;
                cout << "Email: \t\t" << userDetails.homeAddress << "\nAddress: \t" << userDetails.emailAddress << "\nPhoneNumber: \t" << userDetails.phoneNumber << "\nPassword: \t" << password << endl;
                break;
            }
        }
        if (userDetails.firstName != fName && userDetails.lastName != lName)
            cout << "\nERROR: Accout does not exist\n";
    }
}

void PrintAccountDetails(string fileName) {

    //Rye George

    fstream myFile;

    myFile.open(fileName, ios::in);

    if (myFile.is_open()) {

        string line;
        string password;
        User userDetails;

        while (getline(myFile, line)) {

            stringstream ss(line);

            getline(ss, userDetails.firstName, ',');
            getline(ss, userDetails.lastName, ',');
            getline(ss, userDetails.homeAddress, ',');
            getline(ss, userDetails.emailAddress, ',');
            getline(ss, userDetails.phoneNumber, ',');
            getline(ss, password, ',');

            cout << endl << userDetails.firstName << " " << userDetails.lastName << endl;
            cout << "Address: \t" << userDetails.homeAddress << endl;
            cout << "Email: \t\t" << userDetails.emailAddress << endl;
            cout << "PhoneNumber: \t" << userDetails.phoneNumber << endl;
            cout << "Password: \\t" << password << endl << endl;
        }
    }
}

void DeleteAccount(string fileName, string currentPass, string currentEmail) {

    //Rye George

    fstream myFile;
    fstream tempFile;

    string line, password;
    string tempEmail, tempPass;
    User userDetails;

    bool detailCheck = false;

        cout << "Please confirm your email and password: \n\n";
        cout << "Please enter your email: ";
        cin >> tempEmail;
        cout << "Please enter your password: ";
        cin >> tempPass;

    tempFile.open("temp.csv", ios::out);

    myFile.open(fileName, ios::in);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            stringstream ss(line);

            getline(ss, userDetails.firstName, ',');
            getline(ss, userDetails.lastName, ',');
            getline(ss, userDetails.homeAddress, ',');
            getline(ss, userDetails.emailAddress, ',');
            getline(ss, userDetails.phoneNumber, ',');
            getline(ss, password, ',');

            if (userDetails.emailAddress != currentEmail && password != currentPass) { //If the line has the account registered with the same email and password

                //Copy accoutDetails into tempFile
                tempFile << userDetails.firstName << "," << userDetails.lastName << "," << userDetails.emailAddress << "," << userDetails.homeAddress << "," << userDetails.phoneNumber << "," << password << "," << endl;
            }
            else if (userDetails.emailAddress == currentEmail && password == currentPass) { //If the info the user enters matches with an existing account
                detailCheck = true;
            }
        }
    }

    if (detailCheck) {

        myFile.close();
        tempFile.close();

        myFile.open(fileName, ios::out);
        tempFile.open("temp.csv", ios::in);

        while (getline(tempFile, line)) { //Copies contents of tempFile into main file
            myFile << line << endl;
        }
        myFile.close();
        tempFile.close();
    }
    else {
        cout << "ERROR: Account does not exist\n";
    }

}

void UpdateAccountDetails(string fileName) {

    //Rye George

    CompanyHeader();
    cout << "               Update Account                \n";
    cout << "------------------------------------------------\n\n";

    User userDetails;
    fstream myFile;

    DeleteAccount(fileName, currentPassword, currentEmail);

    cout << "Please enter your new account information: \n";

    cout << "Enter first name: ";
    cin >> userDetails.firstName;

    cout << "Enter last name: ";
    cin >> userDetails.lastName;

    cout << "Enter email: ";
    cin >> userDetails.homeAddress;

    cout << "Enter address: ";
    cin >> userDetails.emailAddress;

    cout << "Enter phone number: ";
    cin >> userDetails.phoneNumber;

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
    cout << "TEST\n";
    myFile.open(fileName, ios::app);
    myFile << userDetails.firstName << "," << userDetails.lastName << "," << userDetails.homeAddress << "," << userDetails.emailAddress << "," << userDetails.phoneNumber << "," << pw << "," << endl;

}


void FindNewTrip() {

    //Rye George

    fstream myFile, tempFile;
    string line;
    Trip tripDetails;
    string tripTime, price, passengers, ID, tripCompleted;
    string oEmailAddress, oTripDate, oPickupTime, oPickupLocation, oDestinationLocation, oTripTime, oPassengers, oPrice, oID, temp;
    int maxID = 0;

    myFile.open("tripDetails.csv", ios::in);
    while (getline(myFile, line)) {
        stringstream ss(line);

        getline(ss, tripDetails.emailAddress, ',');
        getline(ss, tripDetails.tripDate, ',');
        getline(ss, tripDetails.pickupTime, ',');
        getline(ss, tripDetails.pickupLocation, ',');
        getline(ss, tripDetails.destinationAddress, ',');
        getline(ss, tripTime, ',');
        getline(ss, passengers, ',');
        getline(ss, price, ',');
        getline(ss, ID, ',');
        getline(ss, tripCompleted, ',');

        if (tripCompleted == "0") {
            cout << endl;
            cout << "ID " << ID << ":\t\t\t";
            cout << tripDetails.tripDate << endl;
            
            cout << "Customer Email: \t" << tripDetails.emailAddress << endl;
            cout << "Pickup Location: \t" << tripDetails.pickupLocation << endl;
            cout << "Pickup time: \t\t" << tripDetails.pickupTime << endl;
            cout << "Destination Address: \t" << tripDetails.destinationAddress << endl;
            cout << "Number Of Passengers: \t" << passengers << endl;
            cout << "Price: \t\t\t" << "$" << price << endl;
        }
    }
    myFile.close();

    int enteredID;
    cout << "\nAbove is a list of all avaliable trips (if blank there are no trips avaliable)";
    cout << "\nPlease enter the ID number of the trip you want to take (enter 0 to exit): ";
    cin >> enteredID;

    myFile.open("tripDetails.csv", ios::in);
    tempFile.open("temp.csv", ios::out);

    if (enteredID > 0) {
        while (getline(myFile, line)) {
            stringstream ss(line);
            getline(ss, tripDetails.emailAddress, ',');
            getline(ss, tripDetails.tripDate, ',');
            getline(ss, tripDetails.pickupTime, ',');
            getline(ss, tripDetails.pickupLocation, ',');
            getline(ss, tripDetails.destinationAddress, ',');
            getline(ss, tripTime, ',');
            getline(ss, passengers, ',');
            getline(ss, price, ',');
            getline(ss, ID, ',');
            getline(ss, tripCompleted, ',');

            //Copy all lines to tempFile except for the one that the driver selected
            int id = stoi(ID);
            if (id != enteredID) {
                tempFile << tripDetails.emailAddress << ',' 
                         << tripDetails.tripDate << ',' 
                         << tripDetails.pickupTime << ',' 
                         << tripDetails.pickupLocation << "," 
                         << tripDetails.destinationAddress << ',' 
                         << tripTime << ','
                         << passengers << ',' 
                         << price << ','
                         << ID << "," 
                         << tripCompleted << ',' << endl;

                
            }
            
            if (id == enteredID) {

                oEmailAddress = tripDetails.emailAddress;
                oTripDate = tripDetails.tripDate;
                oPickupTime = tripDetails.pickupTime;
                oPickupLocation = tripDetails.pickupLocation;
                oDestinationLocation = tripDetails.destinationAddress;
                oTripTime = tripTime;
                oPassengers = passengers;
                oPrice = price;

            }
        }
        myFile.close();
        tempFile.close();

        //Copy from tempFile back to myFile
        tempFile.open("temp.csv", ios::in);
        myFile.open("tripDetails.csv", ios::out);

        while (getline(tempFile, line)) {
            myFile << line << endl;
        }
        myFile.close();

        myFile.open("tripDetails.csv", ios::app);

        myFile << oEmailAddress << ','
            << oTripDate << ','
            << oPickupTime << ','
            << oPickupLocation << ","
            << oDestinationLocation << ','
            << oTripTime << ','
            << oPassengers << ','
            << oPrice << ','
            << enteredID << ","
            << '1' << ',' << endl;

        myFile.close();
    }
}


//
//Menu functions
//


void CustomerMenu() {

    // Rye George

    system("CLS");  //Clears console

    CompanyHeader();
    cout << "                Customer Menu                \n";
    cout << "------------------------------------------------\n\n";

    cout << "Please choose one of the following options:\n";
    cout << "a) Enter new trip\n";
    cout << "b) Update account details\n";
    cout << "c) Search trip history\n";
    cout << "d) Report lost property\n";
    cout << "e) File complaint\n";
    cout << "f) Delete Account\n";
    cout << "g) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f' && input != 'g') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }

    switch (input) {
    case 'a': NewTrip();

        break;

    case 'b': UpdateAccountDetails("customerDetails.csv");
        break;

    case 'c': YourTripHistory();
        break;
         
    case 'd': ReportProperty("lostProperty.csv", "Lost");
        break;

    case 'e': FileComplaint();
        break;

    case 'f': 
        CompanyHeader();
        cout << "               Delete Account                \n";
        cout << "------------------------------------------------\n\n";
        DeleteAccount("customerDetails.csv", currentPassword, currentEmail);

    case 'g': break;
        break;
    }
}

void DriverMenu() {

    // Rye George

    system("CLS");  //Clears console

    CompanyHeader();
    cout << "                 Driver Menu                \n";
    cout << "------------------------------------------------\n\n";
    
    cout << "Please choose one of the following options:\n";
    cout << "a) Find new trip\n";
    cout << "b) Search trip history\n";
    cout << "c) Report found property\n";
    cout << "d) Update account details\n";
    cout << "e) Delete Account\n";
    cout << "f) Exit\n";

    char input;
    cin >> input;

    while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f') { //Validates if input is an acceptable value
        CheckInput(input);
        cin >> input;
        cout << endl;
    }

    switch (input) {
    case 'a': FindNewTrip();
        break;

    case 'b': YourTripHistory();
        break;

    case 'c': ReportProperty("foundProperty.csv", "Found");
        break;

    case 'd': UpdateAccountDetails("driverDetails.csv");
        break;

    case 'e': 
        CompanyHeader();
        cout << "               Delete Account                \n";
        cout << "------------------------------------------------\n\n";
        DeleteAccount("driverDetails.csv", currentPassword, currentEmail);

    case 'f': break;
        break;
    }
}

void AdminMenu() {

    // Rye George

    system("CLS");  //Clears console

    CompanyHeader();
    cout << "                 Admin Menu                 \n";
    cout << "------------------------------------------------\n\n";

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
    case 'a': YourTripHistory();
        break;

    case 'b': ManageDriversMenu();
        break;

    case 'c': ManageCustomersMenu();
        break;

    case 'd': 
        DisplayProperty("lostProperty.csv", "Lost");
        DisplayProperty("foundProperty.csv", "Found");
        break;

    case 'e': break;
        break;
    }
}

void ManageCustomersMenu() {

    //Rye George

    CompanyHeader();
    cout << "              Manage Customers                 \n";
    cout << "------------------------------------------------\n\n";

    cout << "Please choose one of the following options:\n";
    cout << "a) View customer details\n";
    cout << "b) View customer complaints\n";
    cout << "c) Exit\n";

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

    case 'b': DisplayComplaints();
        break;

    case 'c': break;
        break;
    }
}

void ManageDriversMenu() {

    //Rye George

    CompanyHeader();
    cout << "               Manage Drivers                 \n";
    cout << "------------------------------------------------\n\n";

    cout << "Please choose one of the following options:\n";
    cout << "a) View driver details\n";
    cout << "b) View car details\n";
    cout << "c) Exit\n";

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

    case 'b': DisplayCarDetails();
        break;

    case 'c': break;
        break;
    }
}

void NewTrip() { //Enter a new trip
    //Shaun Cooper

    cin.clear();
    cin.ignore(1000, '\n');

    cout << "              New Trip Details     " << endl;
    cout << "------------------------------------------------" << endl;

    Trip m;//we receive one user data at any given time
    m.emailAddress = currentEmail; //email is updated by the logged in user
    /*cin.clear();
    cin.ignore(1000, '\n');*/
    cout << "\nEnter the destination address: ";
    getline(cin, m.destinationAddress);
    cout << "Enter your pickup address: ";
    getline(cin, m.pickupLocation);
    cout << "Enter the date for the trip (dd/mm/yyyy): ";
    getline(cin, m.tripDate);
    cout << "Enter the time you would like to be picked up: ";
    getline(cin, m.pickupTime);
    cout << "How many passengers will there be?: ";
    cin >> m.passengers;
    cout << "How long will the trip take? (mins): ";
    cin >> m.tripTime;
    m.price = (m.tripTime * 1.5) * (m.passengers * 1.15 + 1); // $1.50 per min + 15% for 1 passenger, then adding 15% for each successive passenger.
    cout << "\nThe price of your trip is: $" << m.price << endl;
    cout << endl;

    char answer;
    cout << "Enter 'y' to accept or 'n' to cancel: ";
    cin >> answer;
    
    //Obtain trip ID number by counting amount of lines in database
    fstream myFile("tripDetails.csv", ios::in);
    string line;
    int count = 0;
    while (getline(myFile, line)) {
        istringstream linestream(line);//to split the row into coloumns/properties
        count++;
    }
    myFile.close();
    m.tripIdNumber = count + 1; //Next number in list

    //Write trip details to database
    if (tolower(answer) == 'y') {
        fstream myFile("tripDetails.csv", ios::app);
        myFile << m.emailAddress << "," << m.tripDate << "," << m.pickupTime << "," << m.pickupLocation << "," << m.destinationAddress << "," << m.tripTime << "," << m.passengers << "," << m.price << "," << m.tripIdNumber << "," << m.tripCompleted << endl;
        myFile.close();

        cout << "\nYour trip has been ordered.\n\n";
    }
    else
        cout << "\nTrip cancelled...\n\n";

    return;
}

void ReportProperty(string fileName, string type) { //Report lost or found property
    //Shaun Cooper

    cout << "            Report " << type << " Property  " << endl;
    cout << "------------------------------------------------" << endl;

    Property m;
    m.email = currentEmail; //email is updated by the logged in user
    char loop = 'y';
    while (loop == 'y') {
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

        cin.ignore(1000, '\n');
        cout << "\nDescribe the item: ";
        getline(cin, m.itemDescription);
        cout << "\nDescribe any identifying features: ";
        getline(cin, m.identifyingFeature);

        //Write trip details to database
        fstream myFile(fileName, ios::app);
        myFile << m.email << "," << m.itemType << "," << m.itemDescription << "," << m.identifyingFeature << endl;
        myFile.close();

        cout << "\nYour report has been submitted." << endl;
        if (fileName == "lostProperty.csv") { cout << "We will contact you on " << currentEmail << " when the property is found." << endl; }

        cout << "\nWould you like to enter another " << type << " Property Report ? (y / n) : ";
        cin >> loop;
        cout << endl;
    }
    return;
}

void DisplayProperty(string fileName, string type) { //Display all lost or found property
    //Shaun Cooper

    cout << "            Display " << type << " Property  " << endl;
    cout << "------------------------------------------------" << endl;

    cout << "\nBelow is a list of all the " << type << " property on file : \n\n";
    //open file to search not append
    fstream myFile(fileName, ios::in);
    vector<Property>tempProperty;

    Property m;

    string line;
    while (getline(myFile, line)) {
        cout << " - " << line << endl;
        istringstream linestream(line);//to split the row into coloumns/properties
        string item;
        //until the appearance of comma, everything is stored in item
        getline(linestream, item, ',');
        m.itemType = item;
        getline(linestream, item, ',');
        m.itemDescription = item;
        getline(linestream, item, ',');
        m.identifyingFeature = item;
    }
    myFile.close();
    cout << endl;

    char answer = 'y';
    while (tolower(answer) == 'y') {
        cout << "When you have finished reviewing the items, press any key then enter to exit.";
        cin >> answer;
    }

    cout << endl;
    return;
}

void YourTripHistory() {
    //Shaun Cooper

    cout << "             Your Trip History    " << endl;
    cout << "------------------------------------------------" << endl;

    fstream myFile;

    string line, password;
    User customerInfo;

    cout << "\nYou are logged in as: " << currentEmail << endl;
    if (currentEmail == "admin@taxiapp.com") { cout << "Due to being an admin user, the console will display all of the trip information...\n" << endl; }
    else cout << "Below is a summary of your trip history:\n" << endl;

    myFile.open("tripDetails.csv", ios::in);
    int i = 0;
    vector<Trip> trips;
    Trip m;
    int tripTime, passengers; //create local variables to convert from string
    float price; //create local variables to convert from string

    while (getline(myFile, line)) {
        istringstream linestream(line);//to split the row into coloumns/properties
        string item;
        //until the appearance of comma, everything is stored in item
        getline(linestream, item, ','); //the variable 'item' is of string type
        m.emailAddress = item;
        getline(linestream, item, ',');
        m.tripDate = item;
        getline(linestream, item, ',');
        m.pickupTime = item;
        getline(linestream, item, ',');
        m.pickupLocation = item;
        getline(linestream, item, ',');
        m.destinationAddress = item;
        getline(linestream, item, ',');
        tripTime = stoi(item); //use stoi() to convert string into integer
        m.tripTime = tripTime;
        getline(linestream, item, ',');
        passengers = stoi(item);
        m.passengers = passengers;
        getline(linestream, item, ',');
        price = stof(item); //use stof() to convert string into float
        m.price = price;

        trips.push_back(m); //keeps adding to the Trip vector
    }
   
    for (i = 0;i < trips.size();i++) {
        if (trips[i].emailAddress == currentEmail) {
            cout << "- Date: " << trips[i].tripDate << "Pickup Address: " << trips[i].pickupLocation << ", Destination Address: " << trips[i].destinationAddress << ", Price: $" << trips[i].price << endl;
        }
        if (currentEmail == "admin@taxiapp.com") {
            cout << trips[i].emailAddress << "," << trips[i].tripDate << "," << trips[i].pickupTime << "," << trips[i].pickupLocation << "," << trips[i].destinationAddress << "," << trips[i].tripTime << "," << trips[i].passengers << "," << trips[i].price << endl << endl;
        }
    }
    cout << endl;    
    return;
}

//int GetTripId() {
//    Trip m;
//    m.tripIdNumber = tripIdNumber;
//    tripIdNumber++;
//    return;
//}