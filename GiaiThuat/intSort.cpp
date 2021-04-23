#include <iostream>
#include <iomanip>
#include<cmath>
#include <ctime>
#include <time.h>
#include <algorithm>
#include<functional>
using namespace std;

void Nhap(int[], int);
void Xuat(int[], int);
int SoSanh(const void*, const void*);

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int* a = new int[n];
	Nhap(a, n);

	clock_t s1, e1;

	s1 = clock();
	sort(a, a + n,greater<int>());
	e1 = clock();
	cout << endl;
	cout << "Thoi gian chay: " << 1000 * (double)(e1 - s1) / CLOCKS_PER_SEC << " ms" << endl;

	return 1;
}

void Nhap(int a[], int n)
{
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (200 + 1) - 100;
	}
}

void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << a[i];
	}
}