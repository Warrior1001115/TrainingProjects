#include <iostream>
#include <Windows.h>
#include <math.h>

double calcFunction(double x)
{
    return pow(x, 2) - 2;
}

double calcX(double st, double fin)
{
    return st - (calcFunction(st) / (calcFunction(fin) - calcFunction(st))) * (fin - st);
}

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    double st, fin, eps, x, oldX;
    do
    {
        std::cout << "Введите начальное значение, конечное значение и точность\n";
        std::cout << "Обратите внимание, что знак функции на концах отрезка должен быть разным\n";
        std::cin >> st >> fin >> eps;

    } while ((calcFunction(st) * calcFunction(fin)) >= 0);

    x = calcX(st, fin);
    do
    {
        if ((calcFunction(st) * calcFunction(x)) < 0)
            fin = x;
        else if ((calcFunction(fin) * calcFunction(x)) < 0)
            st = x;

        oldX = x;
        x = calcX(st, fin);

    } while (abs(oldX - x) > eps);

    std::cout.setf(std::ios::fixed);
    std::cout.precision(10);
    std::cout << "Искомый корень с точностью " << eps << ": " << x << '\n';
    std::cout << "Значение функции в корне: " << calcFunction(x) << '\n';

    return 0;
}
