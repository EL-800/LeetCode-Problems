#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> ocurrences1, ocurrences2;
        vector<int> order1, order2;
        for (char i : word1)
            ocurrences1[i]++;
        for (char i : word2) {
            if (ocurrences1.find(i) == ocurrences1.end())
                return false;
            ocurrences2[i]++;            
        }
        for (pair<int, int> i : ocurrences1)
            order1.push_back(i.second);
        for (pair<int, int> i : ocurrences2)
            order2.push_back(i.second);
        sort(order1.begin(), order1.end());
        sort(order2.begin(), order2.end());        
        if (order1.size() != order2.size())
            return false;
        for (int i = 0; i < order1.size(); i++) {
            if (order1[i] != order2[i])
                return false;
        }
        return true;
    }
};

int main(){
    return 0;
}