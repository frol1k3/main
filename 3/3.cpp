#include <iostream>
#include <string>

using namespace std;

class Circule {
public:
    double area;
    double perimeter;
    Circule(double r);
    void OutPut();
private:
    void setArea();
    void setPerimeter();
    double r;
};

Circule::Circule(double r) {
    this->r = r;
    this->setArea();
    this->setPerimeter();
}

void Circule::setArea() {
    this->area = 3.14 * (this->r * this->r);
}

void Circule::setPerimeter() {
    this->perimeter = 3.14 * this->r * 2;
}

void Circule::OutPut() {
    cout << "Площадь: " << this->area << " " << "Периметр: " << this->perimeter << "\n";
}

int main()
{
    setlocale(LC_ALL, "");

    Circule c1(5);
    c1.OutPut();

    return 0;
}