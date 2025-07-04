#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int rotate=0;

        while(k > 1){
            long long range = log2(k), mid = 1ll << range;
            if(mid == k){
                range--;
                mid = 1ll << range;
            }            
            k -= mid;            
            if(operations[range])
                rotate++;
        }
        return 'a' + (rotate % 26);
    }
};

int main() {
    return 0;
}