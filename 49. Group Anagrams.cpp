#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramsSet;
        for (string str : strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            anagramsSet[sorted].push_back(str);
        }
        vector<vector<string>> ans;        
        for (auto set : anagramsSet)
            ans.push_back(set.second);        
        return ans;
    }
};

int main(){
    return 0;
}