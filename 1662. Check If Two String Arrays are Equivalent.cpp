#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string con1, con2;
        for (string i : word1)
            con1 += i;
        for (string i : word2)
            con2 += i;
        return con1 == con2;
    }
};

int main(){
    return 0;
}