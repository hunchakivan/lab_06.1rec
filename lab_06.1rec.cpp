#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) {
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i) {
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int Sum(int* a, const int size, int i) {
	if (i < size)
		return a[i] + Sum(a, size, i + 1);
	else
		return 0;
}


int Quantity(int* a, const int size, int i) {
	if (i >= size)
		return 0;
	if (a[i] == 0)
		return 1 + Quantity(a, size, ++i);
	else
		return Quantity(a, size, ++i);
}

int Change(int* a, const int size, int i) {
	if (i >= size)
		return 0;
	if (a[i] > 0 && a[i] % 2 == 0)
		a[i] = 0;
	cout << setw(4) << a[i];
	Change(a, size, ++i);
}

int main() {
	srand((unsigned)time(NULL));
	const int n = 25;
	int a[n];
	int Low = -20;
	int High = 30;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "S = " << Sum(a, n, 0) << endl;
	Change(a, n, 0);
	cout << endl;
	cout << "Q = " << Quantity(a, n, 0) << endl;
	return 0;
}