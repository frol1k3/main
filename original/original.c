#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "");
	float sum = 0;
	float* a = NULL;
	a = malloc(sizeof(float) * 6);
	a[0] = 1.2;
	a[1] = 3.2;
	a[2] = 5.5;
	a[3] = 2.6;
	a[4] = 8.1;
	a[5] = 9.1;
	for (int i = 0; i < 6; i++) {
		sum += a[i];
	}
	printf("Сумма: %f", sum);
	free(a);
}