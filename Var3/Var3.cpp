#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int getRandomValue()
{
    return rand() % 22 + 3;
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
    int repeatCounter = arraySize;
    
    int unsortedArr[100];
    
    //инициализация и печать несортированного массива
    initializeArr(unsortedArr, arraySize);
    printArr(unsortedArr, arraySize);
    std::cout << std::endl;

    //сортировка пузырьком с удалением повторов
    for (int j = 0; j + 1 < repeatCounter; j++)
    {
        for (int i = 0; i + 1 < arraySize - j; i++)
        {
            if (unsortedArr[i] > unsortedArr[i + 1])
            {
                int elem = unsortedArr[i];
                unsortedArr[i] = unsortedArr[i + 1];
                unsortedArr[i + 1] = elem;
            }

            //сдвигаем весь массив, тем самым устраняя повтор
            if (unsortedArr[i] == unsortedArr[i + 1])
            {
                for (int y = i; y < (arraySize - 1); y++)
                    unsortedArr[y] = unsortedArr[y + 1];
                //необходимо учесть уменьшение элементов и сдвиг массива
                --arraySize;
                --i;
            }
        }
    }

    //массив отсортирован
    printArr(unsortedArr, arraySize);

    return 0;
}

