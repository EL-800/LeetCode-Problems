#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long bias = 1 << 18, shift = 32;

    long long encode(int x, int y){        
        return ((long long)(x+bias) << shift) | (long long)(y + bias);
    }

    int checkOne(string &s, int n){
        int best = 1, curr = 1;
        for(int i = 1; i < n; i++){
            if (s[i] == s[i - 1]) 
                curr++;
            else {
                best = max(best, curr);
                curr = 1;
            }
        }
        return max(best, curr);
    }        

    int longestBalanced(string &s) {
        int n = s.size(), ans = checkOne(s, n);
        long long initialState = encode(0, 0);

        unordered_map<long long, int> ab, bc, ca, abc;
        
        ab.reserve(n), bc.reserve(n), ca.reserve(n), abc.reserve(n);        
        abc[initialState] = -1;
        ab[initialState] = -1; 
        bc[initialState] = -1; 
        ca[initialState] = -1; 
    
        vector<int> characterCount(3);
        for (int i = 0; i < n; i++){
            characterCount[s[i] - 'a']++; 
            int countA = characterCount[0], countB = characterCount[1], countC = characterCount[2];
            
            long long key = encode(countB - countA, countC - countA);
            auto it = abc.find(key);
            if (it != abc.end()) 
                ans=max(ans, i-it->second);
            else 
                abc[key] = i;
            
            key = encode(countA - countB, countC);
            it = ab.find(key);
            if (it != ab.end()) 
                ans = max(ans, i-it->second);
            else 
                ab[key] = i;
            
            key = encode(countB - countC, countA);
            it = bc.find(key);
            if (it != bc.end()) 
                ans = max(ans, i - it->second);
            else 
                bc[key] = i;
            
            key = encode(countC - countA, countB);
            it = ca.find(key);
            if (it != ca.end()) 
                ans=max(ans, i - it->second);
            else 
                ca[key] = i;
        }
        
        return ans;
    }
};

int main() {
    return 0;
}