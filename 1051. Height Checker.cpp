#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ordereded(heights.begin(), heights.end());
        sort(ordereded.begin(), ordereded.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); i++){
            if (heights[i] != ordereded[i])
                ans++;
        }
        return ans;
    }
};

int main(){
    return 0;
}