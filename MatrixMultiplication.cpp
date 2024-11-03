// MatrixMultiplication.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
using namespace std;

void MultiplyTransport(int const sizeMatrixs);
void MultiplyStandart(int const sizeMatrixs);


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

void MultiplyTransport(int const sizeMatrixs)
{
    int** firstMatrix{ new int* [sizeMatrixs] };
    int** secondMatrix{ new int* [sizeMatrixs] };
    int** multiplyMatrix{ new int* [sizeMatrixs] };

    for (int i = 0; i < sizeMatrixs; i++)
    {
        firstMatrix[i] = new int[sizeMatrixs];
        secondMatrix[i] = new int[sizeMatrixs];
        multiplyMatrix[i] = new int[sizeMatrixs];

        for (int j = 0; j < sizeMatrixs; j++)
        {
            firstMatrix[i][j] = rand() % 100;
            secondMatrix[i][j] = rand() % 100;
            multiplyMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < sizeMatrixs; i++)
    {
        for (int j = i; j < sizeMatrixs; j++)
        {
            int temp = move(secondMatrix[i][j]);
            secondMatrix[i][j] = move(secondMatrix[j][i]);
            secondMatrix[j][i] = move(temp);
        }
    }

    auto start{ std::chrono::high_resolution_clock::now() };
    for (int i = 0; i < sizeMatrixs; i++)
    {
        for (int j = 0; j < sizeMatrixs; j++)
        {
            for (int k = 0; k < sizeMatrixs; k++)
            {
                multiplyMatrix[i][j] += firstMatrix[i][k] * secondMatrix[j][k];
            }
        }
    }
    auto end{ std::chrono::high_resolution_clock::now() };
    std::chrono::duration<double> duration = end - start;

    std::cout << "Время выполнения: " << duration.count() << " секунд" << std::endl;
}
void MultiplyStandart(int const sizeMatrixs)
{
    int** firstMatrix{ new int* [sizeMatrixs] };
    int** secondMatrix{ new int* [sizeMatrixs] };
    int** multiplyMatrix{ new int* [sizeMatrixs] };

    for (int i = 0; i < sizeMatrixs; i++)
    {
        firstMatrix[i] = new int[sizeMatrixs];
        secondMatrix[i] = new int[sizeMatrixs];
        multiplyMatrix[i] = new int[sizeMatrixs];

        for (int j = 0; j < sizeMatrixs; j++)
        {
            firstMatrix[i][j] = rand() % 100;
            secondMatrix[i][j] = rand() % 100;
            multiplyMatrix[i][j] = 0;
        }
    }

    auto start{ chrono::high_resolution_clock::now() };
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
    auto end{ chrono::high_resolution_clock::now() };
    chrono::duration<double> duration = end - start;

    cout << "Время выполнения: " << duration.count() << " секунд" << endl;
}