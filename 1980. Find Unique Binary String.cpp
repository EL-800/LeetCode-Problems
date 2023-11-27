#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {    
private:
    int n;
    string FindString(unordered_set<string>& bucket, string s = ""){
        if (s.length() == n)
            return !bucket.count(s) ? s : "";
        string left = FindString(bucket, s + '0');
        if (left != "")
            return left;
        string right = FindString(bucket, s + '1');
        if (right != "")
            return right;
        return "";
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> bucket(nums.begin(), nums.end());
        n = nums[0].length();
        return FindString(bucket);
    }
};

int main(){
    return 0;
}