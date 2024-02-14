#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> negatives, positives;
        for (int num : nums){
            if (num < 0)
                negatives.push_back(num);
            else
                positives.push_back(num);
        }
        vector<int> rearrengedNum;        
        for (int i = 0; i < negatives.size(); i++){
            rearrengedNum.push_back(positives[i]);
            rearrengedNum.push_back(negatives[i]);
        }
        return rearrengedNum;
    }
};

int main(){
    return 0;
}