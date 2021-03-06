// Билет12номер1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

void input_matrix(int m, int n, double**a);
double max_element(int i, int m, int n, double**a);
double min_element(int m, int n, double*b);

int main()
{
	int m, n;
	cin >> n >> m;
	double**a = new double*[n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	double*b = new double[n];
	input_matrix(m, n, a);
	for (int i = 0; i < n; i++)
		b[i] = max_element(i, m, n, a);
	cout << min_element(m, n, b);
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

double max_element(int i, int m, int n, double**a)
{
	double max = a[i][0];
	for (int j = 1; j < m; j++)
		if (a[i][j] > max)
			max = a[i][j];
	return max;
}

double min_element(int m, int n, double*b)
{
	double min = b[0];
	for (int i = 1; i < n; i++)
		if (b[i] < min)
			min = b[i];
	return min;
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
