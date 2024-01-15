#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> loseControl;
        vector<vector<int>> ans(2);
        for (auto i : matches) {
            loseControl[i[1]]++;
            if (loseControl.find(i[0]) == loseControl.end())
                loseControl[i[0]] = 0;
        }
        for (auto i : loseControl) {
            if (!i.second)
                ans[0].push_back(i.first);
            else if (i.second == 1)
                ans[1].push_back(i.first);
        }
        return ans;
    }
};

int main(){
    return 0;
}