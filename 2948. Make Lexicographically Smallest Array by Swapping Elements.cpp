#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> indexedNums, currGroup;
    vector<int> ans;

    inline void SortGroup() {        
        vector<int> indexes;
            for (auto [val, ind] : currGroup)
                indexes.push_back(ind);
            sort(indexes.begin(), indexes.end());
            for (int j = 0; j < currGroup.size(); j++) 
                ans[indexes[j]] = currGroup[j].first;  
            currGroup.clear();                                          
    }

public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {        
        int n = nums.size(); 
        ans.resize(n);                       
        for (int i = 0; i < n; i++)
            indexedNums.push_back({nums[i], i});
        sort(indexedNums.begin(), indexedNums.end());        
        int lastVal = indexedNums[0].first;
        for (int i = 0; i < n; i++) {            
            if (indexedNums[i].first - lastVal > limit)
                SortGroup();
            currGroup.push_back(indexedNums[i]);
            lastVal = indexedNums[i].first;
        }
        SortGroup();
        return ans;
    }
};

int main() {
    return 0;
}