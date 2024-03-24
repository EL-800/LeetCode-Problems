#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2, count = 0;
            for (int i : nums) {
                if (i <= mid)
                    count++;
            }
            if (count <= mid)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main(){
    return 0;
}