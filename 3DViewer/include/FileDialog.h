#pragma once
#include <string>
#include <vector>

//Класс для работы с диалогами выбора файлов

class FileDialog {
public:
static std::string openFile(const std::string& filter);
    static std::vector<std::string> openFiles(const char* filter);
}; 