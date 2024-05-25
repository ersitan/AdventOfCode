// #include "includes.hpp"

// int main() {
//     ReadFile rf("input.txt");
//     std::vector<std::string> vec = rf.getLinesVector();
//     // rf.printLines();
//     std::vector<Network> vNetwork;
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

//     std::string directions = vec[0];
//     std::string searchedNode = "AAA";
//     int count = 0;
//     for (auto it = directions.begin();; it++) {
//         auto nodeIt = std::find_if(
//             vNetwork.begin(), vNetwork.end(),
//             [&](Network& n) { return n.getNode() == searchedNode; });
//         if (nodeIt != vNetwork.end()) {
//             if (*it == 'R') {
//                 searchedNode = nodeIt->getRight();
//             } else {
//                 searchedNode = nodeIt->getLeft();
//             }
            
//             count++;
//             if (searchedNode == "ZZZ"){
//                 break;
//             }
//             if (it == directions.end()){
//                 it = directions.begin();
//             }
//         }
//         else{
//             break;
//         }
//     }

//     std::cout<<count<<std::endl;
//     return 0;
// }