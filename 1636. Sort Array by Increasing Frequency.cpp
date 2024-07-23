#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;
        vector<pair<int, int>> valFreq;
        for (auto f : freq) 
            valFreq.push_back(f);        
        sort(valFreq.begin(), valFreq.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        });
        vector<int> ans;
        for (auto vF : valFreq) {
            while (vF.second--)
                ans.push_back(vF.first);
        }
        return ans;
    }
};

int main() {
    return 0;
}