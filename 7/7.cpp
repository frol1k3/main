#include <iostream>
#include <string>

using namespace std;

class Gadget {
public:
    string name;
    int price;
    float weight;

    Gadget(string name, int price, float weight) {
        this->name = name;
        this->price = price;
        this->weight = weight;
    };

    void Output() {
        cout << this->name << endl;
        cout << this->price << endl;
        cout << this->weight << endl;
    };
};

class Smartphone : public Gadget {

public:
    int RAM;
    string CPU;

    Smartphone(string name, int price, float weight, int RAM, string CPU) : Gadget(name, price, weight) {
        this->RAM = RAM;
        this->CPU = CPU;
    }

    void Output() {
        Gadget::Output();
        cout << this->RAM << endl;
        cout << this->CPU << endl;
    }
};

class SmartWatch : public Gadget {
    public:
        bool pulseSensor;
        string wristStmpColor;

        SmartWatch(string name, int price, float weight, bool pulseSensor, string wristStmpColor) : Gadget(name, price, weight) {
            this->pulseSensor = pulseSensor;
            this->wristStmpColor = wristStmpColor;
        };
        void Output() {
            Gadget::Output();
            cout << this->pulseSensor << endl;
            cout << this->wristStmpColor << endl;
        }

};

int main()
{
    setlocale(LC_ALL, "");
    Smartphone* samsung = new Smartphone("Samsung Galaxy S15", 50000, 230, 8, "ARM Super Duper Samsung Processor");
    samsung->Output();

    SmartWatch* applewatch = new SmartWatch("AppleWatch series 7", 25000, 90, 1, "Black");
    applewatch->Output();
}