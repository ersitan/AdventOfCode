#include "ReadFile.hpp"

int main() {
    ReadFile rf("input2.txt");
    std::vector<std::string> vec = rf.getLinesVector();

     rf.printLines();
    return 0;
}