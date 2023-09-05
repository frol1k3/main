#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

struct Country {
	int id;
	string name;
	string code;
};

int main()
{
	setlocale(LC_ALL, "ru-RU.utf-8");
	setlocale(LC_NUMERIC, "C");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file("countries.json");
	json j = json::parse(file);
	file.close();

	vector<Country>countries;
	for (auto jcountry : j) {
		Country new_country;
		new_country.id = jcountry.value("id", 0);
		new_country.name = jcountry.value("name", "");
		new_country.code = jcountry.value("code", "");
		countries.push_back(new_country);
	}

	for (auto country : countries) {
		cout << u8"Номер: " << country.id << "\n";
		cout << u8"Страна: " << country.name << "\n";
		cout << u8"Код страны: " << country.code << "\n";
	}
}