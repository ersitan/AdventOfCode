// #include "includes.hpp"

// void findUntilZero(std::vector<int>& numbers, int& result) {
//     result += numbers.back();
//     std::vector<int> vTemp;
//     for (size_t i = 1; i < numbers.size(); i++) {
//         vTemp.push_back(numbers[i] - numbers[i - 1]);
//     }
//     //result += vTemp.back();
//     if (!std::all_of(vTemp.begin(), vTemp.end(),
//                      [](int& i) { return i == 0; })) {
//         findUntilZero(vTemp, result);
//     } else {
//         return;
//     }
// }

// int main() {
//     ReadFile rf("input.txt");
//     std::vector<std::string> vec = rf.getLinesVector();
//     rf.printLines();
//     std::string word;
//     std::vector<int> numbers, results;
//     int result = 0;
//     for (auto& v : vec) {
//         std::stringstream ss(v);
//         while (ss >> word) {
//             numbers.push_back(std::stoi(word));
//         }
//         findUntilZero(numbers, result);
//         bool debug = true;
//         numbers.clear();
//         results.push_back(result);
//         result = 0;
//     }

//     std::cout<<std::accumulate(results.begin(),results.end(),0)<<std::endl;
//     return 0;
// }