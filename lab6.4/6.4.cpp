//ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}

int multiply (int* a, const int size)
{
	int M=1;
	for (int i = 0; i < size; i++)
		if (a[i]<0)
			M *= a[i];
	return M;
}

int findMaxElement(int* a, const int size, int low)
{
	int max = low;
	for (int i = 0; i < size; i++) {
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

int sum(int* a, const int size, int low)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (a[i]>0 && a[i]!=findMaxElement(a, size, low))
			S += a[i];
	return S;
}

void Inverse(int* a, const int n)
{
	int tmp;
	for (int i = 0; i < n / 2; i++)
	{
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}
}

int main()
{
	srand((unsigned)time(NULL)); 
	int n;
	cout << "Enter size of array"; cin >> n;
	int* a = new int[n];
	int low = -10;
	int high = 10;
	create(a, n, low, high);
	print(a, n);
	cout << "M =" << multiply(a, n) << endl;
	cout << "S = " << sum(a, n, low) << endl;
	Inverse(a, n);
	print(a, n);
	return 0;
}