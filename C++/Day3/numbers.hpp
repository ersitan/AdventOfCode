#ifndef NUMBERS_H
#define NUMBERS_H

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

#endif  // NUMBERS_H