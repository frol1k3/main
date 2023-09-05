#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>

using namespace std;

struct Student {
    string fio;
    int math;
    int rus;
    int chem;
    int bio;
    int fiz;
    float avg;
};

int main()
{
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student student;
    string buffer;
    while (true) {
        int choice;
        cout << "Если вы хотите добавить студента введите 1, если вывести список студентов введие 2, если хотите выйти введите 3: ";
        getline(cin, buffer);
        choice = stoi(buffer);
        if (choice == 3) {
            cout << "Введите ФИО студента: ";
            getline(cin, student.fio);
            cout << "Введите оценку по математике: ";
            getline(cin, buffer);
            student.math = stoi(buffer);
            cout << "Введите оценку по русскому языку: ";
            getline(cin, buffer);
            student.rus = stoi(buffer);
            cout << "Введите оценку по химии: ";
            getline(cin, buffer);
            student.chem = stoi(buffer);
            cout << "Введите оценку по биологии: ";
            getline(cin, buffer);
            student.bio = stoi(buffer);
            cout << "Введите оценку по физике: ";
            getline(cin, buffer);
            student.fiz = stoi(buffer);

            student.avg = (float)(student.math + student.rus + student.bio + student.chem + student.fiz) / 5;
            ofstream my_file;
            my_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            try {
                my_file.open("students.csv", ios_base::app);
                my_file << student.fio << "," << student.math << "," << student.rus << ","
                    << student.bio << "," << student.chem << "," << student.fiz << "," << student.avg << "\n";
                my_file.close();
            }
            catch (ios_base::failure e) {
                if (my_file.fail()) {
                    cout << "Не удалось открыть файл.";
                }
                else {
                    cout << e.what();
                }
            }
        }
        if (choice == 3) {
            break;
        }
        if (choice == 2) {
            ifstream logi;
            string line;
            logi.open("students.csv");
            vector<string> list;
            while (getline(logi, line))
            {
                int index = line.find(",");
                while (index >= 0) {
                    string word = line.substr(0, index);
                    list.push_back(word);
                    line.replace(0, index + 1, "");
                    index = line.find(",");
                }
                list.push_back(line);
            }
            for (string element : list) {
                cout << element << "\n";
            }
        }
    }
}