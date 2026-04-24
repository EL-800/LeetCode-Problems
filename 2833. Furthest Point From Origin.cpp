#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int currPosition = 0, emptiesCount = 0;
        for (char c : moves) {
            if (c == '_')
                emptiesCount++;
            else
                currPosition += c == 'L' ? -1 : 1;
        }

        return abs(currPosition) + emptiesCount;
    }
};

int main() {
    return 0;
}