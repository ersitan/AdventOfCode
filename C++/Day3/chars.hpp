#ifndef CHARS_H
#define CHARS_H

#include "../utils.hpp"

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

#endif  // CHARS_H