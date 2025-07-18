#include <bits/stdc++.h>

using namespace std;

class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> freqNums2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2)
            freqNums2[num]++;
    }
    
    void add(int index, int val) {        
        freqNums2[nums2[index]]--;
        nums2[index] += val;
        freqNums2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int num : nums1) {
            if (freqNums2.count(tot - num))
                ans += freqNums2[tot - num];
        }
        return ans;
    }
};

int main(){
    return 0;
}