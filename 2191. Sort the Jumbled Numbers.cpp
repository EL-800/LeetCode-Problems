#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> numsInd;
        for (int i = 0; i < nums.size(); i++)
            numsInd.push_back({nums[i], i});
        sort(numsInd.begin(), numsInd.end(), [&](pair<int, int>& aI, pair<int, int>& bI){            
            int a = aI.first, b = bI.first, mappedA = 0, mappedB = 0, exp = 0;
            if (!a)
                mappedA = mapping[a];
            else {
                while (a) {
                    int mappedD = mapping[a % 10];
                    mappedA += mappedD * pow(10, exp++);
                    a /= 10;
                }
            }
            exp = 0;
            if (!b)
                mappedB = mapping[b];
            else {
                while (b) {
                    int mappedD = mapping[b % 10];
                    mappedB += mappedD * pow(10, exp++);
                    b /= 10;
                }
            }
            if (mappedA == mappedB)
                return aI.second < bI.second;
            return mappedA < mappedB;
        });
        vector<int> ans;
        for (auto i : numsInd)
            ans.push_back(i.first);
        return ans;
    }
};

int main() {
    return 0;
}