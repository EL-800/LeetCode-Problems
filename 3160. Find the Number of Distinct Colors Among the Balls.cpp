#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> paintedPos;
        unordered_map<int, int> paintCount;
        vector<int> ans;                
        for (auto query : queries) {
            if (paintCount.count(paintedPos[query[0]])) {
                paintCount[paintedPos[query[0]]]--;
                if (!paintCount[paintedPos[query[0]]])
                    paintCount.erase(paintedPos[query[0]]);
            }
            paintedPos[query[0]] = query[1];   
            paintCount[paintedPos[query[0]]]++;        
            ans.push_back(paintCount.size()); 
        }
        return ans;
    }
};

int main() {
    return 0;
}