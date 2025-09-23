#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> Vectorize(string &version) {
        vector<int> vectorized;
        auto left = version.begin(), right = find(left, version.end(), '.');
        while (right != version.end()) {
            string revision = version.substr(left - version.begin(), right - left);
            vectorized.push_back(stoi(revision));
            left = next(right);
            right = find(left, version.end(), '.');
        }
        string revision = version.substr(left - version.begin(), right - left);
        vectorized.push_back(stoi(revision));
        return vectorized;
    }

public:
    int compareVersion(string version1, string version2) {        
        vector<int> vectorized1 = Vectorize(version1), vectorized2 = Vectorize(version2);
        int maxSize = max(vectorized1.size(), vectorized2.size());
        vectorized1.resize(maxSize);
        vectorized2.resize(maxSize);
        if (vectorized1 < vectorized2)
            return -1;
        else if (vectorized1 > vectorized2)
            return 1;
        else
            return 0;
    }
};

int main() {
    return 0;
}