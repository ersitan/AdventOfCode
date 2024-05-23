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

// std::map<char, int> mCards = {
//     {'2', 2}, {'3', 3},  {'4', 4},  {'5', 5},  {'6', 6},  {'7', 7}, {'8', 8},
//     {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};

std::map<char, int> mCards = {
    {'J', 1}, {'2', 2}, {'3', 3},  {'4', 4},  {'5', 5},  {'6', 6}, {'7', 7},
    {'8', 8}, {'9', 9}, {'T', 10}, {'Q', 11}, {'K', 12}, {'A', 13}};

class Hand {
    std::string cards_ = "";
    int bid_ = 0;
    Types type_;

   public:
    Hand(std::string cards, int bid) : cards_(cards), bid_(bid){};
    ~Hand() = default;

    std::string getCards() { return cards_; }
    int getBid() { return bid_; }
    Types& getType() { return type_; }
    void setType(const Types& t) { type_ = t; }

    bool operator<(Hand& other) { return this->type_ < other.type_; }
    bool operator==(Hand& other) { return this->type_ == other.type_; }
};
