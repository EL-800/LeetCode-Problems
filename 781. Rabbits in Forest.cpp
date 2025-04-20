#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {            
            unordered_map<int, int> seen;
            for (int ans : answers) 
                seen[ans]++;        
            int n = 0;
            for (auto [key, val] : seen)
                n += (key + 1) * (val / (key + 1) + (val % (key + 1) != 0));                                
            return n;
        }
    };

int main() {
    return 0;
}