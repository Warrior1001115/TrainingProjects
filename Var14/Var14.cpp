#include <iostream>
#include <string>
#include <Windows.h>

char numbers[] = { '1','2','3','4','5','6','7','8','9','0' };
char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
                   'n','o','p','q','r','s','t','u','v','w','x','y','z',
                   'а','б','в','г','д','е','ё','ж','з','и','й','к','л',
                   'м','н','о','п','р','с','т','у','ф','х','ц','ч','ш',
                   'щ','ъ','ы','ь','э','ю','я' };

bool checkForNumber(char c)
{
    for (int i = 0; i < 10; ++i)
    {
        if (c == numbers[i])
            return true;
    }
    return false;
}

bool checkForLetter(char c)
{
    for (int i = 0; i < 59; ++i)
    {
        if (c == letters[i])
            return true;
    }
    return false;
}

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string stringToCheck;
    std::cout << "Введите строку\n";
    std::getline(std::cin, stringToCheck);
    
    bool flag = true;

    if (checkForLetter(stringToCheck[0]))
        for (int i = 1; i < 10; ++i)
        {
            if (i % 2 == 1)
                flag = checkForNumber(stringToCheck[i]);
            else
                flag = checkForLetter(stringToCheck[i]);
            if (!flag)
                break;
        }
    else if (checkForNumber(stringToCheck[0]))
        for (int i = 1; i < 10; ++i)
        {
            if (i % 2 == 1)
                flag = checkForLetter(stringToCheck[i]);
            else
                flag = checkForNumber(stringToCheck[i]);
            if (!flag)
                break;
        }
    else
        flag = false;

    if (flag)
        std::cout << "В строке чередуются цифры и буквы\n";
    else
        std::cout << "В строке цифры и буквы не чередуются\n";

    return 0;
}
