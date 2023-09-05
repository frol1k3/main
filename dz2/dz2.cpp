#include <iostream>
using namespace std;
void fact(int a);
bool prost(int a);
void cube(int a);
void rav(int a, int b);
bool ist(int a);

int main()
{
	setlocale(LC_ALL, "");
	int a, b;
	cout << "Введите число: ";
	cin >> a;
	cout << "Введите число: ";
	cin >> b;
	fact(a);
	prost(a);
	cube(a);
	rav(a, b);
	ist(a);
}

void fact(int a) {
	int b = 1;
	for (int i = 1; i < a + 1; i++) {
		b *= i;
	}
	cout << "Факториал a: " << b << endl;
}

bool prost(int a) {
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

void cube(int a) {
	int b = 1;
	b = a * a * a;
	cout << "Куб а: " << b << endl;
}

void rav(int a, int b) {
	cout << "Наибольшее число: ";
	if (a > b) {
		cout << a;
	}
	else {
		cout << b;
	}
}

bool ist(int a) {
	if (a > 0) {
		return true;
	}
	return false;
}