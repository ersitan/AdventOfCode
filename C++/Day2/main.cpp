#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

struct Game{
    int gameNo, blueCount, greenCount, redCount;
};

int main() {
  std::ifstream myFile("input.txt");
  std::string line;
  //std::map<int, std::pair<std::string, int>> myMap;
  int gameNo = 0;
  
  while (myFile >> line) {
    	gameNo++;

  }
  return 0;
}
