#include "../utils.hpp"

class Game {
    int gameNo_, blueCount_, redCount_, greenCount_;

   public:
    Game(int&, int&, int&, int&);
    ~Game() = default;
    int getGameNo() { return gameNo_; }
    void setGameNo(int val) { gameNo_ = val; }
    void setColorCount(int& blueCount, int& redCount, int& greenCount) {
        blueCount_ = blueCount;
        redCount_ = redCount;
        greenCount_ = greenCount;
    }

    int getColorCount(std::string colorName) {
        if (colorName == "blue") {
            return blueCount_;
        } else if (colorName == "red") {
            return redCount_;
        } else if (colorName == "green") {
            return greenCount_;
        } else {
            return 0;
        }
    }
};

Game::Game(int& gameNo, int& blue, int& red, int& green)
    : gameNo_(gameNo), blueCount_(blue), redCount_(red), greenCount_(green) {}

int getLargest(std::string color, std::string& line) {
    int largestInt = 0, tmpLargestInt;
    size_t pos = line.find(color);
    while (pos != std::string::npos) {
        size_t tempPos = line.rfind(" ", pos - 2);
        std::string sLargestInt = line.substr(tempPos + 1, pos - tempPos - 2);
        tmpLargestInt = stoi(sLargestInt);
        largestInt = tmpLargestInt > largestInt ? tmpLargestInt : largestInt;
        pos = line.find(color, pos + 1);
    }

    return largestInt;
}

int assignment1() {
    std::ifstream myFile("input.txt");
    std::string line;
    int gameNo = 0, largestBlue = 0, largestRed = 0, largestGreen = 0,
        count = 0;
    std::vector<Game> gameVec;

    while (std::getline(myFile, line)) {
        gameNo++;
        std::unique_ptr<Game> pGame{
            new Game(gameNo, largestBlue, largestRed, largestGreen)};
        largestBlue = getLargest("blue", line);
        largestRed = getLargest("red", line);
        largestGreen = getLargest("green", line);
        pGame->setGameNo(gameNo);
        pGame->setColorCount(largestBlue, largestRed, largestGreen);
        gameVec.push_back(*pGame);
    }

    for (auto& elem : gameVec) {
        // 12 red, 13 green, 14 blue
        if (elem.getColorCount("red") <= 12 &&
            elem.getColorCount("green") <= 13 &&
            elem.getColorCount("blue") <= 14) {
            count += elem.getGameNo();
        }
    }

    return count;
}

int assignment2() {
    std::ifstream myFile("input.txt");
    std::string line;
    int gameNo = 0, largestBlue = 0, largestRed = 0, largestGreen = 0,
        count = 0;
    std::vector<Game> gameVec;

    while (std::getline(myFile, line)) {
        gameNo++;
        std::unique_ptr<Game> pGame{
            new Game(gameNo, largestBlue, largestRed, largestGreen)};
        largestBlue = getLargest("blue", line);
        largestRed = getLargest("red", line);
        largestGreen = getLargest("green", line);
        pGame->setGameNo(gameNo);
        pGame->setColorCount(largestBlue, largestRed, largestGreen);
        gameVec.push_back(*pGame);
    }

    for (auto& elem : gameVec) {
        count += elem.getColorCount("red") * elem.getColorCount("green") *
                 elem.getColorCount("blue");
    }

    return count;
}

int main() {
    std::cout << assignment1() << std::endl;
    std::cout << assignment2() << std::endl;
    return 0;
}
