#include "../utils.hpp"
#include "reader.hpp"

typedef std::map<std::string, std::vector<std::vector<int>>> myMap;

void findKey(std::string& key, std::string& line) {
    size_t posSemicolon = line.find(':');
    if (posSemicolon != std::string::npos) {
        key = line.substr(0, posSemicolon);
        size_t posMap = key.find("map");
        if (posMap != std::string::npos) {
            key = key.substr(0, posMap - 1);  // remove map from the key
        }
    }
}

void getMaps(std::ifstream& file,
             std::map<std::string, std::vector<std::vector<int>>>& mMap) {
    std::string line, key, word;
    std::vector<int> vNumbers;
    std::vector<std::vector<int>> vValue;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        findKey(key, line);
        while (iss >> word) {
            if (std::isdigit(word[0])) {
                vNumbers.push_back(std::stoi(word));
            }
        }

        if (!vNumbers.empty()) {
            vValue.push_back(vNumbers);
            vNumbers.clear();
        }

        if (!line.size()) {
            mMap[key] = vValue;
            vValue.clear();
        }
    }
}

void generateMaps(myMap& mMap, std::string& key) {
    std::map<std::string, std::pair<int, int>> tempMap;
    int values[100]{0};
    auto it = mMap.find(key);
    //std::vector<std::vector<int, int>> vec;
    if (it != mMap.end()) {
        for (auto& e : it->second) {
            int source = e[1];
            int destination = e[0];
            int length = e[2];
            for (int i = 0; i < length; i++) {
                values[source + i] = destination + i;
            }
            // std::cout<<"de";
        }
    }
    for(int k = 0; k<100; k++){
        if (values[k] == 0){
            values[k] = k;
        }
    }
}

int main() {
    std::ifstream myFile("input2.txt");
    std::string key = "seed-to-soil";
    myMap mMap;
    getMaps(myFile, mMap);
    generateMaps(mMap, key);
    return 0;
}