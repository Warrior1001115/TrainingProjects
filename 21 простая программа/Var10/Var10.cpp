#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

struct dataFromFile
{
    std::string fio;
    int year;
    std::string address;
    std::string telNumber;
};

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::fstream fileToRead("file.txt");

    std::string stringFromFile;
    dataFromFile data;

    if (fileToRead.is_open())
    {
        std::getline(fileToRead, stringFromFile);
        data.fio = stringFromFile;

        std::getline(fileToRead, stringFromFile);
        data.year = std::stoi(stringFromFile);

        std::getline(fileToRead, stringFromFile);
        data.address = stringFromFile;

        std::getline(fileToRead, stringFromFile);
        data.telNumber = stringFromFile;

        fileToRead.close();

        std::cout << data.fio <<       '\n' <<
                     data.year <<      '\n' <<
                     data.address <<   '\n' <<
                     data.telNumber << '\n';
    }
    else
        std::cout << "Ошибка открытия файла\n";

    return 0;
}
