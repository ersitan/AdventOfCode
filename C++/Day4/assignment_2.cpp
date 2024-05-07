#include "get_vector.hpp"

void getCount(std::vector<Cards>& cards) {
    for (auto& v : cards) {
        unsigned int tmpCount = 0;
        for (auto const& myNum : v.myNumbers_) {
            if (std::find(v.winningNumbers_.begin(), v.winningNumbers_.end(),
                          myNum) != v.winningNumbers_.end()) {
                tmpCount++;
            }
        }
        for (unsigned int i = 0; i < tmpCount; ++i) {
            cards.at(v.cardNo_ + i).copies_ += v.copies_;
        }
    }
}

int main() {
    std::vector<Cards> cards{getCards()};
    unsigned int count = 0;
    getCount(cards);
    for (const Cards& c : cards) {
        count += c.copies_;
    }
    std::cout << count << std::endl;
    return 0;
}