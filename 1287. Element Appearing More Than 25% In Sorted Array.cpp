#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int obj = arr.size() / 4;
        int streakVal = -1, streak = 0;
        for (int curr : arr){
            if (streakVal == curr)
                streak++;
            else {
                streakVal = curr;
                streak = 1;
            }
            if (streak > obj)
                return streakVal;
        }                
        return -1;
    }
};

int main(){
    return 0;
}