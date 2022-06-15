Nalog.h
#pragma once
#ifndef NALOG_H
#define NALOG_H
#include <iostream>
class Property {
protected:
	double worth;
public:
	Property();
	Property(double n);
	virtual void nal() = 0;
};

class Apartment : public Property {
public:
	Apartment() : Property() {};
	Apartment(double n);
	void nal();
};

class Car : public Property {
public:
	Car() : Property() {};
	Car(double n);
	void nal();
};

class CountryHouse : public Property {
public:
	CountryHouse() : Property() {};
	CountryHouse(double n);
	void nal();
};

#endif

9.cpp
#include "Nalog.h"
int main()
{
	setlocale(LC_ALL, "rus");
	Property* ar[7];
	for (int i = 0; i < 7; i++)
	{
		if (i < 3)
		{
			ar[i] = new Apartment(rand() % 1000 + 10000);
		}
		else if (i < 5) {
			ar[i] = new Car(rand() % 1000 + 10000);
		}
		else {
			ar[i] = new CountryHouse(rand() % 1000 + 10000);
		}

	}
	for (int i = 0; i < 7; i++) {
		ar[i]->nal();
		delete[] ar[i];
	}

}


Nalog.cpp
#include "Nalog.h"
Property::Property() :worth(0) {};
Property::Property(double n) :worth(n) {};

Apartment::Apartment(double n) : Property(worth) {};
void Apartment::nal() {
	std::cout << "Налог на квартиру: " << worth / 1000 << std::endl;
}

Car::Car(double n) : Property(worth) {};
void Car::nal() {
	std::cout << "Налог на машину: " << worth / 200 << std::endl;
}

CountryHouse::CountryHouse(double n) : Property(worth) {};
void CountryHouse::nal() {
	std::cout << "Налог на дачу: " << worth / 500 << std::endl;
}
