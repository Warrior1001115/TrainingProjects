#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <math.h>

int widthIs(double accuracy) // не было
{
    int res = 6;
    while (accuracy < 1)
    {
        accuracy *= 10;
        ++res;
    }
    return res;
}

int precisionIs(double accuracy) // не было
{
    int res = 2;
    while (accuracy < 1)
    {
        accuracy *= 10;
        ++res;
    }
    return res;
}

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double startX, stopX, step, accuracy;

    std::cout << "Введите начальное х (в радианах): ";
    std::cin >> startX;
    std::cout << "Введите конечное х (в радианах): ";
    std::cin >> stopX;
    std::cout << "Введите шаг h: ";
    std::cin >> step;
    std::cout << "Введите точность e: ";
    std::cin >> accuracy;

    double elem, sum, index;
    int iter;

    std::cout.setf(std::ios::fixed | std::ios::left);
    std::cout.precision(precisionIs(accuracy)); // было 8
    int width = widthIs(accuracy);// было 14
    std::cout << std::setw(width) << "x" << std::setw(width) << "y" << std::endl;

    for (double x = startX;x <= stopX; x += step)
    {
        sum = 0.0;
        index = 1.0;
        iter = 1;
        elem = x;
        while (abs(elem) > accuracy)
        {
            sum += elem;
            index *= (2 * static_cast<double>(iter) - 1) / (2 * static_cast<double>(iter));
            elem = index * (pow(x, (2 * static_cast<double>(iter) + 1)) / (2 * static_cast<double>(iter) + 1));
            ++iter;
        }
        std::cout << std::setw(width) << x << std::setw(width) << sum << '\n';
    }
    return 0;
}
