#pragma once

#include "../utils.hpp"

struct Cards {
    unsigned int cardNo_;
    std::vector<int> winningNumbers_;
    std::vector<int> myNumbers_;
    unsigned int copies_ = 1;
};

std::vector<Cards> getCards() {
    std::ifstream myFile("input.txt");
    std::string line;
    unsigned int cardNo = 0;

    std::vector<Cards> vCards;
    while (std::getline(myFile, line)) {
        Cards card;
        cardNo++;
        card.cardNo_ = cardNo;
        size_t pos = line.find(':');
        line = line.substr(pos + 2);
        std::stringstream ss(line);
        std::string ln;
        bool luckyNumbers = true;
        while (ss >> ln) {
            if (ln == "|") {
                luckyNumbers = false;
                continue;
            }

            if (luckyNumbers) {
                card.winningNumbers_.push_back(std::stoi(ln));
            } else {
                card.myNumbers_.push_back(std::stoi(ln));
            }
        }
        vCards.push_back(card);
    }
    return vCards;
}