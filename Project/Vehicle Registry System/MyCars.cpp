#include <iostream>
#include <string>
using namespace std;

// ==========================================
// 1. Base Class: Vehicle
// ==========================================
class Vehicle {
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    // Static Member
    static int totalVehicles;

    // Constructors
    Vehicle() {
        vehicleID = 0;
        manufacturer = "Unknown";
        model = "Unknown";
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, string mfg, string mdl, int yr) {
        vehicleID = id;
        manufacturer = mfg;
        model = mdl;
        year = yr;
        totalVehicles++;
    }

    // Destructor
    virtual ~Vehicle() {
        totalVehicles--;
    }

    // Getters and Setters (Encapsulation)
    void setVehicleID(int id) { vehicleID = id; }
    int getVehicleID() { return vehicleID; }

    void setManufacturer(string mfg) { manufacturer = mfg; }
    string getManufacturer() { return manufacturer; }

    void setModel(string mdl) { model = mdl; }
    string getModel() { return model; }

    void setYear(int yr) { year = yr; }
    int getYear() { return year; }

    // Virtual Display Function
    virtual void display() {
        cout << "ID: " << vehicleID << " | Mfg: " << manufacturer << " | Model: " << model << " | Year: " << year;
    }
};

// Initialize Static Member
int Vehicle::totalVehicles = 0;


// ==========================================
// 2. Derived Classes
// ==========================================

// Car (Single Inheritance from Vehicle)
class Car : public Vehicle {
protected:
    string fuelType; // Additional attribute

public:
    Car(int id, string mfg, string mdl, int yr, string fuel) : Vehicle(id, mfg, mdl, yr) {
        fuelType = fuel;
    }

    void display() {
        Vehicle::display();
        cout << " | Fuel: " << fuelType;
    }
};

// ElectricCar (Multilevel Inheritance from Car)
class ElectricCar : public Car {
protected:
    string batteryCapacity; // Additional attribute

public:
    ElectricCar(int id, string mfg, string mdl, int yr, string batt) : Car(id, mfg, mdl, yr, "Electric") {
        batteryCapacity = batt;
    }

    void display() {
        Vehicle::display();
        cout << " | Battery: " << batteryCapacity;
    }
};

// Aircraft (Base Class for Multiple Inheritance)
class Aircraft {
protected:
    string flightRange; // Additional attribute

public:
    Aircraft(string range) {
        flightRange = range;
    }

    virtual ~Aircraft() {}
};

// FlyingCar (Multiple Inheritance from Car and Aircraft)
class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id, string mfg, string mdl, int yr, string fuel, string range) : Car(id, mfg, mdl, yr, fuel), Aircraft(range) {}
    
    void display() {
        Car::display();
        cout << " | Flight Range: " << flightRange;
    }
};

// SportsCar (Multilevel Inheritance from ElectricCar)
class SportsCar : public ElectricCar {
protected:
    string topSpeed; // Additional attribute

public:
    SportsCar(int id, string mfg, string mdl, int yr, string batt, string speed) : ElectricCar(id, mfg, mdl, yr, batt) {
        topSpeed = speed;
    }

    void display() {
        ElectricCar::display();
        cout << " | Top Speed: " << topSpeed;
    }
};

// Sedan (Hierarchical Inheritance from Car)
class Sedan : public Car {
public:
    Sedan(int id, string mfg, string mdl, int yr, string fuel) : Car(id, mfg, mdl, yr, fuel) {}
    
    void display() {
        Car::display();
        cout << " (Sedan)";
    }
};

// SUV (Hierarchical Inheritance from Car)
class SUV : public Car {
public:
    SUV(int id, string mfg, string mdl, int yr, string fuel) : Car(id, mfg, mdl, yr, fuel) {}
    
    void display() {
        Car::display();
        cout << " (SUV)";
    }
};


// ==========================================
// 3. VehicleRegistry Class
// ==========================================
class VehicleRegistry {
private:
    Vehicle* array[100]; // Manages an array of Vehicle objects
    int count;

public:
    VehicleRegistry() {
        count = 0;
    }

    // Methods for adding
    void addVehicle(Vehicle* v) {
        if (count < 100) {
            array[count] = v;
            count++;
            cout << "=> Vehicle Added Successfully!\n";
        } else {
            cout << "=> Registry is Full!\n";
        }
    }

    // Methods for displaying
    void displayAll() {
        if (count == 0) {
            cout << "=> No Vehicles to View.\n";
            return;
        }
        cout << "\n--- All Vehicles ---\n";
        for (int i = 0; i < count; i++) {
            array[i]->display();
            cout << endl;
        }
        cout << "Total Vehicles in System: " << Vehicle::totalVehicles << "\n";
    }

    // Methods for searching
    void searchByID(int id) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (array[i]->getVehicleID() == id) {
                cout << "=> Vehicle Found:\n";
                array[i]->display();
                cout << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "=> Vehicle ID Not Found!\n";
        }
    }
};


// ==========================================
// 4. Main Function
// ==========================================
int main() {
    VehicleRegistry registry;
    int choice;

    while (true) {
        // Menu-driven approach
        cout << "\n========== MENU ==========\n";
        cout << "1. Add a vehicle\n";
        cout << "2. View all vehicles\n";
        cout << "3. Search by Id\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "\nSelect Vehicle Type:\n";
            cout << "1. Car\n";
            cout << "2. Electric Car\n";
            cout << "3. Flying Car\n";
            cout << "4. Sports Car\n";
            cout << "5. Sedan \n";
            cout << "6. SUV\n";
            cout << "Choice: ";
            cin >> type;

            int id, year;
            string mfg, mdl, fuel;
            
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Manufacturer: "; cin >> mfg;
            cout << "Enter Model: "; cin >> mdl;
            cout << "Enter Year: "; cin >> year;
            
            if (type != 2 && type != 4) {
                cout << "Enter Fuel Type: "; cin >> fuel;
            }

            if (type == 1) {
                registry.addVehicle(new Car(id, mfg, mdl, year, fuel));
            } 
            else if (type == 2) {
                string batt;
                cout << "Enter Battery Capacity (e.g. 5h, 100kwh): "; cin >> batt;
                registry.addVehicle(new ElectricCar(id, mfg, mdl, year, batt));
            } 
            else if (type == 3) {
                string range;
                cout << "Enter Flight Range (e.g. 500miles): "; cin >> range;
                registry.addVehicle(new FlyingCar(id, mfg, mdl, year, fuel, range));
            } 
            else if (type == 4) {
                string batt, speed;
                cout << "Enter Battery Capacity (e.g. 5h, 100kwh): "; cin >> batt;
                cout << "Enter Top Speed (e.g. 1s, 200km/h): "; cin >> speed;
                registry.addVehicle(new SportsCar(id, mfg, mdl, year, batt, speed));
            } 
            else if (type == 5) {
                registry.addVehicle(new Sedan(id, mfg, mdl, year, fuel));
            } 
            else if (type == 6) {
                registry.addVehicle(new SUV(id, mfg, mdl, year, fuel));
            } 
            else {
                cout << "Invalid Type!\n";
            }
        } 
        else if (choice == 2) {
            registry.displayAll();
        } 
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: "; cin >> id;
            registry.searchByID(id);
        } 
        else if (choice == 4) {
            cout << "Exiting system. Goodbye!\n";
            break;
        } 
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
