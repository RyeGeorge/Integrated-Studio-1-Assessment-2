# Integrated-Studio-1-Assessment-2
Integrated Studio 1 Assessment 2 Project, Taxi booking system.

**Technical Style Guide**

**Variable/Function naming style **

Camel case 
var example camelCase 
function example CamelCase 



 
Header Files

iostream 
string 
fstream 
sstream 
vector 
stdlib.h

 
Data structures
Structure  

struct Customer 
    string firstName;
    string lastName;
    string emailAddress;
    string phoneNumber;
    string homeAddress;
    char password[20];

struct Driver 
    string firstName;
    string lastName;
    string emailAddress;
    string phoneNumber;
    string homeAddress;
    string licensePlate;
    string vehicleMake;
    string vehicleModel;
    char password[20]; 

struct Trip 
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


struct CarDetails
    firstName
    lastName
    licensePlate
    vehicalMake
    vehicalModel


FILES

customerDetails – stores customer details 
driverDetails – stores driver details
adminDetails – stores admin details 
tripDetails – stores trip details 
carDetails - stores car details
lostProperty – stores lost property 
foundProperty – stores found property
driverComplaints - stores complaints made against drivers
tempAccountDetails - temporarily holds account information for use in updating account information

