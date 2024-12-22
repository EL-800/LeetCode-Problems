#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {        
        vector<vector<int>> indexedQueries;        
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            if (x > y)
                swap(x, y);
            if (x == y || heights[x] < heights[y])
                ans[i] = y;
            else
                indexedQueries.push_back({y, x, i});        
        }
        sort(indexedQueries.rbegin(), indexedQueries.rend());        
        int hInd = heights.size() - 1;        
        vector<vector<int>> stack;
        for (auto query : indexedQueries) {
            int y = query[0], x = query[1], i = query[2];
            cout << x << " " << y << " " << i << "\n";
            while (hInd >= y) {                
                while(!stack.empty() && heights[hInd] >= stack.back()[0])
                    stack.pop_back();
                stack.push_back({heights[hInd], hInd});
                hInd--;
            }
            for (auto a : stack)
                cout << a[0] << " ";
            cout << "\n";
            auto it = upper_bound(stack.rbegin(), stack.rend(), vector<int>({heights[x], 0}));
            ans[i] = it != stack.rend() ? (*it)[1] : -1;
        }
        return ans;
    }
};

int main() {
    return 0;
}