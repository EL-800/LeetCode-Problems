#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> node1 = edges[0], node2 = edges[1];
        return node1[0] == node2[0] || node1[0] == node2[1] ? node1[0] : node1[1];
    }
};

int main(){
    return 0;
}