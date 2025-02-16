#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:   
        int n;
    
        bool Search(vector<int> &sequence, int ind = 0) {
            if (ind == sequence.size())
                return true;
            if (sequence[ind])
                return Search(sequence, ind + 1);
            for (int i = n; i >= 2; i--) {                
                if (count(sequence.begin(), sequence.end(), i))
                    continue;
                if (ind + i >= sequence.size())
                    return false;
                if (sequence[ind + i])
                    continue;
                sequence[ind] = i;
                sequence[ind + i] = i;
                if (Search(sequence, ind + 1))
                    return true;                
                sequence[ind] = 0;
                sequence[ind + i] = 0;
            }
            if (count(sequence.begin(), sequence.end(), 1))
                return false;
            sequence[ind] = 1;
            if (Search(sequence, ind + 1))
                return true;
            sequence[ind] = 0;
            return false;
        }

    public:
        vector<int> constructDistancedSequence(int n) {
            vector<int> ans(n * 2 - 1);
            this->n = n;
            Search(ans);
            return ans;
        }
    };

int main() {
    Solution s;
    s.constructDistancedSequence(3);
    return 0;
}