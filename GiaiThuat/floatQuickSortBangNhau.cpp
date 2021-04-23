#include <iostream>
#include <ctime>
#include <time.h>
#include <iomanip>
using namespace std;

void swap(float* a, float* b)
{
	float t = *a;
	*a = *b;
	*b = t;
}

int partition(float a[], int low, int high)
{
	float pivot = a[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[high]);
	return (i + 1);
}

void quickSort(float a[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(a, low, high);
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}

void Xuat(float a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << setw(10) << fixed << setprecision(3) << a[i] << " ";
	cout << endl;
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

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	float* a = new float[n];
	Nhap(a, n);

	clock_t s1, e1;

	s1 = clock();
	quickSort(a, 0, n - 1);
	e1 = clock();

	cout << "Thoi gian thuc hien: " << 1000 * (double)(e1 - s1) / CLOCKS_PER_SEC << " ms" << endl;
	return 0;
}