#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "utils.h"

using namespace std;

vector<vector<int>> makeReports(vector<string> lines)
{
    vector<vector<int>> reports;
    for (auto it = lines.begin(); it != lines.end(); it++)
    {
        reports.push_back(toInts(parseCommaSeparated(*it)));
    }
    return reports;
}
vector<int> makeReportDeltas(vector<int> report)
{
    vector<int> deltas;
    for (int i = 0; i < report.size() - 1; i++)
    {
        int diff = report[i + 1] - report[i];
        deltas.push_back(diff);
    }
    return deltas;
}
int sign(int i)
{
    if (i < 0)
        return -1;
    if (i > 0)
        return 1;
    return 0;
}
bool isSafe(vector<int> report)
{
    vector<int> deltas = makeReportDeltas(report);
    int direction = 0;
    for (auto it = deltas.begin(); it != deltas.end(); it++)
    {
        if (direction == 0)
            direction = sign(*it);
        if (direction != sign(*it))
            return false;
        if (abs(*it) < 1)
            return false;
        if (abs(*it) > 3)
            return false;
    }
    return true;
}
vector<vector<int>> filterSafeReports(vector<vector<int>> reports)
{
    vector<vector<int>> safeReports;
    for (auto it = reports.begin(); it != reports.end(); it++)
    {
        if (isSafe(*it))
            safeReports.push_back(*it);
    }
    return safeReports;
}
vector<vector<int>> filterUnsafeReports(vector<vector<int>> reports)
{
    vector<vector<int>> unsafeReports;
    for (auto it = reports.begin(); it != reports.end(); it++)
    {
        if (!isSafe(*it))
            unsafeReports.push_back(*it);
    }
    return unsafeReports;
}
vector<int> makePermutation(int i, vector<int> report)
{
    vector<int> permutation = report;
    permutation.erase(permutation.begin() + i);
    return permutation;
}
vector<vector<int>> makePermutations(vector<int> report)
{
    vector<vector<int>> permutations;
    for (auto i = 0; i < report.size(); i++)
    {
        permutations.push_back(makePermutation(i, report));
    }
    return permutations;
}
vector<vector<int>> filterFixableReports(vector<vector<int>> reports)
{
    vector<vector<int>> fixableReports;
    for (auto it = reports.begin(); it != reports.end(); it++)
    {
        vector<vector<int>> permutations = makePermutations(*it);
        vector<vector<int>> safePermutations = filterSafeReports(permutations);

        if (safePermutations.size() > 0)
            fixableReports.push_back(*it);
    }
    return fixableReports;
}
void day02_part1(vector<string> input)
{
    cout << "day 02 part 1";
    vector<vector<int>> reports = makeReports(input);
    vector<vector<int>> safeReports = filterSafeReports(reports);

    cout << " : " << safeReports.size() << endl;
}
void day02_part2(vector<string> input)
{
    cout << "day 02 part 2";
    vector<vector<int>> reports = makeReports(input);
    vector<vector<int>> safeReports = filterSafeReports(reports);
    vector<vector<int>> unsafeReports = filterUnsafeReports(reports);
    vector<vector<int>> fixableReports = filterFixableReports(unsafeReports);

    cout << " : " << safeReports.size() + fixableReports.size() << endl;
}
void day02()
{
    vector<string> input = readFileLines("data/day02.txt");
    day02_part1(input);
    day02_part2(input);
}
