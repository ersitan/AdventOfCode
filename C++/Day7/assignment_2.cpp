#include "ReadFile.hpp"
#include "includes.hpp"

void setTypes(Hand& hand) {
    std::map<char, int> cardMap;
    for (const auto& card : hand.getCards()) {
        if (cardMap.find(card) != cardMap.end()) {
            cardMap[card]++;
        } else {
            cardMap[card] = 1;
        }
    }

    auto valueView = std::views::values(cardMap);  // c++20
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

void sortByType(std::vector<Hand>& vHand) {
    std::sort(vHand.begin(), vHand.end(),
              [](auto& l, auto& r) { return r < l; });
}

bool sortSameTypes(Hand& left, Hand& right) {
    if (left.getType() == right.getType()) {
        for (size_t i = 0; i <= 5; i++) {
            char& l = left.getCards()[i];
            char& r = right.getCards()[i];
            if (l == r) {
                continue;
            } else {
                auto posLeft = mCards.find(l);
                auto posRight = mCards.find(r);
                return posLeft->second > posRight->second;
            }
        }
    }
    return false;
}

int main() {
    ReadFile rf("input2.txt");
    std::vector<std::string> vec = rf.getLinesVector();
    int i = 1;
    int result = 0;
    std::vector<Hand> vHands;

    for (auto& item : vec) {
        size_t posSpace = item.find(' ');
        std::string val = item.substr(0, posSpace);
        int bid = std::stoi(item.substr(posSpace));
        vHands.push_back(Hand(val, bid));
    }
    for (auto& h : vHands) {
        setTypes(h);
    }

    sortByType(vHands);
    std::vector<Hand> vFiveOfAKind, vFourOfAKind, vFullHouse, vThreeOfAKind,
        vTwoPair, vOnePair, vHighCard;

    for (Hand& h : vHands) {
        switch (h.getType()) {
            case Types::fiveOfAKind:
                vFiveOfAKind.push_back(h);
                break;
            case Types::fourOfAKind:
                vFourOfAKind.push_back(h);
                break;
            case Types::fullHouse:
                vFullHouse.push_back(h);
                break;
            case Types::threeOfAKind:
                vThreeOfAKind.push_back(h);
                break;
            case Types::twoPair:
                vTwoPair.push_back(h);
                break;
            case Types::onePair:
                vOnePair.push_back(h);
                break;
            case Types::highCard:
                vHighCard.push_back(h);
                break;
        }
    }

    std::sort(vFiveOfAKind.begin(), vFiveOfAKind.end(), sortSameTypes);
    std::sort(vFourOfAKind.begin(), vFourOfAKind.end(), sortSameTypes);
    std::sort(vFullHouse.begin(), vFullHouse.end(), sortSameTypes);
    std::sort(vThreeOfAKind.begin(), vThreeOfAKind.end(), sortSameTypes);
    std::sort(vTwoPair.begin(), vTwoPair.end(), sortSameTypes);
    std::sort(vOnePair.begin(), vOnePair.end(), sortSameTypes);
    std::sort(vHighCard.begin(), vHighCard.end(), sortSameTypes);
    
    vHands.clear();
    vHands.insert(vHands.begin(), vHighCard.begin(), vHighCard.end());
    vHands.insert(vHands.begin(), vOnePair.begin(), vOnePair.end());
    vHands.insert(vHands.begin(), vTwoPair.begin(), vTwoPair.end());
    vHands.insert(vHands.begin(), vThreeOfAKind.begin(), vThreeOfAKind.end());
    vHands.insert(vHands.begin(), vFullHouse.begin(), vFullHouse.end());
    vHands.insert(vHands.begin(), vFourOfAKind.begin(), vFourOfAKind.end());
    vHands.insert(vHands.begin(), vFiveOfAKind.begin(), vFiveOfAKind.end());

    for (auto it = vHands.rbegin(); it != vHands.rend(); it++) {
        result += it->getBid() * i;
        i++;
    }

    std::cout << result;
    return 0;
}