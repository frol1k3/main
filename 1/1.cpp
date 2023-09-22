#include <iostream>
#include <random>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	while (true) {
		
		string phrase = "";

		cout << "";
		cin >> phrase;
		if (phrase == "Привет" || phrase == "Здравстуйте" || phrase == "привет" || phrase == "здравстуйте") {
			cout << "Привет!" << "\n";
		}
		else if (phrase == "Пока" || phrase == "пока") {
			cout << "Пока!";
			break;
		}
		else {
			int min = 1;
			int max = 3;
			int n = rand() % max + min;
			if (n == 1) {
				cout << "Я абсолют, я вижу всё" << "\n";
			}
			else if (n == 2) {
				cout << "Я не Тайлер Дердан" << "\n";
			}
			else if (n == 3) {
				cout << "Раян Гослинг" << "\n";
			}
		}
	}
}