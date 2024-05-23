#pragma once
#include "ReadFile.hpp"
#include "utils.hpp"

class Network {
    std::map<std::string, std::pair<std::string, std::string>> map_;
    std::string node_;
    std::pair<std::string, std::string> route_;
   public:
    Network(std::string node, std::pair<std::string, std::string> route) : node_(node), route_(route) {
        map_[node_] = route_;
    }
    ~Network() = default;
    std::string getNode(){ return node_; }
    std::string getLeft(){ return route_.first; }
    std::string getRight(){ return route_.second; }
};
