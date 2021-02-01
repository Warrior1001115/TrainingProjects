#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

bool isSeparator(char charForCheck)
{
    switch (charForCheck)
    {
    case ' ':
        return true;
    case ',':
        return true;
    case '!':
        return true;
    case '.':
        return true;
    case ':':
        return true;
    case '?':
        return true;
    case '/':
        return true;
    default:
        return false;
    }
}

std::vector<std::string> splitString(std::string fullString)
{
    std::vector<std::string> result;
    std::string word;
    for (int i = 0; i < fullString.size(); i++)
    {
        if (isSeparator(fullString[i]))
        {
            if (word != "")
            {
                result.push_back(word);
                word = "";
            }
        }
        else
            word += fullString[i];
    }
    return result;
}

int main()
{
    // переключение кодировки позволит корректно работать с русскими символами,
    // но это необязательно, если файл не содержит русских символов

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream oldFile("oldfile.txt");
    std::ofstream newFile("newfile.txt");

    std::string line = "";

    while (oldFile.is_open() && getline(oldFile, line))
    {
        std::vector<std::string> wordsFromLine = splitString(line);
        for (int i = 0; i < wordsFromLine.size(); i++)
            if (wordsFromLine.at(i).size() > 4)            
                newFile << wordsFromLine.at(i) << " ";
        newFile << std::endl;
    }

    oldFile.close();
    newFile.close();

    return 0;
}
