#include <iostream>
#include <random>

using namespace std;

int main()
{	
	setlocale(LC_ALL, "");

	while (true){
		int a;
		cout << "1)Бросить кости, 2)Выйти: ";
		cin >> a;
		if (a == 1) {
			cout <<"Выпало " << rand() % 6 + 1 << "\n";
		}
		else if (a == 2) {
			cout << "Вы вышли";
			break;
		}
		else {
			cout << "Неправильный ввод";
		}
	}
}