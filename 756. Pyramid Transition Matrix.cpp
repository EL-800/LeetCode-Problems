#include <bits/stdc++.h>

using namespace std;

class Solution {
private:        
    vector<vector<vector<char>>> bucketAlloweds;

    void NextRow(vector<string> &possibleNext, string &base, string &next, int ind = 0) {
        if (next.length() + 1 == base.length()) {
            possibleNext.push_back(next);
            return;
        }
        
        int left = base[ind] - 'A', right = base[ind + 1] - 'A';
        if (bucketAlloweds[left][right].empty())
            return;
        for (char c : bucketAlloweds[left][right]) {
            next.push_back(c);
            NextRow(possibleNext, base, next, ind + 1);
            next.pop_back();
        }                    
    }

    bool Search(string &curr) {
        if (curr.length() == 1)
            return true;
        vector<string> possibleNext;
        string aux;        
        NextRow(possibleNext, curr, aux);
        
        for (auto &next : possibleNext) {
            if (Search(next))
                return true;            
        }                  

        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {        
        bucketAlloweds.assign(26, vector<vector<char>>(26));

        for (auto &a : allowed) {            
            int left = a[0] - 'A', right = a[1] - 'A', top = a[2];
            bucketAlloweds[left][right].push_back(top);
        }

        return Search(bottom);

    }
};

int main() {
    Solution s;
    vector<string> c = {"BCC","CDE","CEA","FFF"};
    cout << s.pyramidTransition("BCD", c);
    return 0;
}