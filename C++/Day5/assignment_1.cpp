#include "../utils.hpp"
#include "reader.hpp"

typedef std::map<std::string, std::vector<std::vector<int>>> myMap;

void getSeedsVector(std::ifstream& file, std::vector<std::string>& vSeeds) {
    std::string line, sSeeds;
    while (std::getline(file, line)) {
        size_t posSeeds = line.find("seeds: ");  // find the seeds
        if (posSeeds != std::string::npos) {
            std::istringstream iss(line);
            while (iss >> sSeeds) {
                if (std::isdigit(sSeeds[0])) {
                    vSeeds.push_back(
                        sSeeds);  // if seeds are found, feed them into a vector
                }
            }
        }
    }
}

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

        if(!vNumbers.empty()){
            vValue.push_back(vNumbers);
            vNumbers.clear();
        }
        
        if (!line.size()) {
            mMap[key] = vValue;
            vValue.clear();
        }
    }
}

void generateMaps(myMap& mMap){
    
}

int main() {
    std::ifstream myFile("input2.txt");
    
    myMap mMap;
    getMaps(myFile, mMap);
    generateMaps(mMap);
    return 0;
}