#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef long double (*modul)(long double s);

double mycos(double x, int k, double e) {
	double x2 = x * x,
		c = 1,
		n = 2,
		f = 2,
		z = -1,
		i = 0;

	while (((x2 / f) >= e) && (i < k))
	{
		c = c + z * x2 / f;
		n = n + 2;
		x2 = x2 * x * x;
		f = f * (n - 1) * n;
		z = z * (-1);
		i = i + 1;
	}
	return c;
}

long double f(long double s) // modul 
{
	if (s < 0)
		s = -s;
	return s;
}

long double cotan(long double x, int k, long double e)
{
	modul mod = f;
	long double sin = x, cos = 1, cotan = 0, a = 1;
	int n = 2, i = 0;
	while ((mod(cos / sin - cotan) > e) && (i < k))
	{
		cotan = cos / sin;
		a *= -x * x / ((n - 1) * n);
		cos += a;
		sin += a * x / (n + 1);
		n += 2;
		i = i + 1;
	}
	cotan = cos / sin;
	return cotan;
}

void enter(double* x, int* n, double* e)
{
	printf("Введите x \n");
	scanf_s("%lf", x);
	printf("Введите число элементов ряда \n");
	scanf_s("%d", n);
	printf("Введите точность вычислений \n");
	scanf_s("%lf", e);
}

long double ch(long double x, int k, long double e)
{
	double result = 1;
	double m = 1;
	int i = 1, j = 0;
	while ((abs(m) >= e) && j < k)
	{
		m *= x * x;
		m /= 2 * i * (2 * i - 1);
		result += m;
		i = i + 1;
		j = j + 1;
	}
	return result;
}

void menu()
{
	modul mod = f;
	double x = 0, e = 0;
	int n = 0;
	int max_op = 0;
	int op;
	long double res = 0, pr1 = 0;
	char men[5][50] = { {"Ввести значения"}, {"cos(x)"}, {"ctg(x)"}, {"ch(x)"}, {"Выход"} };
	max_op = 5;
	while (1)
	{
		system("cls");
		for (int i = 0; i < max_op; i++)
		{
			printf("%d. %s \n", i + 1, men[i]);
		}
		scanf_s("%d", &op);
		switch (op)
		{
		case 1:
		{
			enter(&x, &n, &e);
			break;
		}
		case 2:
		{
			res = mycos(x, n, e);
			pr1 = cos(x);
			printf("Эталонное значение cos(%.0lf) %.13lf \n", x, pr1);
			printf("Вычислительная оценка %.13lf \n", res);
			printf("Разница между оценкой и эталонным значением %.13lf \n", mod(res - pr1));
			system("pause");
			break;
		}
		case 3:
		{
			res = cotan(x, n, e);
			pr1 = cos(x) / sin(x);
			printf("Эталонное значение cos(%.0lf) %.13lf \n", x, pr1);
			printf("Вычислительная оценка %.13lf \n", res);
			printf("Разница между оценкой и эталонным значением %.13f \n", mod(res - pr1));
			system("pause");
			break;
		}
		case 4:
		{
			res = ch(x, n, e);
			pr1 = cosh(x);
			printf("Эталонное значение ch(%.0lf) %.13lf \n", x, pr1);
			printf("Вычислительная оценка %.13lf \n", res);
			printf("Разница между оценкой и эталонным значением %.13f \n", mod(res - pr1));
			system("pause");
			break;
		}
		default:
		{
			break;
		}
		}
		if (op == 5)
		{
			break;
		}
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	menu();
}
