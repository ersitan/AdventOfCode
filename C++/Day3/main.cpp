#include "utils.hpp"

class Numbers {
    int lineNo_;
    size_t pos_;
    std::string sNumber_;

   public:
    Numbers(int &, size_t &, std::string &);
    ~Numbers() = default;
};

Numbers::Numbers(int &lineNo, size_t &pos, std::string &sNumber)
    : lineNo_(lineNo), pos_(pos), sNumber_(sNumber) {}

int assignment1() {
    std::ifstream myFile("input.txt");
    std::string line;

    while (std::getline(myFile, line)) {
    }
}

int assignment2() {
    std::ifstream myFile("input.txt");
    std::string line;

    while (std::getline(myFile, line)) {
    }
}

int main() {
    std::cout << assignment1() << std::endl;
    std::cout << assignment2() << std::endl;
    return 0;
}
