#include <iostream>
#include "Base.cpp"
#include "Vehicle.cpp"
using namespace std;

int main()
{
    Base base;
    base.print();

    Bus bus1(5, 20, 400, 500);
    Bus bus2(5, 20, 400, 500);

    bus1.arrive(&base);
    bus2.arrive(&base);
    base.print();
    bus1.leave();
    base.print();
    bus2.leave();
}
