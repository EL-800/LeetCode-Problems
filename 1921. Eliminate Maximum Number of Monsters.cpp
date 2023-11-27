#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time;
        for (int i = 0; i < n; i++)
            time.push_back((int)ceil((double)dist[i] / (double)speed[i]));
        sort(time.begin(), time.end());
        int i = 0;
        while (i < n){
            if ((i + 1) > time[i])
                break;
            i++;
        }
        return i;
    }
};

int main(){
    return 0;
}