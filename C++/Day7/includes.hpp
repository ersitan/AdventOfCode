#pragma once
#include "utils.hpp"

enum Types : int {
    highCard,
    onePair,
    twoPair,
    threeOfAKind,
    fullHouse,
    fourOfAKind,
    fiveOfAKind
};

enum Cards : int {
    two = 2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    T = 10,
    J,
    Q,
    K
};

class Hands {
    int rank_ = 0;
    std::string value_ = "";
    int bid_ = 0;
    Types type_;

   public:
    Hands(std::string val, int bid) : value_(val), bid_(bid) {};
    ~Hands() = default;

    int getRank() { return rank_; }
    std::string getCards() { return value_;}
    void setType(Types t){type_ = t;}

    bool operator<(Hands& other){
        return this->type_ < other.type_;
    }
};

