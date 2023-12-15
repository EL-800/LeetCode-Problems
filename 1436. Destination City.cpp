#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_set<string> inGoing;
        for (int i = 0; i < n; i++)
            inGoing.insert(paths[i][0]);
        for (int i = 0; i < n; i++){
            if (!inGoing.count(paths[i][1]))
                return paths[i][1];
        }
        return "";
    }
};

int main(){
    return 0;
}