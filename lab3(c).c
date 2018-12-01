//COMMENT AND RESPECT
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void InsertSort(int matrix[10][10], int columnsCount, int rowsCount);
double Calc_gMeanSum(int matrix[10][10], int columnsCount, int rowsCount);

int main()
{
	int i, j, n, m;
	int matrix[10][10];

	printf("Enter count of rows(max size = 10): ");        /*������� ������ �������  n*/
	scanf("%d", &n);
	printf("Enter count of columns(max size = 10): ");        /*������� ������ �������  m*/
	scanf("%d", &m);

	
	for (i = 0; i < n; i++)  /* ������ ������� */
	{
		for (j = 0; j < m; j++)
		{
			printf("Enter data in [%d][%d]: ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}

	for (i = 0; i < n; i++)  /* �������� ������� */
	{
		for (j = 0; j < m; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	
	InsertSort(matrix, m, n);       //����� �������
	
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

void InsertSort(int matrix[10][10], int columnsCount, int rowsCount)           //n - rowsCount, m - columsCount
{
	int tmp, pos;

	for (int i = 0; i < columnsCount; i++) { // i-����� �������
		for (int j = 0; j < rowsCount; j++) // j - ����� �������� �����
		{
			pos = j;
			tmp = matrix[j][i];
			for (int h = j + 1; h < rowsCount; h++) // ���� ������ ����������� ��������(� �������)
			{
				if (matrix[h][i] > tmp)
				{
					pos = h;
					tmp = matrix[h][i];
				}
			}
			matrix[pos][i] = matrix[j][i];
			matrix[j][i] = tmp; // ������ ������� ���������� � ��������(�������)
		}
	}
}
double Calc_gMeanSum(int matrix[10][10], int columnsCount, int rowsCount)
{
	int nmbCount;
	double gMean, gMeanSum = 0;
	for (int i = 1; i < rowsCount; i++)   //dlya pershogo ryadka nemae geom symu(tomy 1) (n rowsCount)
	{
		nmbCount = 0;
		gMean = 1;
		for (int j = 0; j < columnsCount; j++)	//(m columnsCount)
		{
			if (j < i)
			{
				gMean *= abs(matrix[i][j]);
				nmbCount++;
			}
		}
		printf("Geometric mean: %lf \n", pow(gMean, 1.0 / nmbCount));
		gMeanSum += pow(gMean, 1.0 / columnsCount);
	}
	return gMeanSum;
}

