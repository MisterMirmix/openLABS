#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>

void fillMatrix(int** matrix, int n, int m);

void destructMatrix(int** matrix, int n, int m);

int** constructMatrix(int n, int m);

void printMatrix(int** matrix, int n, int m);

int* findMinOfRow(int** matrix, int m, int n);

int* findPlusColoumn(int** matrix, int m, int n);

int** taskMatrix(int** matrix, int m, int &n, int* foundRow, int* rowMin);


