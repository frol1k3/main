#include <iostream>
#include <string>

using namespace std;

class Transport {
public:
    int speed;
    int capacity;//вместимость
    Transport(int speed, int capacity);
    void print() {
        cout << "Скорость: " << this->speed << " " << "Вместимость: " << this->capacity << "\n";
    }
    void move() {
        cout << "Я пешеход" << "\n";
    }
};

Transport::Transport(int speed, int capacity) {
    this->speed = speed;
    this->capacity = capacity;
}

class Car : public Transport {
    public:
        int mileage;//пробег
        void move(){
            cout << "Врум-врум" << "\n";
        }
        Car(int mileage, int speed, int capacity) : Transport(speed, capacity) {
            this->mileage = mileage;
            this->speed = speed;
            this->capacity = capacity;
        }
        void print(){
            cout << "Скорость: " << this->speed << " " << "Вместимость: " << this->capacity << " " << "Пробег: " << this->mileage << "\n";
        }
};

class Plane : public Transport {
    public:
        int turbin;
        void move() {
            cout << "Вжух-вжух" << "\n";
        }
        Plane(int turbin, int speed, int capacity) : Transport(speed, capacity) {
            this->turbin = turbin;
            this->speed = speed;
            this->capacity = capacity;
        }
        void print(){
            cout << "Скорость: " << this->speed << " " << "Вместимость: " << this->capacity << " " << "Кол-во турбин: " << this->turbin << "\n";
        }
};

class Train : public Transport {
    public:
        int van;
        void move() {
            cout << "Туду-туду" << "\n";
        }
        Train(int van, int speed, int capacity) : Transport(speed, capacity) {
            this->van = van;
            this->speed = speed;
            this->capacity = capacity;
        }
        void print() {
            cout << "Скорость: " << this->speed << " " << "Вместимость: " << this->capacity << " " << "Кол-во вагонов: " << this->van << "\n";
        }
};

int main()
{
    setlocale(LC_ALL, "");

    Transport t1(120, 350);
    t1.print();
    t1.move();

    Car c1(220, 6, 120000);
    c1.print();
    c1.move();

    Plane p1(700, 450, 4);
    p1.print();
    p1.move();

    Train tr1(150, 400, 11);
    tr1.print();
    tr1.move();

}