#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjList;
        for (vector<int> adj : adjacentPairs){
            adjList[adj[0]].push_back(adj[1]);
            adjList[adj[1]].push_back(adj[0]);
        }
        int currInd = (*find_if(adjList.begin(), adjList.end(), [](const pair<int, vector<int>>& curr){return curr.second.size() == 1;})).first;
        vector<int> ans;        
        do{
            ans.push_back(currInd);
            int nextInd = adjList[currInd][0];
            if (adjList[nextInd].size() != 1 && adjList[nextInd][0] == currInd)
                swap(adjList[nextInd][0], adjList[nextInd][1]);
            currInd = nextInd;
        }while(adjList[currInd].size() != 1);
        ans.push_back(currInd);
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> a = {{2,1},{3,4},{3,2}};
    s.restoreArray(a);
    return 0;
}