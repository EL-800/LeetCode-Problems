#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        queue<int> pendingMoves;
        vector<int> inDegree(numCourses);
        vector<bitset<100>> existPath(numCourses);
        vector<vector<int>> graph(numCourses);        
        for (auto prerequisite : prerequisites) {
            graph[prerequisite[0]].push_back(prerequisite[1]);            
            inDegree[prerequisite[1]]++;        
            existPath[prerequisite[1]][prerequisite[0]] = true;
        }            
        for (int i = 0; i < numCourses; i++) {
            if (!inDegree[i]) 
                pendingMoves.push(i);                
        }
        while (!pendingMoves.empty()) {
            int curr = pendingMoves.front();
            pendingMoves.pop();
            for (auto adj : graph[curr]) {                
                existPath[adj] |= existPath[curr];
                if (!(--inDegree[adj])) 
                    pendingMoves.push(adj);                                    
            }
        }
        vector<bool> ans;
        for (auto query : queries) 
            ans.push_back(existPath[query[0]][query[1]]);        
        return ans;
    }
};

int main() {
    return 0;
}