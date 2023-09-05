#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include <Windows.h>
#include <vector>

void admin_user();

using namespace std;
using json = nlohmann::json;

struct Person {
    int id;
    string login;
    string pass;
    string role;
    float balance;
};

struct Eat {
    int id;
    string category;
    string name;
    float price;
    int mass;
    int discount;
};

struct Order {
    vector<Eat> eat;
    Person person;
    float sum;
    string status;
};

int main()
{
    setlocale(LC_ALL, "ru-Ru.utf-8");
    setlocale(LC_NUMERIC, "C");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        int choise;
        cout << "1 - Регистрация\n2 - Авторизация\n3 - Выйти" << endl;
        cin >> choise;

        if (choise == 1) {
            cout << "Придумайте логин: ";
            string login;
            cin >> login;
            cout << "Придумайте пароль: ";
            string pass;
            cin >> pass;
            string role = "default";

            ofstream file;
            file.open("login.txt", ios_base::app);
            file << login << "\n" << pass << "\n" << role << "\n";
            file.close();
        }

        else if (choise == 2) {
            cout << "Введите логин: ";
            string login;
            cin >> login;
            cout << "Введите пароль: ";
            string pass;
            cin >> pass;

            ifstream file;
            file.open("login.txt");

            string login_line;
            string pass_line;

            bool is_logged_in = false;
            while (getline(file, login_line)) {
                getline(file, pass_line);
                if (login == login_line) {
                    if (pass == pass_line) {
                        cout << "Вы вошли!";
                        is_logged_in = true;
                    }
                    break;
                }
            }
            if (is_logged_in) {
                break;
            }
            else {
                cout << "Неправильный логин или пароль\n";
            }
        }
        else if(choise == 3){
            cout<<"Вы вышли!";
            break;
        }
    }
    admin_user();
}

void admin_user() {
    string change;
    cout << u8"Выберите одно из действий: " << endl;
    cout << u8"   1 - Добавить товар" << endl;
    cout << u8"   2 - Редактировать товар" << endl;
    cout << u8"   3 - Удалить товар" << endl;
    cout << u8"   4 - Посмотреть список товаров" << endl;
    cout << u8"   5 - Выйти" << endl;
    getline(cin, change);
    if (change == "1") {

        ifstream file("food.json");
        json j = json::parse(file);
        file.close();


        int last_id = 0;
        for (auto jeat : j) {
            last_id = jeat.value("id", 0);
        }
        //last_id++;

        string buffer;
        Eat eat1;
        eat1.id = last_id;
        cout << u8"Введите название блюда: " << endl;
        getline(cin, eat1.name);
        cout << u8"Введите массу блюда: " << endl;
        getline(cin, buffer);
        eat1.mass = stoi(buffer);
        cout << u8"Введите стоимость блюда: " << endl;
        getline(cin, buffer);
        eat1.price = stof(buffer);
        cout << u8"Выбирете категорию блюда(еда, напитки, десерты): " << endl;
        getline(cin, buffer);
        if (buffer == "еда") {
            eat1.category = "eat";
        }
        else if (buffer == "напитки") {
            eat1.category = "drink";
        }
        else if (buffer == "десерты") {
            eat1.category = "desert";
        }
        cout << u8"Введите процент скидки(значок % указывать не нужно): " << endl;
        getline(cin, buffer);
        eat1.discount = stoi(buffer);
        //eat1.price = eat1.price - eat1.price / 100 * eat1.discount;
        json array = json::array();

        json json_p1{};
        json_p1["id"] = eat1.id;
        json_p1["name"] = eat1.name;
        json_p1["mass"] = eat1.mass;
        json_p1["category"] = eat1.category;
        json_p1["price"] = eat1.price;
        json_p1["discount"] = eat1.discount;


        array.insert(array.begin() + last_id, json_p1);
        string data = array.dump(4);
        ofstream file2;
        file2.open("food.json");
        file2 << data;
        file2.close();
    }
    else if (change == "2") {
        ifstream file("food.json");
        json j = json::parse(file);
        file.close();
        vector<Eat> foods;
        for (auto jeat : j) {
            Eat eat1;
            eat1.id = jeat.value("id", 0);
            eat1.name = jeat.value("name", "");
            eat1.mass = jeat.value("mass", 0);
            eat1.category = jeat.value("category", "");
            eat1.price = jeat.value("price", 0);
            eat1.discount = jeat.value("discount", 0);
            foods.push_back(eat1);
        }
        string change2;
        cout << u8"Выберите из списка название блюда, которое хотите заменить: " << endl;
        for (auto i : foods) {
            cout << i.name << ", ";
        }
        cout << endl;
        getline(cin, change2);
        for (auto i : foods) {
            if (i.name == change2) {
                string change3;
                cout << u8"Выберите категорию, значение которой вы хотите заменить: \n\t1 - цена\n \t2 - название\n \t3 - масса\n \t4 - категория\n \t5 - скидка\n";
                getline(cin, change3);
                if (change3 == "1") {
                    string buffer;
                    cout << u8"Введите новую цену: ";
                    getline(cin, buffer);
                    i.price = stof(buffer);
                }
                else if (change3 == "2") {
                    string buffer;
                    cout << u8"Введите новое название: ";
                    getline(cin, buffer);
                    i.name = buffer;
                }
                else if (change3 == "3") {
                    string buffer;
                    cout << u8"Введите новую массу: ";
                    getline(cin, buffer);
                    i.mass = stoi(buffer);
                }
                else if (change3 == "4") {
                    string buffer;
                    cout << u8"Введите новую категорию: ";
                    getline(cin, buffer);
                    i.category = buffer;
                }
                else if (change3 == "5") {
                    string buffer;
                    cout << u8"Введите новую скидку: ";
                    getline(cin, buffer);
                    i.discount = stoi(buffer);
                }
            }
            json json_p1{};
            json_p1["id"] = i.id;
            json_p1["name"] = i.name;
            json_p1["mass"] = i.mass;
            json_p1["category"] = i.category;
            json_p1["price"] = i.price;
            json_p1["discount"] = i.discount;

            json array = json::array();
            array.insert(array.begin() + i.id, json_p1);
            string data = array.dump(4);
            ofstream file2;
            file2.open("new_food.json");
            file2 << data;
            file2.close();

        }
        remove("food.json");
        rename("new_food.json", "food.json");
        remove("new_food.json");
    }
    else if (change == "3") {

    }
    else if (change == "4") {

    }
    else if (change == "5") {

    }
}

