#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence[0] != sentence.back())
            return false;             
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;            
        }
        return true;
    }
};

int main() {
    return 0;
}