#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string compressed;
        char count = '0', last = word[0];
        for (auto c : word) {
            if (c != last) {
                if (count != '0') {
                    compressed += count;
                    compressed += last;              
                }
                last = c;
                count = '1';
                continue;                
            }
            if (count == '8') {
                compressed += '9';
                compressed += last;
                count = '0';
                continue;
            }
            count++;            
        }       
        if (count != '0') { 
            compressed += count;
            compressed += last;
        }
        return compressed;
    }
};

int main() {
    return 0;
}