#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "utils.h"

using namespace std;

void day01_part1(vector<string> input)
{
    cout << "day 01 part 1";
    vector<int> as;
    vector<int> bs;
    for (auto it = input.begin(); it != input.end(); it++)
    {
        int a, b;
        stringstream ss(*it);
        ss >> a;
        ss >> b;
        as.push_back(a);
        bs.push_back(b);
    }
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    int similarity = 0;
    for (auto a = as.begin(), b = bs.begin(); a != as.end() && b != bs.end(); a++, b++)
    {
        similarity += abs(*b - *a);
    }
    cout << " : " << similarity << endl;
}
void day01_part2(vector<string> input)
{
    cout << "day 01 part 2";
    vector<int> as;
    vector<int> bs;
    for (auto it = input.begin(); it != input.end(); it++)
    {
        int a, b;
        stringstream ss(*it);
        ss >> a;
        ss >> b;
        as.push_back(a);
        bs.push_back(b);
    }
    sort(as.begin(), as.end());
    map<int, int> histogram;
    for (auto ap = as.begin(); ap != as.end(); ap++)
    {
        auto a = *ap;
        histogram[a] = count(bs.begin(), bs.end(), a);
    }

    int similarity = 0;
    for (auto ap = as.begin(); ap != as.end(); ap++)
    {
        auto a = *ap;
        similarity += a * histogram[a];
    }
    cout << " : " << similarity << endl;
}
void day01()
{
    vector<string> input = readFileLines("data/day01.txt");
    day01_part1(input);
    day01_part2(input);
}
