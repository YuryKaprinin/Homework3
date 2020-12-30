#include<stdlib.h>
#include<time.h>
#include<stdio.h>


int main()
{
	srand(time(NULL));
	int n = 0,
		min = -100,
		max = 100,
		k = 0;
	double tmp = 0;
	double* arr = NULL;
	scanf_s("%d", &n);
	arr = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double)(rand()) / RAND_MAX * (max - min + 1) + min;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%.2lf ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			tmp = arr[i];
			for (int j = i; j > k; --j)
			{
				arr[j] = arr[j - 1];
			}
			arr[k] = tmp;
			k++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%.2lf ", arr[i]);
	}
	free(arr);
	return 0;
}

