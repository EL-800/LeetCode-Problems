#include <bits/stdc++.h>

using namespace std;

class MountainArray {
private:
    vector<int> arr = {1,2,3,4,5,3,1};
public:
    int get(int index){
        return arr[index];
    }
    int length(){
        return arr.size();
    };
};
 

class Solution {
private:
    int BS(int left, int right, function<bool(int)> comp){
        if (left == right)
            return left;
        int mid = (left + right) / 2 + 1;
        if (comp(mid))
            return BS(mid, right, comp);
        return BS(left, mid - 1, comp);
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = BS(0, n - 1, [&mountainArr](int mid){ return mountainArr.get(mid - 1) < mountainArr.get(mid); });
        int leftSearch = BS(0, peak - 1, [&mountainArr, target](int mid){ return mountainArr.get(mid) <= target; });
        if (mountainArr.get(leftSearch) == target)
            return leftSearch;
        int rightSearch = BS(peak, n - 1, [&mountainArr, target](int mid){ return mountainArr.get(mid) >= target; });
        if (mountainArr.get(rightSearch) == target)
            return rightSearch;
        return -1;
    }
};

int main(){
    Solution s;
    MountainArray ej = MountainArray(); 
    s.findInMountainArray(3, ej);
    return 0;
}