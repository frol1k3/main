#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	regex r("(?=.[a-z])(?=.[A-Z])(?=.[0-9])(?=.[@#$%^&+=]).{8,}"); //Для пароля

	regex r_mail(R"(^\w+([-+.']\w+)@\w+([-.]\w+)\.\w+([-.]\w+)*$)"); //Для почты

	string password, email;
	cout << "Придумайте пароль: ";
	cin >> password;
	cout << "Введите почту: ";
	cin >> email;

	cout << boolalpha << password << " = " << regex_match(password, r) << endl;
	cout << boolalpha << email << " = " << regex_match(email, r_mail);
}