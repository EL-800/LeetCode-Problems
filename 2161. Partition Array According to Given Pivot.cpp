#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int pivotCount = 0;
            vector<int> left, right;
            for (int num : nums) {
                if (num < pivot)
                    left.push_back(num);
                else if (num > pivot)
                    right.push_back(num);
                else
                    pivotCount++;
            }
            left.insert(left.end(), pivotCount, pivot);
            left.insert(left.end(), right.begin(), right.end());            
            return left;
        }
    };

int main() {
    return 0;
}