#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int, unordered_set<int>> grid;        
        int currY = 0, currX = 0;
        grid[currY].insert(currX);
        for (char move : path){
            switch (move)
            {
            case 'N':
                currY--;
                break;
            case 'S':
                currY++;
                break;
            case 'E':
                currX++;
                break;
            case 'W':
                currX--;
                break;            
            }
            if (grid[currY].count(currX))
                return true;
            grid[currY].insert(currX);            
        }
        return false;
    }
};

int main(){
    return 0;
}