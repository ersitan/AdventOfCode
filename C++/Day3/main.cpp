#include "../utils.hpp"
#include "chars.hpp"
#include "numbers.hpp"

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

void getVectors(std::vector<Numbers> &vNumbers, std::vector<Chars> &vChars) {
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

void assignment2() {
    std::vector<Numbers> vNumbers;
    std::vector<Chars> vChars;
    getVectors(vNumbers, vChars);
    long long adjecentDigit = 0;
    for (auto &c : vChars) {
        if (c.getChar() == '*') {
            size_t posChar = c.getPos();
            unsigned int lineChar = c.getLine();
            int tempAdjecentDigit = 1;
            std::vector<int> numbersToMultiply;
            auto itLeftDigit =
                std::find_if(vNumbers.begin(), vNumbers.end(), [&](Numbers &n) {
                    return (n.getLine() == lineChar) &&
                           (n.getPos() + n.getNumber().length() == posChar);
                });

            auto itRightDigit =
                std::find_if(vNumbers.begin(), vNumbers.end(), [&](Numbers &n) {
                    return (n.getLine() == lineChar) &&
                           (n.getPos() - 1 == posChar);
                });

            auto itTopDigit =
                std::find_if(vNumbers.begin(), vNumbers.end(), [&](Numbers &n) {
                    return (n.getLine() == lineChar - 1) &&
                           ((n.getPos() >= posChar - n.getNumber().length()) &&
                            (n.getPos() <= posChar + 1));
                });

            auto itBottomDigit =
                std::find_if(vNumbers.begin(), vNumbers.end(), [&](Numbers &n) {
                    return (n.getLine() == lineChar + 1) &&
                           ((n.getPos() >= posChar - n.getNumber().length()) &&
                            (n.getPos() <= posChar + 1));
                });

            while (itTopDigit != vNumbers.end()) {
                numbersToMultiply.push_back(stoi(itTopDigit->getNumber()));
                itTopDigit = std::find_if(
                    std::next(itTopDigit), vNumbers.end(), [&](Numbers &n) {
                        return (n.getLine() == lineChar - 1) &&
                               ((n.getPos() >=
                                 posChar - n.getNumber().length()) &&
                                (n.getPos() <= posChar + 1));
                    });
            }

            while (itBottomDigit != vNumbers.end()) {
                numbersToMultiply.push_back(stoi(itBottomDigit->getNumber()));
                itBottomDigit = std::find_if(
                    std::next(itBottomDigit), vNumbers.end(), [&](Numbers &n) {
                        return (n.getLine() == lineChar + 1) &&
                               ((n.getPos() >=
                                 posChar - n.getNumber().length()) &&
                                (n.getPos() <= posChar + 1));
                    });
            }

            if (itLeftDigit != vNumbers.end()) {
                numbersToMultiply.push_back(stoi(itLeftDigit->getNumber()));
            }

            if (itRightDigit != vNumbers.end()) {
                numbersToMultiply.push_back(stoi(itRightDigit->getNumber()));
            }

            if (numbersToMultiply.size() == 2) {
                for (int &num : numbersToMultiply) {
                    tempAdjecentDigit *= num;
                }
                adjecentDigit += tempAdjecentDigit;
            }
        }
    }
    std::cout << adjecentDigit;
}

int main() {
    // assignment1();
    assignment2();
    return 0;
}
