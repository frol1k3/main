#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	//Задание 1
	int* nums = new int[5] {4, 1, 5, 63, 7};
	for (int i = 4; i >= 0; i--) {
		cout << nums[i] << " ";
	}
	delete[] nums;

	//Задание 2
	int* a = new int[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cout << "Введите длину стороны: " << endl;
		cin >> a[i];
		sum += a[i];
	}
	cout << "Периметр: " << sum;

	//Задание 3
	int* year = new int[12];
	int max = 0;
	int min = 999999999;
	for (int i = 0; i < 12; i++) {
		cout << "Введите прибыль за месяц: " << endl;
		cin >> year[i];
		if (max < year[i]) {
			max = year[i];
		}
		if (min > year[i]) {
			min = year[i];
		}
	}
	cout << "min: " << min << endl << "max: " << max;
}