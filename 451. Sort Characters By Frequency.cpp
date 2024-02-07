#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ocurrences;
        string ans;
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> mostOcurrences(cmp);
        for (char i : s)
            ocurrences[i]++;
        for (pair<char, int> i : ocurrences)
            mostOcurrences.push(i);
        while (!mostOcurrences.empty()) {
            pair<char, int> curr = mostOcurrences.top();
            mostOcurrences.pop();
            while (curr.second--)
                ans += curr.first;
        }
        return ans;
    }
};

int main(){
    return 0;
}