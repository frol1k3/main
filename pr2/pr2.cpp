#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

struct Command {
	string title;
	string action;
};

struct MenuTab {
	string menu;
	vector<Command> command;
};

int main()
{
	setlocale(LC_ALL, "ru-RU.utf-8");
	setlocale(LC_NUMERIC, "C");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file("menu.json");
	json j = json::parse(file);
	file.close();

	vector<MenuTab>menu;
	for (auto jmenu : j) {
		MenuTab new_menu;
		new_menu.menu = jmenu.value("menu", "");
		vector<Command>command;
		for (auto jcom : jmenu["commands"]) {
			Command new_command;
			new_command.title = jcom.value("title", "");
			new_command.action = jcom.value("action", "");
			command.push_back(new_command);
		}
		new_menu.command = command;
		menu.push_back(new_menu);
	}

	for (auto m : menu) {
		cout << u8"Menu: " << m.menu << "\n";
		cout << u8"Commands: " << "\n";
		for (auto com : m.command) {
			cout << u8"	Заголовок: " << com.title << "\n";
			cout << u8"	Действие: " << com.action << "\n" << "\n";
		}
	}
}