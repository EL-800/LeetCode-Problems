#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void countChars(vector<int>& countArr, string a){
        for (char lett : a)
            countArr[lett - 'a']++;        
    }

public:
    bool isAnagram(string s, string t) {
        vector<int> countS(26), countT(26);
        countChars(countS, s);
        countChars(countT, t);
        return equal(countS.begin(), countS.end(), countT.begin(), countT.end());
    }
};

int main(){
    return 0;
}