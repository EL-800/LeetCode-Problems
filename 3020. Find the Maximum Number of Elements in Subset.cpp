#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {        
        map<long long, int> numbersBucket;

        for (int num : nums) 
            numbersBucket[num]++;        
        
        int ans = numbersBucket[1] - (numbersBucket[1] + 1) % 2;       
        for (auto &[num, count] : numbersBucket) {
            if (num == 1)
                continue;

            long long curr = num;
            int size = 0;
            while (numbersBucket.count(curr) && numbersBucket[curr] != -1) {                
                if (numbersBucket[curr] == 1 || !numbersBucket.count(curr * curr)) {
                    ans = max(ans, size + 1);
                    numbersBucket[curr] = -1;
                    break;                    
                }                
                size += 2;   
                numbersBucket[curr] = -1; 
                curr *= curr;                                                                            
            }
        }
        
        return ans;
    }
};

int main() {
    return 0;
}