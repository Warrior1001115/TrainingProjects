#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

struct listElem
{
    double value;
    listElem* next;
};

double getRandomValue() // генерируются числа от -10000.0 до 10000.0
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return  rand() * fraction * 20000.0 - 10000.0;
}

listElem* createStartElem()
{
    listElem* first;
    first = (listElem*)malloc(sizeof(listElem));
    first->value = getRandomValue();
    first->next = NULL;
    return first;
}

listElem* createNextElem(listElem* elem)
{
    listElem *newElem;
    newElem = (listElem*)malloc(sizeof(listElem));
    newElem->next = elem->next;
    newElem->value = getRandomValue();
    elem->next = newElem;
    return newElem;
}

int main()
{
    // переключение кодировки позволит корректно работать с русскими символами,
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // инициализация рандомизации чисел
    srand(static_cast<unsigned int>(time(0)));

    int listLength;
    do
    {
        std::cout << "Введите длину списка, для корректного сравнения число должно быть чётным" << std::endl;
        std::cin >> listLength;
    } while (listLength % 2 != 0);

    listElem* firstElem = createStartElem();
    listElem* elem = firstElem;

    for (int i = 1; i < listLength/2 + 1; i++)
    {
        elem = createNextElem(elem);
    }

    listElem* secondPartfirstElem = elem;

    for (int i = 0; i < listLength / 2 - 1; i++)
    {
        elem = createNextElem(elem);
    }

    bool isPartsEqual = true;
    for (int i = 0; i < listLength / 2 - 1; i++)
    {
        if (firstElem->value != secondPartfirstElem->value)
        {
            isPartsEqual = false;
        }
        firstElem = firstElem->next;
        secondPartfirstElem = secondPartfirstElem->next;
    }

    if (isPartsEqual)
        std::cout << "Значения половин списка совпадают" << std::endl;
    else
        std::cout << "Значения половин списка не совпадают" << std::endl;
    return 0;
}
