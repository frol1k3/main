#include <iostream>
#include <string>

using namespace std;

class Food {
	public:
		string name;
		int price;
		int calories;
		Food(string name, int price, int calories) {
			this->name = name;
			this->price = price;
			this->calories = calories;
		};
		void print() {
			cout << endl << this->name << endl;
			cout << this->price << endl;
			cout << this->calories << endl;
		}
};

class Burger : public Food {
	public:
		string sauce;
		string cutlet;
		Burger(string name, int price, int calories, string sauce, string cutlet) : Food(name, price, calories) {
			this->sauce = sauce;
			this->cutlet = cutlet;
		}
		void print() {
			Food::print();
				cout << this->sauce << endl;
				cout << this->cutlet << endl;
		}
};

class Pizza : public Food {
public:
	string toping;
	int diametr;
	Pizza(string name, int price, int calories, string toping, int diametr) : Food(name, price, calories) {
		this->toping = toping;
		this->diametr = diametr;
	}
	void print() {
		Food::print();
		cout << this->toping << endl;
		cout << this->diametr << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "");
	Food* p1 = new Food("People", 100000000, 0);
	p1->print();

	Burger* b1 = new Burger("Big Mac", 170, 300, "BBQ", "beef");
	b1->print();

	Pizza* piz1 = new Pizza("pepperoni", 320, 500, "sausage", 20);
	piz1->print();
}