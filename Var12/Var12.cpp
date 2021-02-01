#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>

int getRandomValue()
{
    return rand() % 51 - 25;
}

void printArray(int extArray[], int size)
{
    std::cout.setf(std::ios::right);                      // для удобочитаемости зададим выравнивание по правому краю
    for (int i = 0; i < size; ++i)
    {
        std::cout << std::setw(5) << extArray[i] << ' ';  // а также фиксированную длину поля
        if ((i + 1) % 5 == 0)                             // и через каждые 5 элементов
            std::cout << '\n';                            // переход на следующую строку
    }
}

int main()
{
    // переключение кодировки позволит корректно работать с русскими
    // символами
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // инициализация рандомизации чисел
    srand(static_cast<unsigned int>(time(0)));
    
    const int arrayLength= 90;
    int unsortedArray[arrayLength];

    for (int i = 0; i < arrayLength; ++i)
    {
        unsortedArray[i] = getRandomValue();
    }

    printArray(unsortedArray, arrayLength);
    std::cout << '\n';

    int d = (arrayLength / 2);
    int j, elem;
    while (d > 0)
    {
        for (int i = 0; i < arrayLength - d; ++i)
        {
            j = i;
            while (j >= 0 && unsortedArray[j] < unsortedArray[j + d])
            {
                elem = unsortedArray[j];
                unsortedArray[j] = unsortedArray[j + d];
                unsortedArray[j + d] = elem;
                j--;
            }

        }
        d = d / 2;
    }

    printArray(unsortedArray, arrayLength);

    return 0;
}
