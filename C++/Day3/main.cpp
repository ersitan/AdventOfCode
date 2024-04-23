#include "../utils.hpp"

class Numbers {
    unsigned int lineNo_;
    size_t pos_;
    std::string sNumber_;

   public:
    Numbers(unsigned int &, size_t &, std::string &);
    ~Numbers() = default;

    int getLine() { return lineNo_; }

    int getPos() { return pos_; }

    std::string getNumber() { return sNumber_; }
};

class Chars {
    unsigned int lineNo_;
    size_t pos_;
    char char_;

   public:
    Chars(unsigned int &, size_t &, char &);
    ~Chars() = default;

    int getLine() { return lineNo_; }

    int getPos() { return pos_; }

    char getChar() { return char_; }
};

Numbers::Numbers(unsigned int &lineNo, size_t &pos, std::string &sNumber)
    : lineNo_(lineNo), pos_(pos), sNumber_(sNumber) {}

Chars::Chars(unsigned int &lineNo, size_t &pos, char &_char)
    : lineNo_(lineNo), pos_(pos), char_(_char) {}

void assignment1() {
    std::ifstream myFile("input.txt");
    std::string line;
    size_t pos = 0;
    unsigned int lineNo = 0, count = 0;
    std::vector<Numbers> vNumbers;
    std::vector<Chars> vChars;
    while (myFile >> line) {
        lineNo++;
        for (auto i = line.begin(); i != line.end(); i++) {
            pos = std::distance(
                line.begin(), i);  // since i is an iterator, we assign the
                                   // position of the iterator to vairable pos.
            if (isdigit(*i)) {
                size_t nonDigitPos = line.find_first_not_of(
                    "0123456789",
                    pos);  // find the first non-digit char after the digit
                // so that we know the size of the found digit.
                std::string digit = line.substr(pos, nonDigitPos - pos);
                vNumbers.push_back(Numbers(lineNo, pos, digit));
                if (nonDigitPos != std::string::npos) {
                    std::advance(i, digit.length());
                } else {  // last digit in the line, no need to search for the
                          // next
                    break;
                }
            }
            if (!isdigit(*i) &&
                *i != '.') {  // if it is a non-digit char but '.'
                pos = std::distance(line.begin(), i);  //
                char temp = *i;
                vChars.push_back(Chars(lineNo, pos, *i));
            }
        }
    }

    for (auto &d : vNumbers) {
        for (auto &c : vChars) {
            int digitPos = d.getPos();
            int digitLenght = d.getNumber().length();
            std::string digitDigit = d.getNumber();
            int charPos = c.getPos();
            char charChar = c.getChar();
            int digitLine = d.getLine();
            int charLine = c.getLine();
            if (digitLine == charLine) {
                if (digitPos + digitLenght == charPos ||
                    digitPos - 1 == charPos) {
                    std::cout << "Found ADJECENT: " << digitDigit <<
                        //'(' << digitPos << ')' <<
                        " and " << charChar <<
                        //'(' << charPos << ')' <<
                        " in line " << digitLine << std::endl;
                    count += stoi(digitDigit);
                    break;
                }
            } else if (digitLine + 1 == charLine || digitLine - 1 == charLine) {
                for (int i = digitPos - 1; i < digitPos + digitLenght + 1;
                     i++) {
                    if (i == charPos) {
                        std::cout << "Found ADJECENT: " << digitDigit <<
                            //'(' << digitPos << ')' <<
                            " in line " << digitLine << ", " << charChar <<
                            //'(' << charPos << ')' <<
                            " in line " << charLine << std::endl;
                        count += stoi(digitDigit);
                        break;
                    }
                }
            }
        }
    }
    std::cout << count << std::endl;
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
