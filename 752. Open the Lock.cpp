#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> pendingMoves;    
        pendingMoves.push({"0000",0}); 
        unordered_set<string> visited (deadends.begin(), deadends.end());
        while (!pendingMoves.empty()){
            auto curr = pendingMoves.front();
            pendingMoves.pop();
            if (visited.count(curr.first))
                continue;
            visited.insert(curr.first);
            if (curr.first == target)
                return curr.second;            
            for (int i = 0; i < curr.first.size(); i++){
                string move = curr.first;
                if (move[i] == '9')
                    move[i] = '0';
                else                    
                    move[i]++;
                pendingMoves.push({move, curr.second + 1});
                move = curr.first;
                if (move[i] == '0')
                    move[i] = '9';
                else
                    move[i]--;
                pendingMoves.push({move, curr.second + 1});       
            }
        }
        return -1;
    }
};

int main(){
    return 0;
}