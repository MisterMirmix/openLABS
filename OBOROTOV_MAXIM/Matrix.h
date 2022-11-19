#pragma once
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>

void fillMatrix(int** matrix, int n, int m);

void destructMatrix(int  **matrix, int n, int m);

int** constructMatrix(int n, int m);

void printMatrix(int** matrix, int n, int m);

int** transpMatrix(int** matrix, int& n, int& m);

int** sumMatrix(int** matrix, int n, int m);

int** multiplicationMatrix(int** matrix, int &n, int &m);

void initMatrix();