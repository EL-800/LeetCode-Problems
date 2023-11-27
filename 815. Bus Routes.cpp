#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> stops;
        for (int i = 0; i < routes.size(); i++){
            for (int stop : routes[i])
                stops[stop].push_back(i);
        }
        vector<bool> shortest(routes.size());
        queue<pair<int, int>> pendingMoves;        
        pendingMoves.push({source, 0});        
        while(!pendingMoves.empty()){
            auto currStop = pendingMoves.front();
            pendingMoves.pop();
            if (currStop.first == target)
                return currStop.second;
            for (int adjRoute : stops[currStop.first]){
                if (shortest[adjRoute])
                    continue;
                shortest[adjRoute] = true;
                for (int adjStop : routes[adjRoute])
                    pendingMoves.push({adjStop, currStop.second + 1});                
            }
        }
        return -1;
    }
};

int main(){
    return 0;
}