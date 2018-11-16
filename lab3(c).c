//doka2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void InsertSort(int matrix[10][10], int columnsCount, int rowsCount)           //n - rowsCount, m - columsCount
{
	int tmp, pos;

	for (int i = 0; i < columnsCount; ++i) { // i-номер колонки
		for (int j = 0; j < rowsCount; ++j) // j - номер текущего рядка
		{
			pos = j;
			tmp = matrix[j][i];
			for (int h = j + 1; h < rowsCount; ++h) // цикл выбора наибольшего элемента(в столбце)
			{
				if (matrix[h][i] > tmp)
				{
					pos = h;
					tmp = matrix[h][i];
				}
			}
			matrix[pos][i] = matrix[j][i];
			matrix[j][i] = tmp; // меняем местами наибольший с поточным(текущий)
		}
	}
}
double Calc_gMeanSum(int matrix[10][10], int columnsCount, int rowsCount)
{
	double gMean, gMeanSum = 0;
	for (int i = 1; i < rowsCount; i++)   //dlya pershogo ryadka nemae geom symu(tomy 1) (n rowsCount)
	{
		gMean = 1;
		for (int j = 0; j < columnsCount; j++)	//(m columnsCount)
		{
			if (j < i)
			{
				gMean *= abs(matrix[i][j]);
			}
		}
		printf("Geometric mean: %lf \n", sqrt(gMean));
		gMeanSum += sqrt(gMean);
	}
	return gMeanSum;
}
 
int main()
{
	int i, j, n, m;
	int matrix[10][10];

	printf("Enter count of rows(max size = 10): ");        /*Указать размер матрицы  n*/
	scanf("%d", &n);
	printf("Enter count of columns(max size = 10): ");        /*Указать размер матрицы  m*/
	scanf("%d", &m);

	
	for (i = 0; i < n; i++)  /* Ввести матрицу */
	{
		for (j = 0; j < m; j++)
		{
			printf("Enter data in [%d][%d]: ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}

	for (i = 0; i < n; i++)  /* показать матрицу */
	{
		for (j = 0; j < m; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	
	InsertSort(matrix, m, n);       //метод Вставки
	
	printf("Sorted matrix: \n");  
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("Geometric Mean Sum: %lf \n", Calc_gMeanSum(matrix, m, n));
		system("pause");
		return 0;
}
