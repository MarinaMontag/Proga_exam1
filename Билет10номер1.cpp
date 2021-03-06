// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

void input_matrix(int m, int n, double**a);
void output_matrix(int m, int n, double**a);
void swapping_rows(int m, int n, double**a);
void Swap(double*x, double*y);
double sum(int i, int m, int n, double**a);

int main()
{
	int m, n;
	cin >> n >> m;
	double**a = new double*[n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	input_matrix(m, n, a);
	swapping_rows(m, n, a);
	cout << endl;
	output_matrix(m, n, a);
	for (int i = 0; i < n; i++)
		delete a[i];
	delete a;
	return 0;
}

void input_matrix(int m, int n, double**a)
{
	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)
			cin >> a[i][j];
}

void output_matrix(int m, int n, double**a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void Swap(double*x, double*y)
{
	double t = *x; *x = *y; *y = t;
}

void swapping_rows(int m, int n, double**a)
{
	int N_temp = n;
	while (N_temp > 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (i + 1 < n && i >= 0)
			{
				if (sum(i,m,n,a)>sum(i+1,m,n,a))
					for (int j = 0; j < m; j++)
						Swap(&a[i][j], &a[i + 1][j]);
			}
		}
		N_temp--;
	}
}

double sum(int i, int m, int n, double**a)
{
	double sum = 0;
	for (int j = 0; j < m; j++)
		sum += a[i][j];
	return sum;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
