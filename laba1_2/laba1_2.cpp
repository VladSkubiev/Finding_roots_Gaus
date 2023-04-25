#include <iostream>
#include <windows.h>
using namespace std;
int n, i, j, k;
double d, s, **mat, *b1, N;

void enter(double *a[], double *b, int n) {
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";			//Вывод матрицы 			
		}
		cout << "  " << b[i] << "\n";
	}
	cout << "\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Порядок системы n: " << endl;
	cin >> n;
	double** a = new double* [n];
	for (i = 0; i <= n; i++)
		a[i] = new double[n];
	double** a1 = new double* [n];
	for (i = 0; i <= n; i++)
		a1[i] = new double[n];
	double* b = new double[n];
	double* x = new double[n];
	mat = a;
	b1 = b;
	cout << "Введмте Матрицу системы" << endl;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << "a[ " << i << "," << j << "]= ";			//Ввод левой	 части 
			cin >> a[i][j];
			a1[i][j] = a[i][j];
		}
		cout << "b,[ " << i << "]= ";							//Ввод правой части 
		cin >> b[i];
	}
	for (k = 1; k <= n; k++) // прямой ход
	{
		cout << "\n";
		enter(a, b, n);
		for (j = k + 1; j <= n; j++)
		{

			d = a[j][k] / a[k][k]; // формула (1)
			for (i = k; i <= n; i++)
			{
				a[j][i] = a[j][i] - d * a[k][i]; // формула (2)
				//cout << a[j][i] << " ";
			}
			b[j] = b[j] - d * b[k]; // формула (3)
			//cout << b[j] << " " << "\n";
		}

	}


	for (k = n; k >= 1; k--) // обратный ход
	{
		d = 0;
		for (j = k + 1; j <= n; j++)
		{
			s = a[k][j] * x[j]; // формула (4)
			d = d + s; // формула (4)
			//cout << a[k][j];
		}
		x[k] = (b[k] - d) / a[k][k]; // формула (4)
		//cout << x[k];
	}


	cout << "\nКорни системы: " << endl;							//Проверка
	for (i = 1; i <= n; i++)
		cout << "x[" << i << "]=" << x[i] << " " << endl;

	for (i = 1; i <= n; i++)
	{	
		double sum = 0;
		for (j = 1; j <= n; j++) {
			sum += mat[i][j] * x[j];
		}
		N = b1[i] - sum;
		cout << "Невязка N" << i << " = " << round(N * 10) / 10 << "\n";
	}

	return 0;

}