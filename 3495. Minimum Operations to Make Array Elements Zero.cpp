#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfDivisions(int right) {
        long long currPower = 3, lastPower = 1, count = 0, add = 1;
        while (currPower <= right) {
            count += (currPower - lastPower + 1) * add;
            add++;
            lastPower = currPower + 1;
            currPower = (currPower + 1) * 4 - 1;            
        }
        return count + add * (right - lastPower + 1);  
    }

    long long minOperations(vector<vector<int>>& queries) {
        int ans = 0;        
        for (auto query : queries) {
            ans += (numberOfDivisions(query[1]) - numberOfDivisions(query[0] - 1) + 1) / 2;
        }
        return ans;
    }
};

int main() {
    return 0;
}