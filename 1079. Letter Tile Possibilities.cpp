#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        set<string> ans;

        void Search(string &curr, string &missing) {
            ans.insert(curr);
            if (missing.empty())
                return;
            for (auto it = missing.begin(); it != missing.end(); it++) {
                curr.push_back(char(*it));
                string aux = missing;
                missing.erase(it);
                Search(curr, missing);
                curr.pop_back();
                missing = aux;
            }
        }

    public:
        int numTilePossibilities(string tiles) {            
            string curr;
            Search(curr, tiles);
            return ans.size() - 1;
        }
    };

int main() {
    return 0;
}