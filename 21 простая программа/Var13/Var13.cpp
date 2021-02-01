#include <iostream>
#include <iomanip>
#include <Windows.h>

const int maxValue = 20;

void printMatrix(double matrix[maxValue][maxValue + 1], int ecNumber, int varNumber)
{
    std::cout << "Cистема имеет вид:\n";
    std::cout.setf(std::ios::right);
    for (int i = 0; i < ecNumber; ++i)
    {
        for (int j = 0; j < varNumber + 1; ++j)
        {
            if (j == varNumber)
                std::cout << '|';
            std::cout << std::setw(5) << matrix[i][j] << ' ';
        }
        std::cout <<  '\n';
    }
}

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int ecNumber, varNumber;
    double matrix[maxValue][maxValue + 1];

    std::cout << "Введите количество уравнений в системе (не больше 20):\n";
    std::cin >> ecNumber;

    std::cout << "Введите количество переменных в уравнениях (не больше 20):\n";
    std::cin >> varNumber;

    for (int i = 0; i < ecNumber; ++i)
    {
        std::cout << "Введите коэффициенты и свободный член уравнения №" << (i + 1) << ":\n";
        for (int j = 0; j < varNumber + 1; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    printMatrix(matrix, ecNumber, varNumber);

    if (varNumber > ecNumber)
        std::cout << "Cистема либо несовместна, либо имеет бесконечно много решений\n";

    double maxEl, elemToSwap, firstElem;
    int maxElIndex;

    // для каждого столбца
    for (int j = 0; j < varNumber; ++j)
    {
        maxEl = matrix[j][j];
        maxElIndex = j;

        // ищем в столбце максимальный элемент
        for (int i = j; i < ecNumber; ++i)
        {
            if (matrix[i][j] > maxEl)
            {
                maxEl = matrix[i][j];
                maxElIndex = i;
            }
        }

        // перемещаем строку с максимальным элементом наверх
        for (int i = 0; i < varNumber + 1; ++i)
        {
            elemToSwap = matrix[maxElIndex][i];
            matrix[maxElIndex][i] = matrix[j][i];
            matrix[j][i] = elemToSwap;
        }

        // нормализуем 
        for (int y = j; y < ecNumber; ++y)
        {
            if (matrix[y][j] == 0.0)
                continue;
            else
                firstElem = matrix[y][j];
            for (int i = j; i < varNumber + 1; ++i)
            {
                if (matrix[y][i] == 0.0)
                    continue;
                else
                    matrix[y][i] = matrix[y][i] / firstElem;
            }
        }

        // вычитаем строку
        for (int y = j + 1; y < ecNumber; ++y)
        {
            for (int i = j; i < varNumber + 1; ++i)
            {

                // если результат вычитания меньше 1.0e-12 - округляем до 0
                if (abs(matrix[y][i] - matrix[j][i]) > (1.0e-12))
                    matrix[y][i] = matrix[y][i] - matrix[j][i];
                else
                    matrix[y][i] = 0.0;
            }
        }
   
    }

    printMatrix(matrix, ecNumber, varNumber);

    bool isFound = false;
    double resultVector[maxValue];
    double sum;

    if (matrix[ecNumber - 1][varNumber - 1] != 0.0)
    {
        resultVector[varNumber - 1] = matrix[ecNumber - 1][varNumber];
        for (int i = 1; i < ecNumber; ++i)
        {
            sum = 0;
            for (int j = varNumber - 1; j > ecNumber - 1 - i; --j)
                sum = sum + matrix[ecNumber - 1 - i][j] * resultVector[j];
            resultVector[varNumber - 1 - i] = matrix[ecNumber - 1 - i][varNumber] - sum;
        }

        std::cout << "Результирующий вектор:\n[";
        for (int i = 0; i < varNumber; ++i)
        {
            std::cout << resultVector[i];
            if (i != varNumber - 1)
                std::cout << ", ";
        }
        std::cout << "]\n";

    }
    else if (matrix[ecNumber][varNumber + 1] != 0.0)
        std::cout << "Cистема несовместна\n";

    return 0;
}
