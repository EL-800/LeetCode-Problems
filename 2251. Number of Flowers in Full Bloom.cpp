#include <bits/stdc++.h>

using namespace std;

class Solution {    
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> sweepLine;
        for (auto range : flowers){
            sweepLine[range[0]]++;
            sweepLine[range[1] + 1]--;
        }
        int n = people.size();
        vector<pair<int, int>> mappedPeople;
        for (int i = 0; i < n; i++)
            mappedPeople.push_back({people[i], i});
        sort(mappedPeople.begin(), mappedPeople.end());
        int i = 0, curr = 0;
        vector<int> ans(n);
        for (auto flower : sweepLine){
            while (i < n && mappedPeople[i].first < flower.first){
                ans[mappedPeople[i].second] = curr;
                i++;
            }
            curr += flower.second;
        }
        return ans;         
    }
};

int main(){
    return 0;
}