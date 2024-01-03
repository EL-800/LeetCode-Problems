#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;
        for (string row : bank){
            int devicesNum = count(row.begin(), row.end(), '1');
            if (devicesNum)
                devices.push_back(devicesNum);
        }
        if (devices.size() <= 1)
            return 0;
        int beams = 0;
        for (int i = 1; i < devices.size(); i++)
            beams += devices[i] * devices[i - 1];        
        return beams;
    }
};

int main(){
    return 0;
}