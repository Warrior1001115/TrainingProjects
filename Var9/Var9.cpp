#include <iostream>
#include <string>
#include <Windows.h>

void changeString(std::string& stringToChange)
{
    for (int i = 5; i < stringToChange.size(); i += 6)
    {
        stringToChange.insert(i, 1, ' ');
    }
}

int main()
{
    // переключение кодировки для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string stringToChange;
    std::cout << "Введите строку\n";
    
    std::getline(std::cin, stringToChange);

    changeString(stringToChange);

    std::cout << "Изменённая строка:\n" << stringToChange << std::endl;

    return 0;
}
