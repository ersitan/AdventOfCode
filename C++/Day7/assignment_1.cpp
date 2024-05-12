#include "ReadFile.hpp"
#include "includes.hpp"

void setTypes(Hands& hand) {
    std::map<char, int> cardMap;
    for (const auto& card : hand.getCards()) {
        if (cardMap.find(card) != cardMap.end()) {
            cardMap[card]++;
        } else {
            cardMap[card] = 1;
        }
    }

    // auto keyView = std::views::keys(cardMap);
    // std::vector<char> vKeys{keyView.begin(), keyView.end()};
    auto valueView = std::views::values(cardMap);
    std::vector<int> vValues{valueView.begin(), valueView.end()};

    switch (cardMap.size()) {
        case 1:
            hand.setType(Types::fiveOfAKind);
            break;
        case 2:
            if (std::any_of(vValues.begin(), vValues.end(),
                            [](int& x) { return x == 4; })) {
                hand.setType(Types::fourOfAKind);
            } else {
                hand.setType(Types::fullHouse);
            }
            break;
        case 3:
            if (std::any_of(vValues.begin(), vValues.end(),
                            [](int& x) { return x == 3; })) {
                hand.setType(Types::threeOfAKind);
            } else {
                hand.setType(Types::twoPair);
            }
            break;
        case 4:
            hand.setType(Types::onePair);
            break;
        case 5:
            hand.setType(Types::highCard);
            break;
        default:
            break;
    }
}
void sortHands(std::vector<Hands>& vHand) {
    std::sort(vHand.begin(), vHand.end(),
              [](auto& l, auto& r) { return r < l; });
}

int main() {
    ReadFile rf("input2.txt");
    std::vector<std::string> vec = rf.getLinesVector();

    std::vector<Hands> vHands;
    for (auto& item : vec) {
        size_t posSpace = item.find(' ');
        std::string val = item.substr(0, posSpace);
        int bid = std::stoi(item.substr(posSpace));
        vHands.push_back(Hands(val, bid));
    }
    for (auto& h : vHands) {
        setTypes(h);
    }

    sortHands(vHands);

    return 0;
}