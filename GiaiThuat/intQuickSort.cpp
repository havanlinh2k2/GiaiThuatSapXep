#include <iostream>
#include <ctime>
#include <time.h>
#include <iomanip>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (a[j] > pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[high]);
	return (i + 1);
}

void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(a, low, high);
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}

void Xuat(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}

void Nhap(int a[], int n)
{
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (500 + 1) - 100;
	}
}

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int* a = new int[n];
	Nhap(a, n);

	clock_t s1, e1;

	s1 = clock();
	quickSort(a, 0, n - 1);
	//Xuat(a, n);
	e1 = clock();

	cout << "Thoi gian thuc hien: " << 1000 * (double)(e1 - s1) / CLOCKS_PER_SEC << " ms" << endl;
	return 0;
}