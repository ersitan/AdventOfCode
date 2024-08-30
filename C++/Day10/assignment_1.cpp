#include "includes.hpp"

std::pair<size_t, size_t> findPosS(std::vector<std::string> &v)
{
    int lineNo = 0;
    for (auto line : v)
    {
        size_t pos = line.find('S');
        if (pos != line.npos)
        {
            return std::pair<int, size_t>(lineNo, pos);
        }
        lineNo++;
    }
    return std::pair<int, size_t>(0, 0);
}

char defineS(std::vector<std::string> &v, std::pair<size_t, size_t> &posS)
{
    char up, left, right, down;
    if (v[posS.first - 1][posS.second] != '.')
    {
        up = v[posS.first - 1][posS.second];
    }
    if (v[posS.first + 1][posS.second] != '.')
    {
        down = v[posS.first + 1][posS.second];
    }
    if (v[posS.first][posS.second - 1] != '.')
    {
        left = v[posS.first][posS.second - 1];
    }
    if (v[posS.first][posS.second + 1] != '.')
    {
        right = v[posS.first][posS.second + 1];
    }

    if (up && right)
    {
        return 'L';
    }
    else if (up && left)
    {
        return 'J';
    }
    else if (up && down)
    {
        return '|';
    }
    else if (right && down)
    {
        return 'F';
    }
    else if (right && left)
    {
        return '-';
    }
    else if (left && down)
    {
        return '7';
    }
}

char findNext(std::vector<std::string> &v, char c, std::pair<size_t, size_t> pos, std::string comingFrom, uint64_t& count)
{
    char newChar;
    std::pair<size_t, size_t> newCharPos;
    std::string newCharComingFrom;
    if (c == 'F')
    {
        if (comingFrom == "down")
        {
            newCharPos = std::make_pair(pos.first, pos.second + 1);
            newCharComingFrom = "left";
        }
        else if(comingFrom == "right")
        {
            newCharPos = std::make_pair(pos.first+1, pos.second);
            newCharComingFrom = "up";
        }
    }
    else if (c == 'L')
    {
        if (comingFrom == "right")
        {
            newCharPos = std::make_pair(pos.first-1, pos.second);
            newCharComingFrom = "down";
        }
        else if(comingFrom == "up")
        {
            newCharPos = std::make_pair(pos.first, pos.second+1);
            newCharComingFrom = "left";
        }        
    }
    else if (c == '|')
    {
        if (comingFrom == "up")
        {
            newCharPos = std::make_pair(pos.first+1, pos.second);
            newCharComingFrom = "up";
        }
        else if(comingFrom == "down")
        {
            newCharPos = std::make_pair(pos.first-1, pos.second);
            newCharComingFrom = "down";
        }        
    }
    else if (c == 'J')
    {
        if (comingFrom == "left")
        {
            newCharPos = std::make_pair(pos.first-1, pos.second);
            newCharComingFrom = "down";
        }
        else if(comingFrom == "up")
        {
            newCharPos = std::make_pair(pos.first, pos.second-1);
            newCharComingFrom = "right";
        }        
    }
    newChar = v[newCharPos.first][newCharPos.second];
        count++;
    if (newChar != 'S')
    {
        return findNext(v, newChar, newCharPos, newCharComingFrom, count);
    }
    return 'S';
}

int main()
{
    ReadFile rf("input2.txt");
    std::vector<std::string> vec = rf.getLinesVector();
    uint64_t count = 0;
    auto posS = findPosS(vec);
    char s = defineS(vec, posS);
    return 0;
}