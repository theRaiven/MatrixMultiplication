// MatrixMultiplication.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

void MultiplyTransport(int const sizeMatrixs);
void MultiplyStandart(int const sizeMatrixs);

auto Multiply = [](auto firstMatrix, auto secondMatrix, auto multiplyMatrix, int sizeMatrixs)
{
    for (int i = 0; i < sizeMatrixs; i++)
    {
        for (int j = 0; j < sizeMatrixs; j++)
        {
            for (int k = 0; k < sizeMatrixs; k++)
            {
                multiplyMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
};
auto Transpose = [](auto secondMatrix, int sizeMatrixs)
{
    for (int i = 0; i < sizeMatrixs; i++)
    {
        for (int j = i; j < sizeMatrixs; j++)
        {
            int temp = move(secondMatrix[i][j]);
            secondMatrix[i][j] = move(secondMatrix[j][i]);
            secondMatrix[j][i] = move(temp);
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "\t***Стандартная***" << endl;
    MultiplyStandart(200);
    MultiplyStandart(400);
    MultiplyStandart(800);
    MultiplyStandart(1600);
    MultiplyStandart(2000);
    cout << endl << "\t***Транспонированная***" << endl;
    MultiplyTransport(200);
    MultiplyTransport(400);
    MultiplyTransport(800);
    MultiplyTransport(1600);
    MultiplyTransport(2000);
}

void MultiplyStandart(int const sizeMatrixs)
{
    vector<vector<int>> firstMatrix;
    vector<vector<int>> secondMatrix;
    vector<vector<int>> multiplyMatrix;

    firstMatrix.reserve(sizeMatrixs);
    secondMatrix.reserve(sizeMatrixs);
    multiplyMatrix.reserve(sizeMatrixs);

    for (int i = 0; i < sizeMatrixs; ++i) 
    {
        firstMatrix.emplace_back(sizeMatrixs, rand() % 100);
        secondMatrix.emplace_back(sizeMatrixs, rand() % 100);
        multiplyMatrix.emplace_back(sizeMatrixs, 0);
    }

    

    auto start{ chrono::high_resolution_clock::now() };

    Multiply(firstMatrix, secondMatrix, multiplyMatrix, sizeMatrixs);

    auto end{ chrono::high_resolution_clock::now() };
    chrono::duration<double> duration = end - start;

    cout << "Время выполнения: " << duration.count() << " секунд" << endl;
}

void MultiplyTransport(int const sizeMatrixs)
{
    vector<vector<int>> firstMatrix;
    vector<vector<int>> secondMatrix;
    vector<vector<int>> multiplyMatrix;

    firstMatrix.reserve(sizeMatrixs);
    secondMatrix.reserve(sizeMatrixs);
    multiplyMatrix.reserve(sizeMatrixs);

    for (int i = 0; i < sizeMatrixs; ++i)
    {
        firstMatrix.emplace_back(sizeMatrixs, rand() % 100);
        secondMatrix.emplace_back(sizeMatrixs, rand() % 100);
        multiplyMatrix.emplace_back(sizeMatrixs, 0);
    }

    Transpose(secondMatrix, sizeMatrixs);

    auto start{ chrono::high_resolution_clock::now() };

    Multiply(firstMatrix, secondMatrix, multiplyMatrix, sizeMatrixs);

    auto end{ chrono::high_resolution_clock::now() };
    chrono::duration<double> duration = end - start;

    cout << "Время выполнения: " << duration.count() << " секунд" << endl;
}


