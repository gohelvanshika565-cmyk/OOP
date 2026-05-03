#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    private:
        string model;
        double speed;

    public:
        Vehicle(string m, double s) : model(m), speed(s) {}

        // Getters and Setters
        void setModel(string m) { model = m; }
        string getModel() const { return model; }

        void setSpeed(double s) { speed = s; }
        double getSpeed() const { return speed; }
};

class Car : public Vehicle{
    public:
        Car(string m, double s) : Vehicle(m, s) {}

        double calculateTime(double distance)
        {
            if (getSpeed() > 0)
                return distance / getSpeed();
            return 0;
        }
};

    class Bike : public Vehicle{
    public:
        Bike(string m, double s) : Vehicle(m, s) {}

        double calculateTime(double distance)
        {
            if (getSpeed() > 0)
                return distance / getSpeed();
            return 0;
        }
};

int main(){
    Car myCar("Toyota Camry", 100.0);
    Bike myBike("Yamaha MT-07", 80.0);

    double distance = 200.0;

    cout << "Time taken by Car (" << myCar.getModel() << ") for " << distance << " km: " << myCar.calculateTime(distance) << " hours" << endl;

    cout << "Time taken by Bike (" << myBike.getModel() << ") for " << distance << " km: " << myBike.calculateTime(distance) << " hours" << endl;

    return 0;
}
