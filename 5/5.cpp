#include <iostream>
#include <string>

using namespace std;

class Animal {
    public:
        int age;
        string gender;
        string yo;
        Animal(int age, string gender, string yo);
        void print();
};

void Animal::print() {
    cout << "Возраст: " << this->age << "\n" << "Пол: " << this->gender << "\n" << "Животное " << this->yo << "\n\n";
}

Animal::Animal(int age, string gender, string yo) {
    this->age = age;
    this->gender = gender;
    this->yo = yo;
    if (age < 1) {
        this->yo = "не родилось";
    }
    else if (age <= 8) {
        this->yo = "молодое";
    }
   else if (age > 8) {
        this->yo = "старое";
    }
   
}

class Cat : public Animal {
    public:
        string color;
        Cat(int age, string gender, string yo, string color) : Animal(age, gender, yo) {
            this->color = color;
        };
        void print();
};

void Cat::print() {
    cout << "Возраст: " << this->age << "\n" << "Пол: " << this->gender << "\n" << "Животное " << this->yo << "\n" << "Цвет: " << this->color << "\n\n";
}

int main()
{
    setlocale(LC_ALL, "");

    Cat c1(4, "female", "", "black");
    c1.print();
}