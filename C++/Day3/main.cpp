#include "../utils.hpp"

class Numbers {
    unsigned int lineNo_;
    size_t pos_;
    int iNumber_;

   public:
    Numbers(unsigned int &, size_t &, int);
    ~Numbers() = default;
};

class Chars {
    unsigned int lineNo_;
    size_t pos_;
    char char_;

   public:
    Chars(unsigned int &, size_t &, char &);
    ~Chars() = default;
};

Numbers::Numbers(unsigned int &lineNo, size_t &pos, int iNumber)
    : lineNo_(lineNo), pos_(pos), iNumber_(iNumber) {}

Chars::Chars(unsigned int &lineNo, size_t &pos, char &_char)
    : lineNo_(lineNo), pos_(pos), char_(_char) {}

void assignment1() {
    std::ifstream myFile("input.txt");
    std::string line;
    size_t pos = 0;
    unsigned int lineNo = 0;
    std::vector<Numbers> vNumbers;
    std::vector<Chars> vChars;
    while (myFile >> line) {
        lineNo++;
        for (auto i = line.begin(); i != line.end(); i++) {
            pos = std::distance(line.begin(), i);
            if (isdigit(*i)) {
                size_t nonDigitPos =
                    line.find_first_not_of("0123456789", pos + 1);
                if (nonDigitPos != std::string::npos) {
                    std::string digit = line.substr(pos, nonDigitPos - pos);
                    std::advance(i, nonDigitPos - pos);
                    std::unique_ptr<Numbers> pNumbers(
                        new Numbers(lineNo, pos, std::stoi(digit)));
                    vNumbers.push_back(*pNumbers);
                }
            } else if (*i != '.') {
                char temp = *i;
                std::unique_ptr<Chars> pChar(new Chars(lineNo, pos, *i));
                vChars.push_back(*pChar);
            }
        }
    }
}

int assignment2() {
    std::ifstream myFile("input.txt");
    std::string line;

    while (std::getline(myFile, line)) {
    }
}

int main() {
    assignment1();
    // std::cout << assignment2() << std::endl;
    return 0;
}
