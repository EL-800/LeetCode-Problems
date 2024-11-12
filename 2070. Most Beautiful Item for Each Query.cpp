#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<vector<int>> indexedQueries(queries.size());
        vector<int> finalAns(queries.size());                
        for (int i = 0; i < queries.size(); i++) 
            indexedQueries[i] = {queries[i], i}; 
        sort(indexedQueries.begin(), indexedQueries.end());
        sort(items.begin(), items.end());
        int itemsInd = 0, queriesInd = 0, currAns = 0;
        while (queriesInd < indexedQueries.size()) {                     
            while (itemsInd < items.size() && items[itemsInd][0] <= indexedQueries[queriesInd][0]) {
                currAns = max(currAns, items[itemsInd][1]);
                itemsInd++;
            }
            finalAns[indexedQueries[queriesInd][1]] = currAns;
            queriesInd++;
        }
        return finalAns;
    }
};

int main() {
    return 0;
}