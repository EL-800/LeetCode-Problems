#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<string>> ans;

    bool isPalindrome(string& s){
        int left = 0, right = s.length() - 1;
        while (left < right){
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void Search(string &s, vector<string>& partition, string currS = "", int ind = 0){
        if (ind == s.length()){
            if (currS == "")
                ans.push_back(partition);
            return;
        }      
        currS += s[ind];
        if (isPalindrome(currS)) {
            partition.push_back(currS);
            Search(s, partition, "", ind + 1);
            partition.pop_back();
        }
        Search(s, partition, currS, ind + 1);          
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        Search(s, partition);
        return ans;
    }
};

int main(){
    return 0;
}