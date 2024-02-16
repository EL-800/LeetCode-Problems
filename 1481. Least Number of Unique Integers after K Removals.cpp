#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> count;
        for (int num : arr)
            count[num]++;
        priority_queue<int, vector<int>, greater<int>> least;
        for (auto ocurrence : count)
            least.push(ocurrence.second);
        while (!least.empty() && least.top() <= k){
            k -= least.top();
            least.pop();
        }               
        return least.size(); 
    }
};

int main(){
    return 0;
}