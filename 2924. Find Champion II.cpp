#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> degreeCount(n);
        for (auto edge : edges) 
            degreeCount[edge[1]]++;        
        return count(degreeCount.begin(), degreeCount.end(), 0) == 1 ? find(degreeCount.begin(), degreeCount.end(), 0) - degreeCount.begin() : -1;
    }
};

int main() {
    return 0;
}