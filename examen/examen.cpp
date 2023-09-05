#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>

using namespace std;

struct Hero {
	//Структура героев Доты
	string name;
	string role;
	int strength;
	int agility;
	int intelligence;
	float armor;
	int damage;
	int hp;
	int mana;
	float hp_restore;
	float mana_restore;
	int speed;
};

int main()
{
	setlocale(LC_ALL, "");
	setlocale(LC_NUMERIC, "C"); //Для правильного чтения дробных чисел

	//Для записи в файл на русском языке
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice = 0;

	while (choice != 3) {
		cout << "\nВведите номер опции:\n";
		cout << "1) Записать нового героя в файл\n";
		cout << "2) Просмотреть существующих героев\n";
		cout << "3) Выйти\n";
		string buffer; //Буфер для чисел
		getline(cin, buffer);
		choice = stoi(buffer);

		if (choice == 1) {
			Hero hero;
			cout << "Введите имя героя: ";
			getline(cin, hero.name); //Запись названия персонажа в структуру

			cout << "Введите роль " << hero.name << ": ";
			getline(cin, hero.role);

			cout << "Введите силу " << hero.name << ": ";
			getline(cin, buffer);
			hero.strength = stoi(buffer); //Конвертируем значение буфера в целое число
			//stoi = string to integer = строка в целое число
			cout << "Введите ловкость " << hero.name << ": ";
			getline(cin, buffer);
			hero.agility = stoi(buffer);

			cout << "Введите интеллект " << hero.name << ": ";
			getline(cin, buffer);
			hero.intelligence = stoi(buffer);

			cout << "Введите армор " << hero.name << ": ";
			getline(cin, buffer);
			hero.armor = stof(buffer); //Конвертируем значение буфера в дробное число
			//stof = string to float = строка в дробное число

			cout << "Введите урон " << hero.name << ": ";
			getline(cin, buffer);
			hero.damage = stoi(buffer);

			cout << "Введите жизни " << hero.name << ": ";
			getline(cin, buffer);
			hero.hp = stoi(buffer);

			cout << "Введите ману " << hero.name << ": ";
			getline(cin, buffer);
			hero.mana = stoi(buffer);

			cout << "Введите скорость восстановления жизни " << hero.name << ": ";
			getline(cin, buffer);
			hero.hp_restore = stof(buffer);

			cout << "Введите скорость восстановления маны " << hero.name << ": ";
			getline(cin, buffer);
			hero.mana_restore = stof(buffer);

			cout << "Введите скорость передвижения " << hero.name << ": ";
			getline(cin, buffer);
			hero.speed = stoi(buffer);

			//Запись в файл
			ofstream my_file;
			my_file.open("heroes.csv", ios_base::app);
			my_file << hero.name << ","
				<< hero.role << ","
				<< hero.strength << ","
				<< hero.agility << ","
				<< hero.intelligence << ","
				<< hero.armor << ","
				<< hero.damage << ","
				<< hero.hp << ","
				<< hero.mana << ","
				<< hero.hp_restore << ","
				<< hero.mana_restore << ","
				<< hero.speed << "\n";
			my_file.close();
		}
		else if (choice == 2) {
			int choice2 = 0;
			cout << "\nВведите номер опции:\n";
			cout << "1) Вывести всех персонажей\n";
			cout << "2) Вывести персонажа по имени\n";
			cout << "3) Фильтрация по роли\n";
			getline(cin, buffer);
			choice2 = stoi(buffer);

			vector<Hero> heroes;

			ifstream my_file;
			my_file.open("heroes.csv");
			while (my_file.peek() != -1) {

				string str;
				getline(my_file, str);

				int index = str.find(","); //Находим индекс первой запятой

				vector<string> words; //Все поля героя
				//Пока есть запятые
				while (index >= 0) {
					string word = str.substr(0, index); //Читаем все что до запятой
					words.push_back(word); //Добавляем в список слов
					str.replace(0, index + 1, ""); //Стираем слово, которое мы прочитали, вместе с запятой
					index = str.find(","); //Находим следующую запятую
				}
				words.push_back(str); //Читаем последнее слово

				Hero hero;
				hero.name = words[0];
				hero.role = words[1];
				hero.strength = stoi(words[2]);
				hero.agility = stoi(words[3]);
				hero.intelligence = stoi(words[4]);
				hero.armor = stof(words[5]);
				hero.damage = stoi(words[6]);
				hero.hp = stoi(words[7]);
				hero.mana = stoi(words[8]);
				hero.hp_restore = stof(words[9]);
				hero.mana_restore = stof(words[10]);
				hero.speed = stoi(words[11]);

				heroes.push_back(hero);
			}

			if (choice2 == 1) {
				int count = 0;
				for (Hero hero : heroes) {
					cout << "Название: " << hero.name << "\n";
					cout << "Роль: " << hero.role << "\n";
					cout << "Сила: " << hero.strength << "\n";
					cout << "Ловкость: " << hero.agility << "\n";
					cout << "Интеллект: " << hero.intelligence << "\n";
					cout << "Армор: " << hero.armor << "\n";
					cout << "Урон: " << hero.damage << "\n";
					cout << "Жизни: " << hero.hp << "\n";
					cout << "Мана: " << hero.mana << "\n";
					cout << "Скорость восстановления жизней: " << hero.hp_restore << "\n";
					cout << "Скорость восстановления маны: " << hero.mana_restore << "\n";
					cout << "Скорость передвижения: " << hero.speed << "\n";
					cout << "\n";
					count++;
				}
				cout << "Количество записей: " << count << "\n\n";
			}
			else if (choice2 == 2) {
				cout << "Введите имя героя: ";
				string search;
				getline(cin, search);

				int count = 0;
				for (Hero hero : heroes) {
					if (hero.name.rfind(search, 0) == 0) {
						cout << "Название: " << hero.name << "\n";
						cout << "Роль: " << hero.role << "\n";
						cout << "Сила: " << hero.strength << "\n";
						cout << "Ловкость: " << hero.agility << "\n";
						cout << "Интеллект: " << hero.intelligence << "\n";
						cout << "Армор: " << hero.armor << "\n";
						cout << "Урон: " << hero.damage << "\n";
						cout << "Жизни: " << hero.hp << "\n";
						cout << "Мана: " << hero.mana << "\n";
						cout << "Скорость восстановления жизней: " << hero.hp_restore << "\n";
						cout << "Скорость восстановления маны: " << hero.mana_restore << "\n";
						cout << "Скорость передвижения: " << hero.speed << "\n";
						cout << "\n";
						count++;
					}
				}
				cout << "Количество записей: " << count << "\n\n";
			}
			else if (choice2 == 3) {
				cout << "Введите роль героя: ";
				string search;
				getline(cin, search);

				int count = 0;
				for (Hero hero : heroes) {
					if (hero.role == search) {
						cout << "Название: " << hero.name << "\n";
						cout << "Роль: " << hero.role << "\n";
						cout << "Сила: " << hero.strength << "\n";
						cout << "Ловкость: " << hero.agility << "\n";
						cout << "Интеллект: " << hero.intelligence << "\n";
						cout << "Армор: " << hero.armor << "\n";
						cout << "Урон: " << hero.damage << "\n";
						cout << "Жизни: " << hero.hp << "\n";
						cout << "Мана: " << hero.mana << "\n";
						cout << "Скорость восстановления жизней: " << hero.hp_restore << "\n";
						cout << "Скорость восстановления маны: " << hero.mana_restore << "\n";
						cout << "Скорость передвижения: " << hero.speed << "\n";
						cout << "\n";
						count++;
					}
				}
				cout << "Количество записей: " << count << "\n\n";
			}
		}
	}

}