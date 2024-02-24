#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    unordered_map<int, int> parents;
    vector<bool> secretKnown;

    int Find(int u){
        if (!parents.count(u) || parents[u] == u)
            return u;                
        return parents[u] = Find(parents[u]);
    }

    void Union(int u, int v){
        int parentU = Find(u);
        int parentV = Find(v);
        if (secretKnown[parentU])
            parents[parentV] = parentU;
        else
            parents[parentU] = parentV;
    }

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {        
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b){return a[2] < b[2];});
        this->n = n;
        secretKnown.assign(n, false);  
        secretKnown[0] = secretKnown[firstPerson] = true;      
        int currTime = 0;
        
        for (vector<int> meeting : meetings){
            if (currTime != meeting[2]) {
                for (auto ind : parents) {
                    int parent = Find(ind.first);    
                    if (secretKnown[parent])
                        secretKnown[ind.first] = true;
                }
                parents.clear();                                  
            }            
            Union(meeting[0], meeting[1]);
            currTime = meeting[2];
        }
        for (auto ind : parents) {
            int parent = Find(ind.first);    
            if (secretKnown[parent])
                secretKnown[ind.first] = true;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if(secretKnown[i])
                ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> c = {{0,2,2},{3,4,1},{3,2,1},{4,0,2},{4,3,1}};
    s.findAllPeople(6, c, 1);
    return 0;
}