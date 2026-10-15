#pragma once
#include <iostream>
#include "Base.cpp"
using namespace std;

class Vehicle
{
protected:
	double petrol;
	double max_petrol;
	Base* base;
public:
	Vehicle(double petrol_amount, double tank_volume)
	{
		petrol = petrol_amount;
		max_petrol = tank_volume;
		base = nullptr;
	}
	double getTankVolume()
	{
		return max_petrol;
	}
	double getPetrolAmount()
	{
		return petrol;
	}
	void arrive(Base* base)
	{
		this->base = base;
		base->addVehicles(1);
	}
	bool leave()
	{
		double petrol_to_take = max_petrol - petrol;

		if (base == nullptr)
			return true;
		if (base->getPeople() == 0)
		{
			cout << "Vehicle could not leave (no people at the base)\n\n";
			return false;
		}
		if (base->getPetrol() < petrol_to_take)
		{
			cout << "Vehicle could not leave (not enough fuel)\n\n";
			return false;
		}

		cout << "A vehicle has departed\n\n";
		base->subPetrol(petrol_to_take);
		base->subPeople(1);
		base->subVehicles(1);
		base = nullptr;
		return true;
	}
};

class Bus : public Vehicle
{
	int people;
	int max_people;
public:
	Bus(int people, int max_people, double petrol, double max_petrol) : Vehicle(petrol,max_petrol)
	{
		this->people = people;
		this->max_people = max_people;
	}
	void arrive(Base* base)
	{
		if (this->base == nullptr)
		{
			cout << "A bus with " << people << " passengers has arrived\n\n";
			this->base = base;
			base->addPeople(people + 1);
			people = 0;
			base->addVehicles(1);
		}
	}
	bool leave()
	{
		double people_to_take = max_people + 1;
		if (base->getPeople() < people_to_take)
			people_to_take = base->getPeople();
		double petrol_to_take = max_petrol - petrol;

		if (base == nullptr)
			return true;
		if (base->getPeople() == 0)
		{
			cout << "Bus could not leave (no people at the base)\n\n";
			return false;
		}
		if (base->getPetrol() < petrol_to_take)
		{
			cout << "Bus could not leave (not enough fuel)\n\n";
			return false;
		}

		cout << "A bus with " << people_to_take << " passengers has departed\n\n";
		base->subPetrol(petrol_to_take);
		base->subPeople(people_to_take);
		base->subVehicles(1);
		base = nullptr;
		return true;
	}
};