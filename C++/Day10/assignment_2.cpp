// #include "includes.hpp"
// #include <bits/stdc++.h>

// typedef long long int ll;
 
// // Utility function to find
// // GCD of 'a' and 'b'
// int gcd(int a, int b)
// {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }
 
// // Returns LCM of array elements
// ll findlcm(std::vector<int> arr, int n)
// {
//     // Initialize result
//     ll ans = arr[0];
 
//     // ans contains LCM of arr[0], ..arr[i]
//     // after i'th iteration,
//     for (int i = 1; i < n; i++)
//         ans = (((arr[i] * ans)) /
//                 (gcd(arr[i], ans)));
 
//     return ans;
// }

// void createNetworkVector(std::vector<std::string>& vec,
//                          std::vector<Network>& vNetwork) {
//     for (auto& item : vec) {
//         size_t posEqualSign = item.find('=');
//         size_t posComma = item.find(',');
//         if (posEqualSign != std::string::npos) {
//             std::string node = item.substr(0, posEqualSign - 1);
//             std::pair<std::string, std::string> route = std::pair(
//                 item.substr(posComma - 3, 3), item.substr(posComma + 2, 3));
//             vNetwork.push_back(Network(node, route));
//         }
//     }
// }

// void createVectorWithEndingA(std::vector<Network>& vNetwork,
//                              std::vector<Network>& vNetworkWithEndingA) {
//     auto it = std::find_if(vNetwork.begin(), vNetwork.end(), [](Network& n) {
//         return n.getNode().back() == 'A';
//     });

//     while (it != vNetwork.end()) {
//         vNetworkWithEndingA.push_back(*it);
//         it = std::find_if(it + 1, vNetwork.end(),
//                           [](Network& n) { return n.getNode().back() == 'A'; });
//     }
// }

// void updateSearchVector(std::vector<Network>& vNetwork,
//                         std::vector<Network>& searchVector,
//                         const std::vector<std::string>& vSearchNode) {
//     searchVector.clear();
//     for (auto& node : vSearchNode) {
//         auto it = std::find_if(vNetwork.begin(), vNetwork.end(),
//                                [=](Network& n) { return n.getNode() == node; });
//         if (it != vNetwork.end()) {
//             searchVector.push_back(*it);
//         }
//     }
// }

// int main() {
//     ReadFile rf("input.txt");
//     std::vector<std::string> vec = rf.getLinesVector();
//     std::vector<Network> vNetwork, vNetworkWithEndingA, searchVector;
//     std::string directions = vec[0];
//     createNetworkVector(
//         vec,
//         vNetwork);  // Network objects are created and pushed into a vector.
//     createVectorWithEndingA(vNetwork, vNetworkWithEndingA);

//     int count = 0;
//     ll result;
//     std::vector<std::string> vSearchNode;
//     auto NetworkIt = vNetwork.begin();
//     std::vector<int> vCount;
//     for (size_t i = 0; i < vNetworkWithEndingA.size(); i++) {
//         Network network = vNetworkWithEndingA[i];
//         for (auto dirIt = directions.begin();; dirIt++) {
//             if (dirIt == directions.end()) {
//                 dirIt = directions.begin();
//             }

//             if (*dirIt == 'R') {
//                 NetworkIt = std::find_if(
//                     vNetwork.begin(), vNetwork.end(), [&](Network& n) {
//                         return n.getNode() == network.getRight();
//                     });
//             } else {
//                 NetworkIt = std::find_if(
//                     vNetwork.begin(), vNetwork.end(), [&](Network& n) {
//                         return n.getNode() == network.getLeft();
//                     });
//             }

//             count++;
//             network = *NetworkIt;
//             if (NetworkIt->getNode().back() == 'Z') {
//                 dirIt = directions.begin();
//                 vCount.push_back(count);
//                 count = 0;
//                 break;
//             }
//         }
//     }
//     result = findlcm(vCount, vCount.size()); 

//     std::cout << result << std::endl;
//     return 0;
// }