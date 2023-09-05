#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>

using json = nlohmann::json;
using namespace std;

struct Tovar {
	string name;
	string category;
	int price;
};

struct Client {
	string name;
	string town;
	string region;
};

struct Sale {
	string date;
	Tovar tovar;
	int quantity;
	int itogo;
	Client client;
};

int main()
{
	setlocale(LC_ALL, "");
	setlocale(LC_NUMERIC, "C");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Tovar potato{ u8"Картофель", u8"Овощи", 28 };
	Tovar peach{ u8"Персик", u8"Фрукты", 150 };
	Tovar onion{ u8"Лук", u8"Овощи", 19 };
	Tovar nktarine{ u8"Никторин", u8"Фрукты", 90 };

	Client dubilin{ u8"Дубилин", u8"Москва", u8"Центр" };
	Client yezhov{u8"Ежов", u8"Санкт-Петербург", u8"Север"};
	Client stukalo{ u8"Стукало", u8"Омск", u8"Восток" };

	Sale s1{ "19.05.2023", potato, 12, potato.price * 12, dubilin };
	Sale s2{ "20.05.2023", peach, 4, peach.price * 4, yezhov };

	/*Sale s1;
	s1.date = "19.05.2023";
	s1.tovar = potato;
	s1.quantity = 12;
	s1.itogo = potato.price * s1.quantity;
	s1.client = dubilin;*/

    json s1_json{};
    s1_json["data"] = s1.date;
    s1_json["tovar"]["name"] = s1.tovar.name;
    s1_json["tovar"]["category"] = s1.tovar.category;
    s1_json["tovar"]["price"] = s1.tovar.price;
    s1_json["quantity"] = s1.quantity;
    s1_json["itogo"] = s1.itogo;
    s1_json["klient"]["name"] = s1.client.name;
    s1_json["klient"]["town"] = s1.client.town;
    s1_json["klient"]["region"] = s1.client.region;

    json s2_json{};
    s2_json["data"] = s2.date;
    s2_json["tovar"]["name"] = s2.tovar.name;
    s2_json["tovar"]["category"] = s2.tovar.category;
    s2_json["tovar"]["price"] = s2.tovar.price;
    s2_json["quantity"] = s2.quantity;
    s2_json["itogo"] = s2.itogo;
    s2_json["klient"]["name"] = s2.client.name;
    s2_json["klient"]["town"] = s2.client.town;
    s2_json["klient"]["region"] = s2.client.region;

    json s_array = json::array();
    s_array.push_back(s1_json);
    s_array.push_back(s2_json);
    ofstream my_file("data.json");
    my_file << s_array.dump(4);
    my_file.close();


}