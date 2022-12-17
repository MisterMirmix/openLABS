#include "Header.h"

void fillMatrix(int** matrix, int n, int m)
{
	std::cout << "1)Заполнить вручную\n";
	std::cout << "2)Заполнить случайными числами\n";
	int choosedOption;
	std::cin >> choosedOption;
	if (choosedOption == 2)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				matrix[i][j] = rand() % 50 - rand()%30;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				std :: cin >> matrix[i][j];
			}
		}
	}
}

void destructMatrix(int** matrix, int n, int m)  //удаление выделенной памяти под матрицу n*m
{
	for (int i = 0; i < n; ++i)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}

int** constructMatrix(int n, int m)  //выделение памяти под матрицу n*m
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[m];
	}
	return matrix;
}

void printMatrix(int** matrix, int n, int m)  //вывод матрицы на экран
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << matrix[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

int* findMinOfRow(int** matrix, int m, int n) //делаем массив из минимальных по строкам
{
	int* rowMin = new int[m];
	int minNum;
	for (int i = 0; i < m; ++i)
	{
		minNum = matrix[i][0];
		for (int j = 0; j < n; ++j)
		{
			if (minNum >= matrix[i][j])
			{
				minNum = matrix[i][j];
			}
		}
		rowMin[i] = minNum;
	}
	std::cout << "Минимальные по строкам\n";
	for (int i = 0; i < m; ++i)
	{
		std::cout << rowMin[i] << '\t';
	}
	std::cout << '\n';

	return rowMin;
}

int* findPlusColoumn(int** matrix, int m, int n) //делаем массив индексов столбцов, которые не являются положительными 
{
	int* foundRow = new int [n];
	for (int i = 0; i < n; ++i)
	{
		foundRow[i] = -1;
	}
	int sumColoumn;
	for (int i = 0; i < n; ++i)
	{
		sumColoumn = 0;
		for (int j = 0; j < m; ++j)
		{
			sumColoumn += matrix[j][i];
		}
		if (sumColoumn <= 0)
		{
			foundRow[i] = i;
		}
	}
	std::cout << "Индексы неположительных столбцов\n";
	for (int i = 0; i < n; ++i)
	{
		if (foundRow[i] != -1)
		{
			std::cout << foundRow[i] << '\t';
		}
	}
	std::cout << '\n';
	return foundRow;
}

int** taskMatrix(int** matrix, int m, int &n, int* foundRow, int* rowMin) //создание матрицы по заданию
{
	
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (foundRow[i] == -1)
		{
			++count;
		}
	}
	
	int** newMatrix = new int* [m];
	int nNew = n - count + 1;
	count = 0;
	for (int i = 0; i < m; ++i)
	{
		newMatrix[i] = new int[n - count + 1];
	}

	count = 0;
	for (int i = 0; i < nNew; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j < m; ++j)
			{
				newMatrix[j][i] = rowMin[j];
			}
		}
		else
		{
			for (int j = 0; j < m; ++j)
			{
				while (foundRow[count] == -1)
				{
					count++;
				}
				newMatrix[j][i] = matrix[j][foundRow[count]];
			}
		}
	}

	destructMatrix(matrix, m, n);
	n = nNew;
	return newMatrix;
}
