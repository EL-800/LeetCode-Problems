#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lastRow({1});
        for (int i = 0; i < rowIndex; i++){
            vector<int> currRow({1});
            for (int j = 1; j < lastRow.size(); j++)
                currRow.push_back(lastRow[j - 1] + lastRow[j]);
            currRow.push_back(1);
            lastRow = currRow;
        }
        return lastRow;
    }
};

int main(){
    Solution s;
    s.getRow(4);
    return 0;
}