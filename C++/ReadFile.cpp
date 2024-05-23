#include "ReadFile.hpp"

ReadFile::ReadFile(std::string filename) {
    std::ifstream myFile(filename);
    std::string line;
    while (std::getline(myFile, line)) {
        vLines_.push_back(line);
    }
}

void ReadFile::printLines() {
    for (const std::string& line : vLines_) {
        std::cout << line << std::endl;
    }
}