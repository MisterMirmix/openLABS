#include "Matrix.h"


void fillMatrix(int** matrix, int n, int m)  //���������� ������� 
{
	std::cout << "1)��������� �������\n";
	std::cout << "2)��������� ���������� �������\n";
	
	int choosedOption;
	bool isError = false;
	do
	{
		std::cout << "������� �����:\n";
		std::cin >> choosedOption;
		if (std::cin.fail() || choosedOption > 2 || choosedOption < 1)
		{
			isError = true;
			std::cout << "������ ������� ����� �� 1 �� 2\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			continue;
		}
		isError = false;
	} while (isError);
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	
	if (choosedOption == 2)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				matrix[i][j] = rand() % 50;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				do
				{
					std::cout << "������� (" << (i+1) << "," << (j+1) << ") -> ";
					std::cin >> choosedOption;
					
					if (std::cin.fail())
					{
						isError = true;
						std::cout << "������ ������� ����� �����\n";
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());
						continue;
					}
					isError = false;
				} while (isError);
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				matrix[i][j] = choosedOption;
			}
		}
	}
}

void destructMatrix(int **matrix, int n, int m)  //�������� ���������� ������ ��� ������� n*m
{
	for (int i = 0; i < n; ++i)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}

int** constructMatrix(int n, int m)  //��������� ������ ��� ������� n*m
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[m];
	}
	return matrix;
}

void printMatrix(int** matrix, int n, int m)  //����� ������� �� �����
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}


int** transpMatrix(int** matrix, int &n, int &m) 
{
	int** tMatrix = constructMatrix(n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			tMatrix[i][j] = matrix[i][j];
		}
	}
	destructMatrix(matrix, n, m);
	
	matrix = constructMatrix(m, n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			matrix[j][i] = tMatrix[i][j];
		}
	}
	destructMatrix(tMatrix, n, m);
	
	int q;
	q = m;
	m = n;
	n = q;
	//n*m -> m*n
	
	return matrix;
}

int** sumMatrix(int** matrix, int n, int m)
{
	int** matrix2 = constructMatrix(n, m);
	fillMatrix(matrix2, n, m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			matrix[i][j] = matrix[i][j] + matrix2[i][j];
		}
	}

	destructMatrix(matrix2, n, m);

	return matrix;
}

int** multiplicationMatrix(int** matrix, int &n, int &m)
{
	int nMulti, mMulti, n2, m2;
	bool isError = false;
	do
	{
		std::cout << "������� ������ ������� �� ������� ������ ��������:\n";
		std::cin >> n2 >> m2;
		if (std::cin.fail() || (m != n2))
		{
			isError = true;
			std::cout << "������ ������� ������� ��������� ��� ��������� �� �������� �������\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			continue;
		}
		isError = false;
	} while (isError);
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	
	
	int** matrix2 = constructMatrix(n2, m2);
	fillMatrix(matrix2, n2, m2);
	printMatrix(matrix2, n2, m2);
	mMulti = n;
	nMulti = m2;
	
	int** matrixMulti = constructMatrix(nMulti, mMulti);
	
	for (int i = 0; i < nMulti; ++i)
	{
		for (int j = 0; j < mMulti; ++j)
		{
			
			matrixMulti[i][j] = 0;
		}
	}

	for (int i = 0; i < nMulti; ++i)
	{
		for (int j = 0; j < mMulti; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				matrixMulti[i][j] += (matrix[i][k]*matrix2[k][j]);
			}
		}
	}


	destructMatrix(matrix, n, m);
	destructMatrix(matrix2, n, m);

	
	n = nMulti;
	m = mMulti;

	return matrixMulti;
}

void initMatrix()
{
	int n, m;
	bool isError = false;
	do
	{
		std::cout << "������� ������� ������� n, m: \n";
		std::cin >> n >> m;
		
		if (std::cin.fail())
		{
			isError = true;
			std::cout << "������ ������� ����� �����\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			continue;
		}
		isError = false;
	} while (isError);
	std::cin.ignore(std::cin.rdbuf()->in_avail());


	int** matrix1 = constructMatrix(n, m);
	fillMatrix(matrix1, n, m);
	printMatrix(matrix1, n, m);

	std::cout << "1)��������������� �������\n";
	std::cout << "2)������� � ��������\n";
	std::cout << "3)�������� �� �������\n";
	std::cout << "0)��������� ���������\n";

	int choosedOption;
	do
	{
		std::cout << "������� ����� :\n";
		std::cin >> choosedOption;

		
		if (std::cin.fail())
		{
			isError = true;
			std::cout << "������ ������� ����� ����� �� 0 �� 3\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			continue;
		}
		isError = false;
	} while (isError);
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	switch (choosedOption)
	{
	case 0:
		break;
	case 1:
		std::cout << "����������������� �������:\n";
		matrix1 = transpMatrix(matrix1, n, m);
		printMatrix(matrix1, n, m);
		break;
	case 2:
		std::cout << "����� ������\n";
		matrix1 = sumMatrix(matrix1, n, m);
		printMatrix(matrix1, n, m);
		break;
	case 3:
		std::cout << "������������ ������\n";
		matrix1 = multiplicationMatrix(matrix1, n, m);
		printMatrix(matrix1, n, m);
		break;
	}

	destructMatrix(matrix1, n, m);
}
