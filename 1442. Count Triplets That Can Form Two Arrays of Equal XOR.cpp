#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, pair<int, int>> mapCount;
        int curr = 0, ans = 0;        
        for (int i = 0; i < arr.size(); i++){
            curr ^= arr[i];
            if (!curr)
                ans += i;
            if (mapCount.count(curr)){
                auto [count, indexSum] = mapCount[curr];
                ans += count * i - count - indexSum;
            }
            mapCount[curr].first++;
            mapCount[curr].second += i;
        }
        return ans;
    }
};

int main(){
    return 0;    
}