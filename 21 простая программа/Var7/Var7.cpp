#include <iostream>
#include <Windows.h>
#include <cmath>

double calcFunction(double S, double n, double x)
{
    return ((pow((x + 1), n) - 1)/x - S);
}

int main()
{
    // устанавливаем кодировку для работы с русскими символами
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double S, n, r, r1, r2, e;

    // устанавливаем количество символов после запятой, выводимых программой
    std::cout.setf(std::ios::fixed);
    std::cout.precision(10);

    std::cout << "Введите S\n";
    std::cin >> S;
    std::cout << "Введите n\n";
    std::cin >> n;
    std::cout << "Введите требуемую точность\n";
    std::cin >> e;
    
    // используем метод деления пополам
    r1 = 0.0001;
    r2 = 1000;
    r = (r2 - r1) / 2;
    if (calcFunction(S, n, r1) * calcFunction(S, n, r2) <= 0)
    {
        do
        {
            if (calcFunction(S, n, r1) * calcFunction(S, n, r) <= 0)
               r2 = r;
            else
               r1 = r;
            r = (r2 + r1) / 2;
        } while (abs(r1 - r2) >= e);
        std::cout << "Норма процента: " << r << '\n';
    }
    else
    {
        std::cout << "Корней в интервале от 0.0001 до 1000 не обнаружено, либо не существует единственного корня\n";
    } 
    
    return 0;
}
