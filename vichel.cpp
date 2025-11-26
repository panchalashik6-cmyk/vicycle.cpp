#include <iostream>
using namespace std;
class Vehicle
{
private:
    int id;
    string name, type;

public:
    static int total;

    Vehicle() 
    { 
        total++; 
    }
    ~Vehicle() { 
        total--;
          }

    void setData(int i, string n, string t)
    {
        id = i;
        name = n;
        type = t;
    }
    int getId() {
         return id;
         }

    virtual void display()
    {
        cout << "ID:" << id << "  Name:" << name << "  Type:" << type;
    }
};
int Vehicle::total = 0;

class Car : public Vehicle
{
public:
    void display()
    {
        Vehicle::display();
        cout << "  (Car)";
    }
};

class ElectricCar : public Car
{
public:
    void display()
    {
        Car::display();
        cout << "  Electric";
    }
};

class Aircraft
{
public:
    int range;
    Aircraft(int r = 0) { 
        range = r;
     }
};

class FlyingCar : public ElectricCar, public Aircraft
{
public:
    FlyingCar(int r = 0) : Aircraft(r) {}
    void display()
    {
        ElectricCar::display();
        cout << "  Range:" << range;
    }
};

class Sedan : public Car{};
class SUV : public Car{};

class Registry
{
    Vehicle *v[50];
    int count = 0;

public:
    void addVehicle(Vehicle *x) { 
        v[count++] = x;
     }

    void showAll()
    {
        cout << "\n--- Vehicle List ---\n";
        for (int i = 0; i < count; i++)
        {
            v[i]->display();
            cout << endl;
        }
    }

    void ashik()
    {
        int id;
        cout << "Enter ID: ";
        cin >> id;
        for (int i = 0; i < count; i++)
            if (v[i]->getId() == id)
            {
                v[i]->display();
                return;
            }
        cout << "Vehicle Not Found!";
    }
};

int main()
{
    Registry reg;
    int ch, id;
    string n, t;

    do
    {
        cout << "\n1.Add Car \n 2.Add E-Car \n 3.Add FlyingCar \n 4.Add Sedan \n 5.Add SUV \n 6.View All \n 7.Search \n 8.Exit\nEnter choice: ";
        cin >> ch;

        if (ch >= 1 && ch <= 5)
        {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> n;
            cout << "Enter Type: ";
            cin >> t;
        }

        switch (ch)
        {
        case 1:
        {
            Car *c = new Car();
            c->setData(id, n, t);
            reg.addVehicle(c);
            break;
        }
        case 2:
        {
            ElectricCar *e = new ElectricCar();
            e->setData(id, n, t);
            reg.addVehicle(e);
            break;
        }
        case 3:
        {
            FlyingCar *f = new FlyingCar(500);
            f->setData(id, n, t);
            reg.addVehicle(f);
            break;
        }
        case 4:
        {
            Sedan *s = new Sedan();
            s->setData(id, n, t);
            reg.addVehicle(s);
            break;
        }
        case 5:
        {
            SUV *u = new SUV();
            u->setData(id, n, t);
            reg.addVehicle(u);
            break;
        }
        case 6:
            reg.showAll();
            break;
        case 7:
            reg.ashik();
            break;
        case 8:
            break;
        }

    } while (ch != 8);

    return 0;
}