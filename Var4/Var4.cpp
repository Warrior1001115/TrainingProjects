#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int getRandomValue()
{
    return rand() % 100 + 1;
}

void initializeArr(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        arr[i] = getRandomValue();
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << std::endl;
}

int main()
{
    // переключение кодировки позволит корректно работать с русскими символами
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // инициализация рандомизации чисел
    srand(static_cast<unsigned int>(time(0)));

    int arraySize = 100;

    int unsortedArr[100];

    //инициализация и печать несортированного массива
    initializeArr(unsortedArr, arraySize);
    printArr(unsortedArr, arraySize);
    std::cout << std::endl;

    //сортировка вставками
    for (int i = 1; i < arraySize; ++i)
    {
        int elem = unsortedArr[i];
        int j = i;
        while (j > 0 && unsortedArr[j - 1] > elem)
        {
            unsortedArr[j] = unsortedArr[j - 1];
            --j;
        }
        unsortedArr[j] = elem;
    }
    //печать отсортированного массива
    printArr(unsortedArr, arraySize);

    return 0;
}
