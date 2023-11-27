#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end(), [](int a, int b){
            if (__builtin_popcount(a) == __builtin_popcount(b))
                return a < b;
            return __builtin_popcount(a) < __builtin_popcount(b);
        });
        return sorted;
    }
};

int main(){
    return 0;
}