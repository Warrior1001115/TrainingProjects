#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

struct listElem
{
    listElem* next;
    listElem* prev;
    std::string surname;
};

listElem* createStartElem(std::string surnameString)
{
    listElem* first = new listElem;
    first->surname = surnameString;
    first->next = NULL;
    first->prev = NULL;
    return first;
}

void putInNextElem(listElem* elem, std::string surnameString)
{
    listElem* newElem = new listElem;
    newElem->prev = elem;
    newElem->next = elem->next;
    newElem->surname = surnameString;
    elem->next = newElem;
}

int main()
{
    // для работы с русскими символами
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream surnames("surnames.txt");
    std::string line = "";

    getline(surnames, line);

    listElem* currElem = new listElem;
    currElem = createStartElem(line);

    while (surnames.is_open() && getline(surnames, line))
    {   
        if (line >= currElem->surname)
        {
            while ((currElem->next != NULL) && (line >= currElem->next->surname))
                currElem = currElem->next;
            putInNextElem(currElem, line);
        }
        else
        {
            while ((currElem->prev != NULL) && (line < currElem->prev->surname))
                currElem = currElem->prev;
            putInNextElem(currElem, line);
        }    
    }

    surnames.close();

    while (currElem->prev != NULL)
        currElem = currElem->prev;
    while (currElem->next != NULL)
    {
        std::cout << currElem->surname << std::endl;
        currElem = currElem->next;
    }
    std::cout << currElem->surname << std::endl;
    while (currElem->prev != NULL)
        currElem = currElem->prev;
    while (currElem->next != NULL)
    {
        listElem* delElem = currElem;
        currElem = currElem->next;
        delete delElem;
    }
    delete currElem;

    return 0;
}
