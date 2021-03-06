// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

void input_matrix(int m, int n, int **a);
int max_element_in_column(int j, int m, int n, int **a);
int counting(int j, int m, int n, int **a);

int main()
{
	int m, n, counter = 0;
	cin >> n >> m;
	int**a = new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	input_matrix(m, n, a);
	for (int j = 0; j < m; j++)
		counter+=counting(j, m, n, a);
	cout << counter;
	for (int i = 0; i < n; i++)
		delete a[i];
	delete a;
	return 0;
}

void input_matrix(int m, int n, int **a)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
}

int max_element_in_column(int j, int m, int n, int **a)
{
	int max = a[0][j];
	int i_max=0;
	for (int i = 1; i < n; i++)
		if (a[i][j] > max)
		{
			max = a[i][j];
			i_max = i;
		}
	return i_max;
}

int counting(int j, int m, int n,int **a)
{
	int sum = 0, counter = 0;
	int k = max_element_in_column(j, m, n, a);
	for (int i = 0; i < n; i++)
	{
		if (i == k)
			continue;
	     else sum += a[i][j];
	}
	if (sum < a[k][j])
		counter++;
	return counter;
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
