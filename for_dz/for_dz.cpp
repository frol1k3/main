#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <windows.h>

using json = nlohmann::json;
using namespace std;

struct Person {
	string name;
	string surename;
	string otch;
	string position;
	string DateofBirth;
	int experience;
	string gender;
};


int main()
{
	setlocale(LC_ALL, "");
	setlocale(LC_NUMERIC, "C");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Person p1;
	p1.name = "Alex";
	p1.surename = "Frolov";
	p1.otch = "Denicovich";
	p1.position = "Manager";
	p1.DateofBirth = "24.04.2007";
	p1.experience = 4;
	p1.gender = "men";


	json json_p1{};
	json_p1["name"] = p1.name;
	json_p1["surename"] = p1.surename;
	json_p1["otchestvo"] = p1.otch;
	json_p1["position"] = p1.position;
	json_p1["Date of Birth"] = p1.DateofBirth;
	json_p1["experince"] = p1.experience;
	json_p1["gender"] = p1.gender;

	string data = json_p1.dump(4);
	ofstream file;
	file.open("employees.json");
	file << data;
	file.close();
}