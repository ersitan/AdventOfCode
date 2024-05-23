#pragma once
#include "utils.hpp"

class ReadFile {
    std::vector<std::string> vLines_;

   public:
    ReadFile(std::string);
    ~ReadFile() = default;

    std::vector<std::string> getLinesVector() { return vLines_; };
    void printLines();
};