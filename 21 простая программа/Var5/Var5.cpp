#include <iostream>
#include <ctime>
#include <Windows.h>

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << std::endl;
    std::cout << std::endl;
}

bool checkForSimple(int number)
{
    for (int j = 2; j <= sqrt(number); ++j)
        if (number % j == 0)
        {
            return false;
        }
    return true;
}

int main()
{
    // переключение кодировки позволит корректно работать с русскими
    // символами
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // инициализация рандомизации чисел
    srand(static_cast<unsigned int>(time(0)));

    int simpleInt[90];
    int simpleCount = 0;

    for (int number = 10; number <= 100; ++number)
    {
        if (checkForSimple(number))
        {
            simpleInt[simpleCount] = number;
            ++simpleCount;
        }
    }
    printArr(simpleInt, simpleCount);
    std::cout << "Было найдено " << simpleCount << " простых чисел" << std::endl;

    // произведение 2 случайных чисел и проверка
    int randNumA = simpleInt[rand() % simpleCount];
    int randNumB = simpleInt[rand() % simpleCount];
    std::cout << "Результат произведения простых чисел " << randNumA << " и " << randNumB << std::endl;
    if (checkForSimple(randNumA * randNumB)) 
        std::cout << "является простым числом." << std::endl;
    else
        std::cout << "не является простым числом." << std::endl;

    return 0;
}
