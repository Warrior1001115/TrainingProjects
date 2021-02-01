#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

struct person
{
    std::string surname;
    unsigned short year;
    unsigned short month;
    unsigned short day;
};

int main()
{
    // для использования русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    person newPerson;

    std::ofstream fileToAddData("file.txt", std::ios::app);

    std::cout << "Введите фамилию, год, месяц и день\n";
    std::cin >> newPerson.surname >> newPerson.year >> newPerson.month >> newPerson.day;

    fileToAddData << newPerson.surname << '\n' <<
                     newPerson.year << '\n' <<
                     newPerson.month << '\n' <<
                     newPerson.day << '\n';

    fileToAddData.close();

    std::ifstream fileToReadData("file.txt");

    std::cout << "Введите фамилию человека, чъю дату рождения необходимо найти:\n";
    std::cin >> newPerson.surname;

    std::string stringFromFile;
    bool isFinded = false;

    while ((std::getline(fileToReadData, stringFromFile)) && (!isFinded))
    {
        if (stringFromFile == newPerson.surname)
        {
            std::getline(fileToReadData, stringFromFile);
            newPerson.year = std::stoi(stringFromFile);

            std::getline(fileToReadData, stringFromFile);
            newPerson.month = std::stoi(stringFromFile);

            std::getline(fileToReadData, stringFromFile);
            newPerson.day = std::stoi(stringFromFile);

            isFinded = true;
        }
    }

    std::cout << "Дата рождения человека с фамилией " << newPerson.surname << '\n';
    if (isFinded)
        std::cout << newPerson.year << '.' <<
                     newPerson.month << '.' <<
                     newPerson.day << '\n';
    else
        std::cout << "не найдена\n";

    return 0;
}
