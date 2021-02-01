#include <iostream>
#include <string>
#include <Windows.h>

const char lettersArr[] =
{
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z',
    'x', 'c', 'v', 'b', 'n', 'm', 'й', 'ц', 'у', 'к',
    'е', 'н', 'г', 'ш', 'щ', 'з', 'х', 'ъ', 'ф', 'ы',
    'в', 'а', 'п', 'р', 'о', 'л', 'д', 'ж', 'э', 'я',
    'ч', 'с', 'м', 'и', 'т', 'ь', 'б', 'ю'
};

const char numbersArr[] =
{
    '0','1','2','3','4','5','6','7','8','9'
};

bool checkForNumber(char c)
{
    for (int i = 0; i < 10; ++i)
    {
        if (c == numbersArr[i])
            return true;
    }
    return false;      
}

bool checkForLetter(char c)
{
    for (int i = 0; i < 58; ++i)
    {
        if (c == lettersArr[i])
            return true;
    }
    return false;
}

bool recurseFunction(std::string& stringToCheck, int i)
{
    switch (i)
    {
    case 0:
        if (checkForNumber(stringToCheck[i]) || checkForLetter(stringToCheck[i]))
            return true;
        else
            return false;
    default:
        if ((checkForNumber(stringToCheck[i]) && checkForLetter(stringToCheck[(i - 1)])) ||
            (checkForLetter(stringToCheck[i]) && checkForNumber(stringToCheck[(i - 1)])))

            return recurseFunction(stringToCheck, i - 1);

        else
            return false;
    }
}

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string stringToCheck;
    do
    {
        std::cout << "Введите строку:\n";
        std::getline(std::cin, stringToCheck);
    } 
    while (stringToCheck.empty());
    
    if (recurseFunction(stringToCheck, stringToCheck.size() - 1))
        std::cout << "В строке чередуются цифры и буквы\n";
    else
        std::cout << "Цифры и буквы в строке не чередуются\n";
    
    return 0;
}


