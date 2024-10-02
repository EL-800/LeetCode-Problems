#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> ranks;
        vector<int> sorted = arr;        
        sort(sorted.begin(), sorted.end());
        int rank = 1, prevNum = INT_MIN;
        for (int num : sorted) {
            if (prevNum != num)
                ranks[num] = rank++;
            prevNum = num;
        }
        vector<int> ans;
        for (int num : arr) 
            ans.push_back(ranks[num]);
        return ans;
    }
};

int main() {
    return 0;
}