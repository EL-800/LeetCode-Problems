#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        string GetCompressed(string num) {
            int n = num.length();
            vector<pair<char, int>> consFrequency;        
            num += 'a';    
            for (int i = 0; i < n; i++) {
                char c = num[i];
                int f = 1;
                while (i < n && num[i] == num[i + 1]) {
                    f++;
                    i++;
                }
                consFrequency.emplace_back(c, f);
            }
            string compNum;
            for (auto [val, freq] : consFrequency) {
                compNum += to_string(freq);
                compNum += val;
            }
            return compNum;
        }

    public:
        string countAndSay(int n) {
            string currNum = "1";
            for (int i = 1; i < n; i++) 
                currNum = GetCompressed(currNum);
            return currNum;
        }
    };

int main() {
    return 0;
}