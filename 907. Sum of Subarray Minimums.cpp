#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int, int>> mins;
        const int mod = (int)1e9 + 7;
        int ans = 0, currSum = 0;
        for (int curr : arr){
            int size = 1;
            while(!mins.empty() && mins.top().first > curr){
                currSum -= mins.top().first * mins.top().second;
                size += mins.top().second;
                mins.pop();                
            }        
            mins.push({curr, size});
            currSum = (currSum + (curr * size % mod)) % mod;
            ans = (ans + currSum) % mod;
        }
        return ans;
    }
};

int main(){
    return 0;
}