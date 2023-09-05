#pragma once
#include <iostream>

using namespace std;

void sort(int* nums) {
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5 - i -1; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << nums[i] << " ";
	}
}

void sred(int* nums, int n) {
	int a = 0;
	int b = 0;
	cout << endl << "Среднее значение массива:" << endl;
	for (int i = 0; i < n; i++) {
		a += nums[i];
	}
	b = a / n;
	cout << "Среднее значение: " << b << endl;
}

int* copy(int* nums, int n) {
	int* nums1 = new int[n];
	for (int i = 0; i < n; i++) {
		nums1[i] = nums[i];
	}
	return nums1;
}

void surge(int* nums, int n, int index) {
	cout << "Поиск по индексу:";
	if (index >= 0 && index <= n - 1) {
		cout << nums[index] << endl;
	}
	else {
		cout << "Неправильный индекс!" << endl;
	}
}

void first_second(int* nums, int n) {
	cout << "Перове и последние значение:" << endl;
	cout << "Первое значение: " << nums[0] << " Последнее значение: " << nums[n - 1] << endl;
}