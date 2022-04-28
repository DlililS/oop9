#include <iostream>
using namespace std;
class Property {
public:
    double worth;
    explicit Property(double worth) : worth(worth) {
    }

};
class Apartment : public Property {
public:
    explicit Apartment(double worth);
};

Apartment::Apartment(double worth) : Property(worth) {
    cout << worth / 1000 << endl;

}



class Car : public Property {
public:
    explicit Car(double worth);
};

Car::Car(double worth) : Property(worth) {
    cout << worth / 1200 << endl;
}
class CountryHouse : public Property {
public:
    explicit CountryHouse(double worth);
};

CountryHouse::CountryHouse(double worth) : Property(worth) {
    cout << worth / 1500 << endl;
}

int main() {
    Property* objects[9];
    for (int i = 1; i < 9; ++i)
    {
        if (i <= 3) objects[i] = new Apartment(i * 10000);;
        if ((i > 3) && (i < 6)) objects[i] = new Car(i * 10000);
        if ((i > 6) && (i < 9)) objects[i] = new CountryHouse(i * 10000);
    }   return 0;
}