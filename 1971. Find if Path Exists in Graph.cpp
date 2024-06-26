#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> hash;
        for(auto& edge : edges){
            hash[edge[0]].push_back(edge[1]);
            hash[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(start);
        vector<bool> visit(n, false);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur == end) return true;
            for(auto& node : hash[cur]){
                if(!visit[node]){
                    q.push(node);
                    visit[node] = true;
                }
            }
        }
        return false;
    }
};

int main(){
    return 0;
}