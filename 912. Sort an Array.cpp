#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void Merge(vector<int>& nums, int left, int right, int mid) {        
        vector <int> aux;        
        int i = left, j = mid;
        while (i < mid && j <= right) {
            if (nums[i] < nums[j])
                aux.push_back(nums[i++]);
            else
                aux.push_back(nums[j++]);
        }
        while (i < mid)
            aux.push_back(nums[i++]);
        while (j <= right)
            aux.push_back(nums[j++]);
        for (int l = left; l <= right; l++)
            nums[l] = aux[l - left];
    }

    void Sort(vector<int>& nums, int left, int right) {
        if (left == right)
            return;
        int mid = (left + right) / 2 + 1;
        Sort(nums, left, mid - 1);
        Sort(nums, mid, right);
        Merge(nums, left, right, mid);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        Sort(nums, 0, nums.size() - 1);
        return nums;
    }
};


int main() {
    return 0;
}