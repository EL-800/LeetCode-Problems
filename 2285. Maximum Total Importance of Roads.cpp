#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> appears(n);
        for (auto road : roads) {
            appears[road[0]]++;
            appears[road[1]]++;
        }
        sort(appears.begin(), appears.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) 
            ans += (long long)appears[i] * (long long)(i + 1);
        return ans;                    
    }
};

int main(){
    return 0;
}