#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mappedStrings;
        for (string curr : arr) 
            mappedStrings[curr]++;        
        int ind = 0;
        for (string curr : arr) {
            ind += mappedStrings[curr] == 1;
            if (ind == k)
                return curr;
        }
        return "";
    }
};

int main() {
    return 0;
}