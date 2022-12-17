//в матрице столбцы с положительными суммами элементов,
//а затем в качестве первого вставьте столбец из минимальных элементов соответсвующих строк
//
#include "Header.h"

int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, m;
    std::cout << "Введите размеры матрицы\n";
    std::cin >> m >> n;
    int** matrix = constructMatrix(m, n);
    fillMatrix(matrix, m, n);
    printMatrix(matrix, m, n);
    int* rowMin = findMinOfRow(matrix, m, n);
    int* foundRow = findPlusColoumn(matrix, m, n);
    matrix = taskMatrix(matrix, m, n, foundRow, rowMin);
    std::cout << "Новая матрица\n";
    printMatrix(matrix, m, n);
    delete[] rowMin;
    delete[] foundRow;
  
    destructMatrix(matrix, m, n);
    return 0;
}

