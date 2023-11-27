#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        ans.push_back(pref.front());
        for (int i = 1; i < pref.size(); i++)
            ans.push_back(pref[i] xor pref[i - 1]);
        return ans;
    }
};

int main(){
    return 0;
}