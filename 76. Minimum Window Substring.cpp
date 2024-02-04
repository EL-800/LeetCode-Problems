#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool Validation(vector<int>& currWindow, vector<int>& objWindow) {
        for (int i = 0; i <= 'z'; i++) {
            if (currWindow[i] < objWindow[i])
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        vector<int> currWindow(int('z' + 1)), objWindow(int('z' + 1));
        s = s + ',';
        int n = s.size(), m = t.size();
        int left = 0, right = 0, ansSize = INT_MAX, bestLeft = 0, bestRight = 0;        
        for (char i : t)
            objWindow[i]++;
        while (right < n) {
            if (Validation(currWindow, objWindow)) {
                int currSize = right - left;
                if (currSize < ansSize) {
                    ansSize = currSize;
                    bestLeft = left;
                    bestRight = right;
                }
                currWindow[s[left]]--;
                left++;
            }
            else {
                currWindow[s[right]]++;
                right++;
            }            
        }
        string ans;
        for (int i = bestLeft; i < bestRight; i++)
            ans += s[i];
        return ans;
    }
};

int main(){

}