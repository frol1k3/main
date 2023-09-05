#include <iostream>
using namespace std;

void print(int* nums, int n);
void sort(int* nums, int n);
void sred_sum(int* nums, int n);
void min_max(int* nums, int n);
void replace(int* nums, int n, int index, int value);
void first_second(int* nums, int n);
void surge(int* nums, int n, int index);
int* copy(int* nums, int n);

int main()
{
	setlocale(LC_ALL, "");
	int n = 6;
	int* nums = new int[n] {8, 1, 6, 5, 9, 7};
	print(nums, n);
	sort(nums, n);
	sred_sum(nums, n);
	min_max(nums, n);
	replace(nums, n, 1, 11);
	first_second(nums, n);
	surge(nums, n, 3);
	int* arr = copy(nums, n);


	delete[] nums;
}




void print(int* nums, int n) {
	cout << "Исходный массив:" << endl;
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

void sort(int* nums, int n) {
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

void sred_sum(int* nums, int n) {
	int a = 0;
	int b = 0;
	cout << "Среднее значение массива и сумма:" << endl;
	for (int i = 0; i < n; i++) {
		a += nums[i];
	}
	b = a / n;
	cout << "Среднее значение: " << b << " Сумма: " << a << endl;
}

void min_max(int* nums, int n) {
	cout << "Минимальное и максимальное значение массива: " << endl;
	int min = nums[0];
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < nums[i]) {
			max = nums[i];
		}
		else if (min > nums[i]) {
			min = nums[i];
		}
	}
	cout << "min: " << min << " max: " << max << endl;
}

void replace(int* nums, int n, int index, int value) {
	cout << "Замена числа по индексу:" << endl;
	if (index >= 0 && index < n - 1) {
		nums[index] = value;
	}
	else {
		cout << "Неправильный индекс!" << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

void first_second(int* nums, int n) {
	cout << "Перове и последние значение:" << endl;
	cout << "Первое значение: " << nums[0] << " Последнее значение: " << nums[n - 1] << endl;
}

void surge(int* nums, int n, int index) {
	cout << "Поиск по индексу:" << endl;
	if (index >= 0 && index < n - 1) {
		cout << nums[index] << endl;
	}
	else {
		cout << "Неправильный индекс!" << endl;
	}
}

int *copy(int* nums, int n) {
	int* nums1 = new int[n];
	for (int i = 0; i < n; i++) {
		nums1[i] = nums[i];
	}
	return nums1;
}

