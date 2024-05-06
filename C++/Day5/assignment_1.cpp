#include "../utils.hpp"
#include "reader.hpp"

typedef std::map<std::string, std::vector<std::vector<uint64_t>>> myMap;

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
             std::map<std::string, std::vector<std::vector<uint64_t>>>& mMap) {
    std::string line, key, word;
    std::vector<uint64_t> vNumbers;
    std::vector<std::vector<uint64_t>> vValue;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        findKey(key, line);
        while (iss >> word) {
            if (std::isdigit(word[0])) {
                vNumbers.push_back(std::stoll(word));
            }
        }

        if (!vNumbers.empty()) {
            vValue.push_back(vNumbers);
            vNumbers.clear();
        }

        if (!line.size() || file.eof()) {
            mMap[key] = vValue;
            vValue.clear();
        }
    }
}

std::vector<std::pair<uint64_t,uint64_t>> generateMappedVector(myMap& mMap, std::string& key) {
    std::vector<std::pair<uint64_t,uint64_t>> values;
    auto it = mMap.find(key);
    if (it != mMap.end()) {
        /*for (uint64_t k = 0; k < std::numeric_limits<uint64_t>::max(); k++) {
            values.push_back(k);
        }*/
        for (auto& e : it->second) {
            uint64_t source = e[1];
            uint64_t destination = e[0];
            uint64_t length = e[2];
            for (uint64_t i = 0; i < length; i++) {
                values.push_back(std::make_pair(source + i, destination + i));
            }
        }
    }
    return values;
}

uint64_t getValueFromMap(const uint64_t& elem,
                    std::map<std::string, std::vector<std::pair<uint64_t,uint64_t>>>& myMap,
                    std::string& keyword) {
    auto it1 = std::find_if(myMap.begin(), myMap.end(), [&](const auto& tmp) {
        return (tmp.first == keyword);
    });
    for (auto &e: it1->second){
        if(e.first == elem){
            return e.second;
        }
    }
    return elem;
}

int main() {
    std::ifstream myFile("input2.txt");
    std::string sSeedToSoil = "seed-to-soil";
    std::string sSoilToFertilizer = "soil-to-fertilizer";
    std::string sFertilizerToWater = "fertilizer-to-water";
    std::string sWaterToLight = "water-to-light";
    std::string sLightToTemp = "light-to-temperature";
    std::string sTempToHum = "temperature-to-humidity";
    std::string sHumToLoc = "humidity-to-location";
    myMap mMap;
    std::map<std::string, std::vector<std::pair<uint64_t,uint64_t>>> sortedMap;
    std::vector<uint64_t> vec;
    getMaps(myFile, mMap);
    for (const auto& m : mMap) {
        std::string key = m.first;
        if (key.find("seeds") == std::string::npos) {
            std::vector<std::pair<uint64_t,uint64_t>> myArray = generateMappedVector(mMap, key);
            sortedMap[key] = myArray;
        }
    }

    auto it = mMap.find("seeds");
    if (it != mMap.end()) {
        for (const uint64_t& elem : it->second[0]) {
            uint64_t soil = getValueFromMap(elem, sortedMap, sSeedToSoil);
            uint64_t fertilizer =
                getValueFromMap(soil, sortedMap, sSoilToFertilizer);
            uint64_t water =
                getValueFromMap(fertilizer, sortedMap, sFertilizerToWater);
            uint64_t light = getValueFromMap(water, sortedMap, sWaterToLight);
            uint64_t temperature = getValueFromMap(light, sortedMap, sLightToTemp);
            uint64_t hum = getValueFromMap(temperature, sortedMap, sTempToHum);
            uint64_t loc = getValueFromMap(hum, sortedMap, sHumToLoc);
            vec.push_back(loc);
        }
    }
    std::cout << *std::min_element(vec.begin(), vec.end());

    return 0;
}