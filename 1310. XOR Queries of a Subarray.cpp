#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans, prefixXor(n + 1);        
        for (int i = 1; i <= n; i++)
            prefixXor[i] = prefixXor[i - 1] ^ arr[i - 1];
        for (auto query : queries) 
            ans.push_back(prefixXor[query[1] + 1] ^ prefixXor[query[0]]);        
        return ans;
    }
};

int main() {
    return 0;
}