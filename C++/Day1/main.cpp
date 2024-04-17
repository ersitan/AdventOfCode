#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int replaceDigits(std::string& str, std::map<std::string, char>& map) {
  std::string output;
  std::map<std::size_t, char> newMap;
  for (size_t i = 0; i <= str.size(); i++) {
    char c = str[i];
    if (isdigit(c)) {
      newMap.emplace(i, c);
    }
  }

  for (auto it = map.begin(); it != map.end(); it++) {
    auto pos = str.find(it->first);
    while (pos != std::string::npos) {
      newMap.emplace(pos, it->second);
      pos = str.find(it->first, pos + it->first.size());
    }
  }

  if (newMap.rbegin() != newMap.rend()) {
    std::string val;
    val.push_back(newMap.begin()->second);
    val.push_back(newMap.rbegin()->second);
    
    //std::cout << val << '\n';
    
    return stoi(val);
  }
  return 0;
}

int main() {
  std::ifstream myFile("input.txt");
  std::string line, first, last;
  std::vector<int> digits;
  std::map<std::string, char> digitMap = {
      {"zero", '0'},  {"one", '1'},  {"two", '2'}, {"three", '3'},
      {"four", '4'},  {"five", '5'}, {"six", '6'}, {"seven", '7'},
      {"eight", '8'}, {"nine", '9'},
  };
  int count = 0;
  while (myFile >> line) {
    count += replaceDigits(line, digitMap);
    //std::cout << count << std::endl;
  }

  std::cout << count << std::endl;

  return 0;
}
