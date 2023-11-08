#include <iostream>
using namespace std;
/************************A design without factory pattern******************************/
enum VehicleType {
    DHO_TwoWheeler,
    DHO_ThreeWheeler,
    DHO_FourWheeler
};

// Library classes
class Vehicle {
public:
    virtual void printVehicle() = 0;
};

class TwoWheeler : public Vehicle {
public:
    void printVehicle()
    {
        cout << "I am two wheeler" << endl;
    }
};

class ThreeWheeler : public Vehicle {
public:
    void printVehicle()
    {
        cout << "I am three wheeler" << endl;
    }
};

class FourWheeler : public Vehicle {
public:
    void printVehicle()
    {
        cout << "I am four wheeler" << endl;
    }
};

// Client (or user) class
/*Problem:
The library introduces a new class ThreeWheeler to incorporate three-wheeler vehicles also.
What would happen? The client will end up chaining a new else if in the conditional ladder
to create objects of ThreeWheeler. Which in turn will need the Client to be recompiled.
So, each time a new change is made on the library side, the Client would need to make some
corresponding changes at its end and recompile the code. Sounds bad? This is a very bad
practice of design.
*/
class Client {
private:
    Vehicle* pVehicle;

public:
    Vehicle* getVehicle() { return pVehicle; }

    Client(int type)
    {
        // Client explicitly creates classes according to
        // type
        if (type == 1)
            pVehicle = new TwoWheeler();
        else if (type == 2)
            pVehicle = new FourWheeler();
        else
            pVehicle = NULL;
    }

    ~Client()
    {
        if (pVehicle) {
            delete pVehicle;
            pVehicle = NULL;
        }
    }
};
/***********************************************************************************/

/************************A design with factory pattern******************************/
// the factory class can be extended asand when required.For example,
// if we start adding water transportationand need to add vehicles like ships,
// and submarines.New Library classes can be very easily addedand extending
// the factory class won’t affect the client code at all
class Creator {
public:
    Creator() {};
    ~Creator() {};
    Vehicle* build(VehicleType type) {
        if (type == DHO_TwoWheeler) {
            return new TwoWheeler();
        }
        else if (type == DHO_ThreeWheeler) {
            return new ThreeWheeler();
        }
        else
            return new FourWheeler();
    }
};

class ClientFactory {
private:
    Vehicle* pVehicle;

public:
    ~ClientFactory()
    {
        if (pVehicle) {
            delete pVehicle;
            pVehicle = NULL;
        }
    }

    void buildVehicle(VehicleType type) {
        Creator* creator = new Creator();
        pVehicle = creator->build(type);
    }

    Vehicle* getVehicle() {
        return pVehicle;
    }
};
/***********************************************************************************/

// Driver program
int main()
{
    Client* pClient = new Client(1);
    Vehicle* pVehicle = pClient->getVehicle();
    pVehicle->printVehicle();

    // no need to re-create a new object of Client class 
    // for different type of Wheeler
    ClientFactory client = new ClientFactory();
    client.buildVehicle(DHO_ThreeWheeler);
    Vehicle* pVehicle = client.getVehicle();
    pVehicle->printVehicle();
    return 0;
}