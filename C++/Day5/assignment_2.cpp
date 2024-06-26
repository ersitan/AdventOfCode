#include "../utils.hpp"

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

void sortValues(myMap& map) {
    for (auto& elem : map) {
        std::sort(elem.second.begin(), elem.second.end(),
                  [](auto& left, auto& right) { return left[1] < right[1]; });
    }
}

void readFileIntoMap(myMap& mMap) {
    std::ifstream myFile("input.txt");
    std::string line, key, word;
    std::vector<uint64_t> vNumbers;
    std::vector<std::vector<uint64_t>> vValue;

    while (std::getline(myFile, line)) {
        std::istringstream iss(line);
        findKey(key, line);
        while (iss >> word) {
            if (std::isdigit(word[0])) {
                vNumbers.push_back(std::stoull(word));
            }
        }

        if (!vNumbers.empty()) {
            vValue.push_back(vNumbers);
            vNumbers.clear();
        }

        if (!line.size() || myFile.eof()) {
            mMap[key] = vValue;
            vValue.clear();
        }
    }
}

uint64_t findLocation(const uint64_t& input, myMap& mMap,
                 std::string& key) {
    int res = 0;
    auto vec = mMap.at(key);
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i][0] <= input && input < vec[i][0] + vec[i][2]) {
            return input - vec[i][0] + vec[i][1];
        }
    }
    return input;
}

std::vector<uint64_t> seperateSeeds(myMap& map) {
    std::vector<uint64_t> seedVec;
    auto it = map.find("seeds");
    if (it != map.end()) {
        for (const uint64_t& elements : it->second[0]) {
            seedVec.push_back(elements);
        }
        map.erase(it);
    }
    return seedVec;
}

bool findNumberInSeeds(uint64_t& val, std::vector<uint64_t>& seedsVec){
    for(uint64_t i = 0; i < seedsVec.size(); i+=2){
        if(seedsVec[i] <= val && val < seedsVec[i] + seedsVec[i+1]){
            return true;
        }        
    }
    return false;
}

int main() {
    std::string sSeedToSoil = "seed-to-soil";
    std::string sSoilToFertilizer = "soil-to-fertilizer";
    std::string sFertilizerToWater = "fertilizer-to-water";
    std::string sWaterToLight = "water-to-light";
    std::string sLightToTemp = "light-to-temperature";
    std::string sTempToHum = "temperature-to-humidity";
    std::string sHumToLoc = "humidity-to-location";
    myMap mMap;
    uint64_t largestNumber;
    readFileIntoMap(mMap);
    std::vector<uint64_t> seedsVec = seperateSeeds(mMap), locationVector;
    sortValues(mMap);
    
    auto it = mMap.find(sHumToLoc);
    if(it!=mMap.end()){
        largestNumber = it->second.back()[1];
        for (uint64_t i = 0; i <= largestNumber; i++){
            uint64_t hum = findLocation(i, mMap, sHumToLoc);
            uint64_t temp = findLocation(hum, mMap, sTempToHum);
            uint64_t light = findLocation(temp, mMap, sLightToTemp);
            uint64_t water = findLocation(light, mMap, sWaterToLight);
            uint64_t fert = findLocation(water, mMap, sFertilizerToWater);
            uint64_t soil = findLocation(fert, mMap, sSoilToFertilizer);
            uint64_t seed = findLocation(soil, mMap, sSeedToSoil);
            if (findNumberInSeeds(seed, seedsVec)){
                std::cout<<"location " << i << " is found at " << seed << std::endl;
                break;
            }
        }
    }
    return 0;
}