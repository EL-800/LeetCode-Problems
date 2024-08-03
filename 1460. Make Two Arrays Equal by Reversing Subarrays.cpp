#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> bucket(1001);
        for (int num : arr)
            bucket[num]++;
        for (int num : target)
            bucket[num]--;    
        return all_of(bucket.begin(), bucket.end(), [](int num) {return num == 0;});    
    }
};

int main() {
    return 0;
}