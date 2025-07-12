#include <bits/stdc++.h>

using namespace std;

class Solution {    
private:
    int n, firstPlayer, secondPlayer;
    bool players[28];
    vector<int> ans = {INT_MAX, 1};

    void Search(int left, int right, int round = 1) {              
        if (left >= right) 
            Search(0, n - 1, round + 1);                                                        
        else if (!players[left])
            Search(left + 1, right, round);
        else if (!players[right])
            Search(left, right - 1, round);
        else if (firstPlayer == left && secondPlayer == right) {
            ans[0] = min(ans[0], round);
            ans[1] = max(ans[1], round);            
        }        
        else if (firstPlayer == left || secondPlayer == left) {
            players[right] = false;    
            Search(left + 1, right - 1, round);
            players[right] = true;
        }                            
        else if (firstPlayer == right || secondPlayer == right) {
            players[left] = false;
            Search(left + 1, right - 1, round);
            players[left] = true;
        }            
        else {
            players[right] = false;    
            Search(left + 1, right - 1, round);
            players[right] = true;
            players[left] = false;
            Search(left + 1, right - 1, round);
            players[left] = true;
        }        
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        this->n = n;
        this->firstPlayer = firstPlayer - 1;
        this->secondPlayer = secondPlayer - 1;
        memset(players, true, n);  
        Search(0, n - 1);
        
        return ans;
    }
};

int main() {
    Solution s;
    s.earliestAndLatest(11, 2, 4);
    return 0;
}