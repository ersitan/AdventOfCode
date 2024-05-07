#include "../utils.hpp"

struct Race {
    unsigned long long int time;
    unsigned long long int distance;
};

void readFile(Race& raceObj) {
    std::ifstream myFile("input.txt");
    std::string word;

    unsigned int i = 0;
    bool time = true;
    std::string sTime = "", sDistance = "";
    while (myFile >> word) {
        if (std::isdigit(word[0])) {
            if (time) {
                sTime += word;
            } else {
                sDistance += word;
            }
        }
        if (word == "Distance:") {
            time = false;
        }
    }
    raceObj.time = std::stoull(sTime);
    raceObj.distance = std::stoull(sDistance);
}

unsigned int calculate(const Race& raceObj) {
    for (unsigned int i = 1; i < raceObj.time; i++) {
        if (i * (raceObj.time - i) > raceObj.distance) {
            return raceObj.time - (2 * i) + 1;
        }
    }
}

int main() {
    Race raceObj{0, 0};
    readFile(raceObj);
    unsigned int res = 1;
    res = calculate(raceObj);
    std::cout << res;
    return 0;
}