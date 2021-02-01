#include <iostream>
#include <Windows.h>
#include <ctime>
#include <iomanip>

const int max_ran = 10;
const int min_ran = -10;

int getRandomNumber()
{
    return static_cast<int>(static_cast<double>(rand()) / RAND_MAX * (max_ran - min_ran) + min_ran);
}

void printArr(int** arr, unsigned int x, unsigned int y)
{
    std::cout.setf(std::ios::right);
    for (unsigned int i = 0; i < x; ++i)
    {
        for (unsigned int j = 0; j < y; ++j)
            std::cout << std::setw(4) << arr[i][j];
        std::cout << '\n';
    }
}

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(NULL)));

    unsigned int x, y;

    std::cout << "Введите размер двумерного массива через пробел:\n";
    std::cin >> x >> y;

    int** arr = new int* [x];

    for (unsigned int i = 0; i < x; ++i)
        arr[i] = new int[y];

    for (unsigned int i = 0; i < x; ++i)
    {
        for (unsigned int j = 0; j < y; ++j)
            arr[i][j] = getRandomNumber();
    }

    printArr(arr, x, y);
    std::cout << '\n';

    for (unsigned int i = 0; i < x; ++i)
    {
        for (unsigned int j = 0; j < y; j += 2)
            if (arr[i][j] < 0)
                arr[i][j] = 0;
    }

    printArr(arr, x, y);

    return 0;
}
