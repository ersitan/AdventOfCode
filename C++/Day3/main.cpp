#include "../utils.hpp"
#include "chars.hpp"
#include "numbers.hpp"

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

void find_right_digit(std::string &line, unsigned int &lineNo) {
    size_t posStar = line.find('*');
    while (posStar != std::string::npos) {
        size_t posDigitRight = line.find_first_of("0123456789", posStar);
        if (posDigitRight - 1 == posStar) {
            {
                size_t nonDigitAfterRightDigit =
                    line.find_first_not_of("0123456789", posDigitRight);
                std::string rightDigit = line.substr(
                    posDigitRight, nonDigitAfterRightDigit - posDigitRight);
                std::cout << "LINE NO " << lineNo << ": FOUND " << rightDigit
                          << " ON THE RIGHT" << std::endl;
            }
        }

        posStar = line.find('*', posStar + 1);
    }
}

void find_left_digit(std::string &line, unsigned int &lineNo) {
    auto posStar = line.rfind('*');
    while (posStar != std::string::npos) {
        size_t posDigitLeft = line.find_last_of("0123456789", posStar);
        if (posDigitLeft + 1 == posStar) {
            {
                size_t nonDigitAfterLeftDigit =
                    line.find_last_not_of("0123456789", posDigitLeft);
                std::string leftDigit =
                    line.substr(nonDigitAfterLeftDigit + 1,
                                posDigitLeft - nonDigitAfterLeftDigit);
                std::cout << "LINE NO " << lineNo << ": FOUND " << leftDigit
                          << " IN THE LEFT" << std::endl;
            }
        }

        posStar = line.rfind('*', posStar - 1);
    }
}

void getVectors(std::vector<Numbers>& vNumbers, std::vector<Chars> &vChars) {
    std::ifstream myFile("input.txt");
    std::string line;
    size_t pos = 0;
    unsigned int lineNo = 0, count = 0;
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
}
/*std::ifstream myFile("input.txt");
std::string line;
unsigned int lineNo = 0;

while (myFile >> line) {
    lineNo++;
    //find_right_digit(line, lineNo);
    //find_left_digit(line, lineNo);
}*/

void assignment2() {
    std::vector<Numbers> vNumbers;
    std::vector<Chars> vChars;
    getVectors(vNumbers, vChars);
    
    for (auto &c : vChars) {
        if (c.getChar() == '*') {
            // for (auto &d : vNumbers) {
            //     if (((c.getPos() - d.getNumber().length() == d.getPos()) ||
            //          (d.getPos() - 1 == c.getPos())) &&
            //         c.getLine() == d.getLine()) {
            //         std::cout << "LINE " << c.getLine() << ": " << d.getNumber()
            //                   << " " << c.getChar() << std::endl;
            //         break;
            //     }
            // }
        }
    }
}

int main() {
    // assignment1();
    assignment2();
    return 0;
}
