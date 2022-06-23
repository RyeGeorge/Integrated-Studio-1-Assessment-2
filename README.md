# Integrated-Studio-1-Assessment-2
Integrated Studio 1 Assessment 2 Project, Taxi booking system.

**Technical Style Guide**
**Variable/Function naming style **
Camel case 
var example camelCase 
function example CamelCase


**Login Details for Admin user**
Email: admin@taxiapp.com
Password: admin

 
Header Files

#include <iostream>
#include <string> //For using string variable types
#include <fstream> //To handle file operations
#include <sstream> //To handle string stream conversion
#include <vector> //To handle unlimited structure array
#include <stdlib.h>  //Allows us to use "System("CLS") to clear the console"
#include <iomanip> //To handle rounding numbers
#include <cmath> //To handle rounding numbers

 
Data structures

struct User {
    string firstName;
    string lastName;
    string emailAddress;
    string phoneNumber;
    string homeAddress;
    char password[20];

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

struct CarDetails {
    string firstName;
    string lastName;
    string licensePlate;
    string vehicalMake;
    string vehicalModel;
 
 struct Property {
    string email;
    string itemType;
    string itemDescription;
    string identifyingFeature;


FILES

customerDetails – stores customer details 
driverDetails – stores driver details
adminDetails – stores admin details 
tripDetails – stores trip details 
carDetails - stores car details
lostProperty – stores lost property 
foundProperty – stores found property
driverComplaints - stores complaints made against drivers
temp - file to temporary storage

