#include <iostream>
#include <iomanip>
#include<cmath>
#include <ctime>
#include <time.h>
using namespace std;

void Nhap(int[], int);
int SoSanh(const void*, const void*);
void Xuat(int[], int);

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int* a = new int[n];
	Nhap(a, n);

	clock_t s1, e1;

	s1 = clock();
	qsort(a, n, sizeof(int), SoSanh);
	//Xuat(a, n);
	e1 = clock();
	cout << "Thoi gian thuc hien: " << 1000 * (double)(e1 - s1) / CLOCKS_PER_SEC << " ms" << endl;

	return 0;
}

void Nhap(int a[], int n)
{
	srand(std::time(nullptr));
	for (int i = 0; i < n; i++)
	{
		a[i] = -100.0 + rand() / (RAND_MAX / (100.0 - (-100.0)));
	}
}

void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(10) << fixed << setprecision(3) << a[i];
}

int SoSanh(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}