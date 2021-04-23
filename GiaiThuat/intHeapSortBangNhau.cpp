#include <iostream>
#include <ctime>
#include <iomanip>
#include <time.h>

using namespace std;

void heapify(int a[], int n, int i)
{
    int ln = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[ln])
        ln = l;

    if (r < n && a[r] > a[ln])
        ln = r;

    if (ln != i)
    {
        swap(a[i], a[ln]);

        heapify(a, n, ln);
    }
}

void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void Xuat(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

void Nhap(int a[], int n)
{
    int k;
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
    int* a = new int[n];
    Nhap(a, n);

    clock_t s1, e1;

    s1 = clock();
    HeapSort(a, n);
    e1 = clock();

    cout << "Thoi gian chay: " << 1000 * (double)(e1 - s1) / CLOCKS_PER_SEC << " ms " << endl;
    return 0;
}