#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <limits>
#include <sstream>

// во избежание конфликта имён не будем использовать max
// из библиотеки <Windows.h>
#ifdef max
#undef max
#endif

std::string getFileName()
{
    std::string fileName;
    std::cout << "Введите название файла, в котором требуется перезаписать информацию:\n";
    std::getline(std::cin, fileName);
    return fileName;
}

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int com;

    std::cout << "Команды:\n1. Read - открывает файл по названию\n" <<
                 "2. Append - добавляет в файл информацию\n" <<
                 "3. Create - перезаписывает файл\n";
    std::cin >> com;

    // удаляем из потока символ переноса строки
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::fstream file;
    std::string fileName, stringFromFile;

    switch (com)
    {
        case 1:
        {
            fileName = getFileName();
            file.open(fileName);

            if (file.is_open())
            {
                std::cout << "------------Содержимое файла------------\n";
                while (std::getline(file, stringFromFile))
                {
                    std::cout << stringFromFile << '\n';
                }
                std::cout << "---------------Конец файла--------------\n";
                file.close();
            }
            else
                std::cout << "Файл не найден\n";
            break;
        }
        case 2:
        {
            fileName = getFileName();
            file.open(fileName, std::ios::app);

            if (file.is_open())
            {
                std::cout << "Введите добавляемую информацию:\n";
                std::getline(std::cin, stringFromFile);
                file << '\n' << stringFromFile << '\n';
                file.close();
            }
            else
                std::cout << "Файл не найден\n";
            break;
        }
        case 3:
        {
            fileName = getFileName();
            file.open(fileName, std::ios::out);

            if (file.is_open())
            {
                std::cout << "Введите добавляемую информацию:\n";
                std::getline(std::cin, stringFromFile);
                file << stringFromFile << '\n';
                file.close();
            }
            else
                std::cout << "Файл не найден\n";
            break;
        }
    }
    return 0;
}
