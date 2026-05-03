#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string model;
    double speed;

public:
    Vehicle(string m, double s) : model(m), speed(s) {}
    virtual ~Vehicle() {}

    void setModel(string m) { model = m; }
    string getModel() const { return model; }

    void setSpeed(double s) { speed = s; }
    double getSpeed() const { return speed; }

    // Virtual function
    virtual void displayDetails() const {
        cout << "Vehicle Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
private:
    int doors;
public:
    Car(string m, double s, int d) : Vehicle(m, s), doors(d) {}

    void displayDetails() const override {
        cout << "Car Model: " << getModel() << ", Speed: " << getSpeed() << " km/h, Doors: " << doors << endl;
    }
};

class Bike : public Vehicle {
private:
    bool hasCarrier;
public:
    Bike(string m, double s, bool hc) : Vehicle(m, s), hasCarrier(hc) {}

    void displayDetails() const override {
        cout << "Bike Model: " << getModel() << ", Speed: " << getSpeed() << " km/h, Carrier: " << (hasCarrier ? "Yes" : "No") << endl;
    }
};

int main() {
    // Array of Vehicle pointers
    Vehicle* vehicles[3];

    vehicles[0] = new Car("Honda Civic", 120.0, 4);
    vehicles[1] = new Bike("Royal Enfield", 90.0, true);
    vehicles[2] = new Car("Tesla Model 3", 150.0, 4);

    cout << "--- Vehicle Details ---" << endl;
    // Polymorphism in action
    for (int i = 0; i < 3; i++) {
        vehicles[i]->displayDetails();
    }

    // Cleanup
    for (int i = 0; i < 3; i++) {
        delete vehicles[i];
    }

    return 0;
}
