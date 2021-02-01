#include <iostream>
#include <string>
#include <Windows.h>

char checkSymbol(char c)
{
    switch (c)
    {
    case 'Q': return 'Й'; case 'q': return 'й';
    case 'W': return 'Ц'; case 'w': return 'ц';
    case 'E': return 'У'; case 'e': return 'у';
    case 'R': return 'К'; case 'r': return 'к';
    case 'T': return 'Е'; case 't': return 'е';
    case 'Y': return 'Н'; case 'y': return 'н';
    case 'U': return 'Г'; case 'u': return 'г';
    case 'I': return 'Ш'; case 'i': return 'ш';
    case 'O': return 'Щ'; case 'o': return 'щ';
    case 'P': return 'З'; case 'p': return 'з';
    case '{': return 'Х'; case '[': return 'х';
    case '}': return 'Ъ'; case ']': return 'ъ';
    case 'A': return 'Ф'; case 'a': return 'ф';
    case 'S': return 'Ы'; case 's': return 'ы';
    case 'D': return 'В'; case 'd': return 'в';
    case 'F': return 'А'; case 'f': return 'а';
    case 'G': return 'П'; case 'g': return 'п';
    case 'H': return 'Р'; case 'h': return 'р';
    case 'J': return 'О'; case 'j': return 'о';
    case 'K': return 'Л'; case 'k': return 'л';
    case 'L': return 'Д'; case 'l': return 'д';
    case ':': return 'Ж'; case ';': return 'ж';
    case '"': return 'Э'; case '\'': return 'э';
    case 'Z': return 'Я'; case 'z': return 'я';
    case 'X': return 'Ч'; case 'x': return 'ч';
    case 'C': return 'С'; case 'c': return 'с';
    case 'V': return 'М'; case 'v': return 'м';
    case 'B': return 'И'; case 'b': return 'и';
    case 'N': return 'Т'; case 'n': return 'т';
    case 'M': return 'Ь'; case 'm': return 'ь';
    case '<': return 'Б'; case ',': return 'б';
    case '>': return 'Ю'; case '.': return 'ю';
    default: return c;
    }
}

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string stringToCheck;

    std::cout << "Введите строку\n";
    std::getline(std::cin, stringToCheck);

    for (int i = 0; i < stringToCheck.size(); ++i)
        stringToCheck[i] = checkSymbol(stringToCheck[i]);

    std::cout << "Исходная строка:\n" << stringToCheck << '\n';

    return 0;
}