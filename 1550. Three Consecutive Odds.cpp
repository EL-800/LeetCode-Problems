#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int k = 3, count = 0, left = 0, right = 0;        
        if (arr.size() < k)
            return false;
        for (; right < k; right++)
            count += arr[right] % 2 == 1;
        if (count == k)
            return true;
        for (; right < arr.size(); left++, right++) {
            count += arr[right] % 2 == 1;
            count -= arr[left] % 2 == 1;
            if (count == k)
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}