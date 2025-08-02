#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {        
        unordered_map<int, int> countBascket1, countBascket2;
        for (int fruit : basket1) {            
            countBascket1[fruit]++;   
            countBascket2[fruit] = 0;         
        }
        for (int fruit : basket2) {
            if (!countBascket1.count(fruit))            
                countBascket1[fruit] = 0;
            countBascket2[fruit]++;
        }

        int minFruit = INT_MAX;
        for (auto &[fruit, count] : countBascket1) {
            if ((countBascket1[fruit] + countBascket2[fruit]) % 2) 
                return -1;
            minFruit = min(minFruit, fruit);
        }
        
        vector<int> pendingSwaps;               
        for (auto &[fruit, count] : countBascket1) {
            int countObj = (countBascket1[fruit] + countBascket2[fruit]) / 2;
            int diff = abs(countBascket1[fruit] - countObj);            
            while (diff--) 
                pendingSwaps.push_back(fruit);                                    
        }        
        sort(pendingSwaps.begin(), pendingSwaps.end());
        
        long long ans = 0;
        int swapsN = pendingSwaps.size() / 2;
        for (int i = 0; i < swapsN; i++) 
            ans += min((long)pendingSwaps[i], 2L * (long)minFruit);        
        
        return ans;
    }
};

int main() {
    return 0;
}