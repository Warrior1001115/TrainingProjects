#include <iostream>
#include <Windows.h>
#include <ctime>
#include <iomanip>

const double max_rand = 10.0;
const double min_rand = -10.0;
const double eps = 0.000001;     // числа, разница между которыми меньше eps
                                 // будут считаться одинаковыми

double getRandomNumber()
{
    return static_cast<double>(rand()) / RAND_MAX * (max_rand - min_rand) + min_rand;
}

void initializeArr(double* arr, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        arr[i] = getRandomNumber();
    }
}

void printArr(double* arr, unsigned int size)
{
    std::cout.setf(std::ios::right | std::ios::fixed);
    std::cout.precision(7);
    for (unsigned int i = 0; i < size; ++i)
    {
        std::cout << std::setw(13) << arr[i];
    }
    std::cout << std::endl;
}

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(NULL)));

    unsigned int fArrSize, sArrSize;

    std::cout << "Введите длину первого и второго массива через пробел:\n";
    std::cin >> fArrSize >> sArrSize;

    double *fArr = new double[fArrSize];
    double *sArr = new double[sArrSize];

    initializeArr(fArr, fArrSize);
    initializeArr(sArr, sArrSize);

    std::cout << "Первый массив:\n";
    printArr(fArr, fArrSize); 

    std::cout << "Второй массив:\n";
    printArr(sArr, sArrSize);

    unsigned int countOfSameNums = 0;
    double *checkedNums;

    if (fArrSize > sArrSize)
        checkedNums = new double[fArrSize];
    else
        checkedNums = new double[sArrSize];

    for (unsigned int i = 0; i < fArrSize; ++i)
    {
        for (unsigned int j = 0; j < sArrSize; ++j)
        {
            // если разность чисел меньше eps - считаем их равными
            if (abs(fArr[i] - sArr[j]) < eps)
            {
                bool fl = true;
                for (unsigned int y = 0; y < countOfSameNums; ++y)
                {
                    if (abs(sArr[j] - checkedNums[countOfSameNums]) < eps)
                    {
                        fl = false;
                        break;
                    }
                }

                if (fl)
                {
                    ++countOfSameNums;
                    checkedNums[countOfSameNums - 1] = sArr[j];
                    std::cout << "Найден совпадающий элемент:\n" << 
                        std::setw(13) << sArr[j] << " совпал с " << std::setw(13) << fArr[i] <<'\n';
                }
            }
        }
    }

    std::cout << "Всего найдено " << countOfSameNums << " совпадающих элементов.\n";

    delete[] fArr;
    delete[] sArr;
    delete[] checkedNums;

    return 0;
}
