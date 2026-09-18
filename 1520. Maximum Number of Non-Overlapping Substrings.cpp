#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<pair<int, int>> intervals(26, {1e9, -1});        
        
        for(int i = 0; i < n; i++){
            int c = s[i] - 'a';
            intervals[c].first = min(intervals[c].first, i);
            intervals[c].second = i;                        
        }                

        vector<pair<int, int>> cleanIntervals;
        for(int i = 0; i < 26; i++){
            if(intervals[i].second == -1) 
                continue;   
            bool flag = true;
            int left = intervals[i].first, right = intervals[i].second;            
            for(int i = left; i <= right; i++){
                int c = s[i] - 'a';                
                if(intervals[c].first < left){
                    flag = false;
                    break;
                }                
                right = max(right, intervals[c].second);
            }      
            if (flag)                                   
                cleanIntervals.push_back({right, left});
        }
        
        sort(cleanIntervals.begin(), cleanIntervals.end());        

        vector<string> ans;
        int prevEnd = -1;
        for(auto &[r, l] : cleanIntervals){
            if(l > prevEnd){
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}