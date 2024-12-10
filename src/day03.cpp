#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <regex>

#include "utils.h"

using namespace std;

vector<tuple<int, int>> getPairs(vector<string> input, bool force = true)
{
    vector<tuple<int, int>> pairs = vector<tuple<int, int>>();
    bool doingIt = true;
    regex mulRegex("(mul)\\((\\d+),(\\d+)\\)|(do)\\(\\)|(don't)\\(\\)");
    for (auto pInput = input.begin(); pInput != input.end(); pInput++)
    {
        sregex_iterator regexBegin = {
            pInput->begin(),
            pInput->end(),
            mulRegex};
        sregex_iterator regexEnd;
        for (auto pMatch = regexBegin; pMatch != regexEnd; pMatch++)
        {
            if (pMatch->str() == "do()")
                doingIt = true;
            if (pMatch->str() == "don't()")
                doingIt = false;
            if ((force || doingIt) && pMatch->str(1) == "mul")
            {
                tuple<int, int> pair = {stoi(pMatch->str(2)), stoi(pMatch->str(3))};
                pairs.push_back(pair);
            }
        }
    }
    return pairs;
}
void day03_part1(vector<string> input)
{
    int sum = 0;
    vector<tuple<int, int>> pairs = getPairs(input);
    for (auto pPair = pairs.begin(); pPair != pairs.end(); pPair++)
    {
        auto [a, b] = *pPair;
        sum += a * b;
    }
    cout << "day 02 part 1 : " << sum << endl;
}
void day03_part2(vector<string> input)
{
    int sum = 0;
    vector<tuple<int, int>> pairs = getPairs(input, false);
    for (auto pPair = pairs.begin(); pPair != pairs.end(); pPair++)
    {
        auto [a, b] = *pPair;
        sum += a * b;
    }
    cout << "day 02 part 2 : " << sum << endl;
}
void day03()
{
    vector<string> input = readFileLines("data/day03.txt");
    day03_part1(input);
    day03_part2(input);
}
