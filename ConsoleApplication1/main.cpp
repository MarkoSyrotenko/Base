#include <iostream>
#include "Base.cpp"
#include "Vehicle.cpp"
using namespace std;

int main()
{
    Base base;
    base.print();

    Vehicle vehicle1(90, 100);
    Bus bus1(5, 20, 400, 500);
    Bus bus2(5, 20, 400, 500);
    Truck truck1(30, 40, 300, 500);
    Truck truck2(30, 40, 100, 500);

    vehicle1.arrive(&base);
    base.print();
    vehicle1.leave();
    base.print();

    bus1.arrive(&base);
    base.print();
    bus2.arrive(&base);
    base.print();
    bus1.leave();
    base.print();
    bus2.leave();

    truck1.arrive(&base);
    base.print();
    truck2.arrive(&base);
    base.print();
    truck1.leave();
    base.print();
    truck2.leave();

}
