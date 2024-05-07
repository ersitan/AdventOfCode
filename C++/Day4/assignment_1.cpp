// #include "get_vector.hpp"

// int getCount(std::vector<Cards>& cards) {
//     int count = 0;
//     for (auto const& v : cards) {
//         int tmpCount = 0;
//         for (auto const& myNum : v.myNumbers_) {
//             if (std::find(v.winningNumbers_.begin(), v.winningNumbers_.end(),
//                           myNum) != v.winningNumbers_.end()) {
//                 tmpCount++;
//             }
//         }
//         if (tmpCount > 0) {
//             count +=pow(2, tmpCount - 1);
//         }
//     }
//     return count;
// }
// int main() {
//     std::vector<Cards> cards{getCards()};
//     int count = 0;

//     count = getCount(cards);
//     std::cout << count << std::endl;
//     return 0;
// }