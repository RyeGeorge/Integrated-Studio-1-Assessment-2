# Integrated-Studio-1-Assessment-2
Integrated Studio 1 Assessment 2 Project, Taxi booking system.

**Technical Style Guide**

Variable/Function naming style 

Camel case 
var example camelCase 
function example CamelCase 



 
Header Files 

iostream 
string 
fsteam 
sstrean 
vector 

 

Data structures 
Structure  

struct Customer 
  char[30] customerName; 
  Int customerPhoneNumber; 

struct Driver 
  char[30] driverName; 
  char[6] licensePlate; 
  string vehicleMake; 
  string vehicleModel; 

struct Trip 
  char[30] customerName; 
  char[30] customerPhoneNumber; 
  char[100] destination; 
  Int tripTime; //Minutes 
  pickupTime; 
  string tripDate; 
   float price; 
  char[100] pickupLocation; 
  int passengers; 
  bool tripCompleted; 


FILES 

customerDetails – stores customer details 
driverDetails – stores driver details 
tripDetails – stores trip details 
lostProperty – stores lost property 
foundProperty – stores found property 
