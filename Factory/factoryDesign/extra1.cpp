#include <iostream>
using namespace std;
/************************A design without factory pattern******************************/
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
class Creator {
public:
    Creator() {};
    Vehicle* pVehicle;
    virtual Vehicle* getVehicle();
};

class Creator1 : public Creator {
public:
    Creator1() {
        pVehicle = new TwoWheeler();
    };
    ~Creator1() {};

    Vehicle* getVehicle() {
        return pVehicle;
    }
};

class Creator2 : public Creator {
    Creator2() {
        pVehicle = new FourWheeler();
    };
    ~Creator2() {};

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

    Creator *creator = new Creator1();
    Vehicle *twoWheel = creator->getVehicle();
    twoWheel->printVehicle();

    return 0;
}