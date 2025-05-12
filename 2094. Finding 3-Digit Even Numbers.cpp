#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> globalCount(10), ans;
        for (int digit : digits)
            globalCount[digit]++;
        for (int i = 100; i <= 999; i += 2) {
            int num = i;
            bool possible = true;
            vector<int> currCount = globalCount;            
            while (num) {
                int digit = num % 10;
                currCount[digit]--;
                if (currCount[digit] < 0) {
                    possible = false;
                    break;      
                }  
                num /= 10;
            }
            if (possible)
                ans.push_back(i);            
        }
        return ans;
    }
};

int main() {
    return 0;
}