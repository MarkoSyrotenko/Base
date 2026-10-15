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

		if (petrol > max_petrol)
			petrol = max_petrol;
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
		if (this->base == nullptr)
		{
			cout << "A vehicle has arrived (fuel - " << petrol << "/" << max_petrol << ")\n\n";
			this->base = base;
			base->addPeople(1);
			base->addVehicles(1);
		}
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

//bus--------------------------------------------------------------------------------------------
class Bus : public Vehicle
{
	int people;
	int max_people;
public:
	Bus(int people, int max_people, double petrol, double max_petrol) : Vehicle(petrol,max_petrol)
	{
		this->people = people;
		this->max_people = max_people;

		if (people > max_people)
			this->people = max_people;
	}
	int getPeopleCount()
	{
		return people;
	}
	int getMaxPeople()
	{
		return max_people;
	}
	void arrive(Base* base)
	{
		if (this->base == nullptr)
		{
			cout << "A bus with " << people << " passengers has arrived (fuel - " << petrol << "/" << max_petrol << ")\n\n";
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
		people = people_to_take - 1;
		base = nullptr;
		return true;
	}
};

//truck--------------------------------------------------------------------------------------------
class Truck : public Vehicle
{
	int load;
	int max_load;
public:
	Truck(int load, int max_load, double petrol, double max_petrol) : Vehicle(petrol, max_petrol)
	{
		this->load = load;
		this->max_load = max_load;

		if (load > max_load)
			this->load = max_load;
	}
	int getCurrentLoad()
	{
		return load;
	}
	int getMaxLoad()
	{
		return max_load;
	}
	void arrive(Base* base)
	{
		if (this->base == nullptr)
		{
			cout << "A truck with " << load << " tons of goods has arrived (fuel - " << petrol << "/" << max_petrol << ")\n\n";
			this->base = base;
			base->addGoods(load);
			base->addPeople(1);
			load = 0;
			base->addVehicles(1);
		}
	}
	bool leave()
	{
		double load_to_take = max_load;
		if (base->getGoods() < load_to_take)
			load_to_take = base->getGoods();
		double petrol_to_take = max_petrol - petrol;

		if (base == nullptr)
			return true;
		if (base->getPeople() == 0)
		{
			cout << "Truck could not leave (no people at the base)\n\n";
			return false;
		}
		if (base->getPetrol() < petrol_to_take)
		{
			cout << "Truck could not leave (not enough fuel)\n\n";
			return false;
		}

		cout << "A truck with " << load_to_take << " tons of goods has departed\n\n";
		base->subPetrol(petrol_to_take);
		base->subPeople(1);
		base->subGoods(load_to_take);
		base->subVehicles(1);
		load = load_to_take;
		base = nullptr;
		return true;
	}
};
