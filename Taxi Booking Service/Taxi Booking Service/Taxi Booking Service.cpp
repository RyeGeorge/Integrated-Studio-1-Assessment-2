#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//Data structures
struct Customer { 
  string customerName; 
  int customerPhoneNumber;

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


int main()
{
    vector<Customer> customer;
    vector<Customer> customerFromFile;
    vector <Customer> registerNewUser(vector<Customer> &customer)
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