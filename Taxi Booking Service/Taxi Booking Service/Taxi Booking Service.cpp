#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//Data structures
struct Customer { 
  char customerName[30]; 
  int customerPhoneNumber;
}

struct Driver {
    char driverName[30];
    char licensePlate[6];
    string vehicleMake;
    string vehicleModel;
}

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
}



int main()
{
    std::cout << "Hello World!";
}

