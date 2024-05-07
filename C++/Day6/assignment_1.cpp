// #include "../utils.hpp"

// struct Race {
//     unsigned int raceNo;
//     unsigned int time;
//     unsigned int distance;
// };

// void readFile(std::vector<Race>& vec) {
//     std::ifstream myFile("input.txt");
//     std::string word;

//     unsigned int i = 0;
//     bool time = true;
//     while (myFile >> word) {
//         if (std::isdigit(word[0])) {
//             if (time) {
//                 vec[i].raceNo = i + 1;
//                 vec[i].time = std::stoi(word);
//                 i++;
//             } else {
//                 vec[i].distance = std::stoi(word);
//                 i++;
//             }
//         }
//         if (word == "Distance:") {
//             i = 0;
//             time = false;
//         }
//     }
// }
// unsigned int calculate(const Race& raceObj) {
//     for (unsigned int i = 1; i < raceObj.time; i++) {
//         if (i * (raceObj.time - i) > raceObj.distance) {
//             return raceObj.time - (2 * i) + 1;
//         }
//     }
// }

// int main() {
//     std::vector<Race> raceVec{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
//     readFile(raceVec);
//     unsigned int res = 1;
//     for (const Race& raceObj : raceVec) {
//         res *= calculate(raceObj);
//     }
//     std::cout << res;
//     return 0;
// }