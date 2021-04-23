#include <iostream>
#include <iomanip>
#include<cmath>
#include <ctime>
#include <time.h>
#include <algorithm>
#include<functional>
using namespace std;

void Nhap(float[], int);
void Xuat(float[], int);
int SoSanh(const void*, const void*);

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	float* a = new float[n];
	Nhap(a, n);

	clock_t s1, e1;

	s1 = clock();
	sort(a, a + n);
	e1 = clock();
	cout << endl;
	cout << "Thoi gian thuc hien: " << 1000 * (double)(e1 - s1) / CLOCKS_PER_SEC << " ms" << endl;

	return 1;
}

void Nhap(float a[], int n)
{
	float k;
	cout << "Nhap so: ";
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		a[i] = k;
	}
}

void Xuat(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << fixed << setprecision(3) << a[i];
	}
}