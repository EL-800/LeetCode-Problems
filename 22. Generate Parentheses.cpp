#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<string> ans;
    string currString;

    void SearchValids(int ind = -1, int openParentheses = 0){
        if (ind == n - 1) {
            if (openParentheses == 0)
                ans.push_back(currString);
            return;
        }
        if (openParentheses < 0)
            return;

        currString.push_back('(');
        SearchValids(ind + 1, openParentheses + 1);
        currString.pop_back();

        currString.push_back(')');
        SearchValids(ind + 1, openParentheses - 1);
        currString.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) {
        this->n = 2 * n;
        SearchValids();
        return ans;
    }
};

int main() {
    return 0;
}