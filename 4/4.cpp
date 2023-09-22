#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    string mark;
    string model;
    string color;
    void print();
    Car(string mark, string model, string color, int age);
private:
    int age;
};

Car::Car(string mark, string model, string color, int age) {
    this->mark = mark;
    this->model = model;
    this->color = color;
    this->age = age;
    if (age < 1980) {
        this->age = 2020;
    }
    else {
        this->age = age;
    }
}

void Car::print() {
    cout << "Марка автомобиля: " << this->mark << "\n" << "Модель: " << this->model << "\n" << "Цвет: " << this->color << "\n" << "Год выпуска: " << this->age << "\n\n";
}

int main() {

	setlocale(LC_ALL, "");

    Car c1("bmw", "m8", "blue", 780);
    c1.print();
}