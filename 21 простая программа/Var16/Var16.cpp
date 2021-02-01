#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

const unsigned int ARR_SIZE = 10;
const double DATA_MIN = -100.0;
const double DATA_MAX = 200.0;
const double EPS = 0.0000000001;

double getRandomNumber()
{
    return static_cast<double>(rand()) / RAND_MAX * (DATA_MAX - DATA_MIN) + DATA_MIN;
}

void printArray(double arrayOfNumbers[ARR_SIZE][ARR_SIZE])
{
    std::cout.setf(std::ios::fixed | std::ios::left);
    std::cout.precision(10);
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        for (int j = 0; j < ARR_SIZE; ++j)
            std::cout << std::setw(16) << arrayOfNumbers[i][j];
        std::cout << '\n';
    }
}

int main() 
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(NULL)));

    double arrayOfNumbers[ARR_SIZE][ARR_SIZE];

    for (int i = 0; i < ARR_SIZE; ++i)
    {
        for (int j = 0; j < ARR_SIZE; ++j)
            arrayOfNumbers[i][j] = getRandomNumber();
    }

    printArray(arrayOfNumbers);

    double numberToFind;
    int x, y;
    bool fl = false;

    std::cout << "Введите число:\n";
    std::cin >> numberToFind;

    for (int i = 0; i < ARR_SIZE; ++i)
    {
        for (int j = 0; j < ARR_SIZE; ++j)
        {
            // если числа не отличаются больше, чем на EPS, считаем, что они равны
            if (abs(arrayOfNumbers[i][j] - numberToFind) < EPS)
            {
                x = i;
                y = j;
                fl = true;
                break;
            }
        }
        if (fl)
            break;
    } 

    if (fl)
        std::cout << "Координаты числа в массиве: " << ++x << ',' << ++y << ".\n";
    else
        std::cout << "Число не найдено";

    return 0;
}