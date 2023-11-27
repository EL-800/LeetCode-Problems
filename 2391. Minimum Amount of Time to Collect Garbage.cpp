#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int CollectGarbage(vector<string>& garbage, vector<int>& travel, char garCollect) {
        int ans = 0, currTrans = 0;
        for (int i = 0; i < garbage.size(); i++){
            int garAmount = count(garbage[i].begin(), garbage[i].end(), garCollect);
            if (garAmount) {
                ans += currTrans + garAmount;
                currTrans = 0;
            }
            currTrans += travel[i];
        }
        return ans;
    }

public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        travel.push_back(0);
        return CollectGarbage(garbage, travel, 'M') + CollectGarbage(garbage, travel, 'P') + CollectGarbage(garbage, travel, 'G');
    }
};

int main(){
    return 0;
}