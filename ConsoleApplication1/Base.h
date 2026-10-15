#pragma once
#include <iostream>
using namespace std;

class Base
{
	int people_on_base;
	int vehicles_on_base;
	double petrol_on_base;
	double goods_on_base;
public:
	Base()
	{
		people_on_base = 0;
		vehicles_on_base = 0;
		petrol_on_base = 500;
		goods_on_base = 0;
	}
	void print()
	{
		cout << "people on base: " << people_on_base;
		cout << "\nvehicles on base: " << vehicles_on_base;
		cout << "\npetrol on base: " << petrol_on_base;
		cout << "\ngoods on base: " << goods_on_base << endl << endl;
	}


	int getPeople()
	{
		return people_on_base;
	}
	void setPeople(int p)
	{
		people_on_base=p;
	}
	void addPeople(int p)
	{
		people_on_base += p;
	}
	void subPeople(int p)
	{
		people_on_base -= p;
	}

	int getVehicles()
	{
		return vehicles_on_base;
	}
	void setVehicles(int p)
	{
		vehicles_on_base = p;
	}
	void addVehicles(int p)
	{
		vehicles_on_base += p;
	}
	void subVehicles(int p)
	{
		vehicles_on_base -= p;
	}

	double getPetrol()
	{
		return petrol_on_base;
	}
	void setPetrol(int p)
	{
		petrol_on_base = p;
	}
	void addPetrol(int p)
	{
		petrol_on_base += p;
	}
	void subPetrol(int p)
	{
		petrol_on_base -= p;
	}

	double getGoods()
	{
		return goods_on_base;
	}
	void setGoods(int p)
	{
		goods_on_base = p;
	}
	void addGoods(int p)
	{
		goods_on_base += p;
	}
	void subGoods(int p)
	{
		goods_on_base -= p;
	}
};