#include "includes.hpp"

void createNetworkVector(std::vector<std::string>& vec,
                         std::vector<Network>& vNetwork) {
    for (auto& item : vec) {
        size_t posEqualSign = item.find('=');
        size_t posComma = item.find(',');
        if (posEqualSign != std::string::npos) {
            std::string node = item.substr(0, posEqualSign - 1);
            std::pair<std::string, std::string> route = std::pair(
                item.substr(posComma - 3, 3), item.substr(posComma + 2, 3));
            vNetwork.push_back(Network(node, route));
        }
    }
}

void createVectorWithEndingA(std::vector<Network>& vNetwork,
                             std::vector<Network>& vNetworkWithEndingA) {
    auto it = std::find_if(vNetwork.begin(), vNetwork.end(), [](Network& n) {
        return n.getNode().back() == 'A';
    });

    while (it != vNetwork.end()) {
        vNetworkWithEndingA.push_back(*it);
        it = std::find_if(it + 1, vNetwork.end(),
                          [](Network& n) { return n.getNode().back() == 'A'; });
    }
}

void updateSearchVector(std::vector<Network>& vNetwork,
                        std::vector<Network>& searchVector,
                        const std::vector<std::string>& vSearchNode) {
    searchVector.clear();
    for (auto& node : vSearchNode) {
        auto it = std::find_if(vNetwork.begin(), vNetwork.end(),
                               [=](Network& n) { return n.getNode() == node; });
        if (it != vNetwork.end()) {
            searchVector.push_back(*it);
        }
    }
}

int main() {
    ReadFile rf("input.txt");
    std::vector<std::string> vec = rf.getLinesVector();
    std::vector<Network> vNetwork, vNetworkWithEndingA, searchVector;
    std::string directions = vec[0];
    createNetworkVector(
        vec,
        vNetwork);  // Network objects are created and pushed into a vector.
    createVectorWithEndingA(vNetwork, vNetworkWithEndingA);
    searchVector = vNetworkWithEndingA;
    int count = 0;
    std::vector<std::string> vSearchNode;
    for (auto it = directions.begin();; it++) {
        if (it == directions.end()) {
            it = directions.begin();
        }

        for (auto& n : searchVector) {
            if (*it == 'R') {
                vSearchNode.push_back(n.getRight());
            } else {
                vSearchNode.push_back(n.getLeft());
            }
        }
        updateSearchVector(vNetwork, searchVector, vSearchNode);
        for (auto& item : vSearchNode) {
            std::cout << item << ' ';
        }
        std::cout<<std::endl;
        vSearchNode.clear();
        count++;

        if (std::all_of(searchVector.begin(), searchVector.end(),
                        [](Network& n) { return n.getNode().back() == 'Z'; })) {
            bool found = true;
            goto found;
        }
    }

found:
    std::cout << count << std::endl;
    return 0;
}