void default_user() {
    int choise;
    cout << u8"1 - Хотите сделать заказ; 2 - Хоттите выйти: " << endl;
    cin >> choise;
    if (choise == 1) {
        while (true) {
            int choise2;
            cout << u8"Выберите категорию:" << endl;
            cout << u8"1 - Еда\n2 - Напитки\n3 - Десерты: ";
            cin >> choise2;
            if (choise2 == 1) {
                while (true) {
                    ifstream file("food.json");
                    json j = json::parse(file);
                    file.close();
                    vector<Eat> foods;
                    for (auto jeat : j) {
                        Eat new_eat;
                        new_eat.id = jeat.value("id", 0);
                        new_eat.name = jeat.value("name", "");
                        new_eat.mass = jeat.value("mass", 0);
                        new_eat.category = jeat.value("category", "");
                        new_eat.price = jeat.value("price", 0);
                        new_eat.discount = jeat.value("discount", 0);
                        foods.push_back(new_eat);
                    }
                    string eat;
                    cout << u8"Введите название блюда из списка: ";
                    cin >> eat;
                }
            }
            else if (choise2 == 2) {
                while (true) {
                    ifstream file("food.json");
                    json j = json::parse(file);
                    file.close();
                    vector<Eat> foods;
                    for (auto jdrink : j) {
                        Eat new_drink;
                        new_drink.id = jdrink.value("id", 0);
                        new_drink.name = jdrink.value("name", "");
                        new_drink.mass = jdrink.value("mass", 0);
                        new_drink.category = jdrink.value("category", "");
                        new_drink.price = jdrink.value("price", 0);
                        new_drink.discount = jdrink.value("discount", 0);
                        foods.push_back(new_drink);
                    }
                        string drink;
                        cout << u8"Введите название напитка из списка: ";
                        cin >> drink;
                }
            }
            else if (choise2 == 3) {
                while (true) {
                    ifstream file("food.json");
                    json j = json::parse(file);
                    file.close();
                    vector<Eat> foods;
                    for (auto jdes : j) {
                        Eat new_des;
                        new_des.id = jdes.value("id", 0);
                        new_des.name = jdes.value("name", "");
                        new_des.mass = jdes.value("mass", 0);
                        new_des.category = jdes.value("category", "");
                        new_des.price = jdes.value("price", 0);
                        new_des.discount = jdes.value("discount", 0);
                        foods.push_back(new_des);
                    }
                    string dessert;
                    cout << u8"Введите название десерта из списка: ";
                    cin >> dessert;
                }
            }
        }
    }
    else if (choise == 2) {
        cout << u8"Вы вышли!";
    }
}