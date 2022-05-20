#include <iostream>
#include <vector>

using namespace std;

class Car {
	private :
		int fuel;
		string name;
	public :
		Car(int _fuel, string _name):
			fuel(_fuel), name(_name) {};
		Car():
			fuel(0), name("Damas"){};
		int getFuel()
		{ return fuel; }
		string getName()
		{ return name; }
		void setFuel(int n)
		{ fuel = n; }
		void setName(string str)
		{ name = str; }
		void drive(int time)
		{
			int speed;
			if (name == "FERRARI")
				speed = 300;
			else if (name == "Damas")
				speed = 50;
			if (fuel <= 0)
			{
				 cout << "No Fuel." << endl;
				 return;
			}
			cout << "Driving " << name << " for " << time << " mins, Speed : " << speed <<  endl;
			fuel -= time * 10;
			if (fuel <= 0)
				fuel = 0;
			cout << "Fuel left : " << fuel;
		}

		void display()
		{
			cout << "Name of the Car : " << name << endl;
			cout << "Fuel left : " << fuel << endl;
		}
};

int main()
{
	Car car = Car(1000, "FERRARI");
	car.display();
	car.drive(30);
}
