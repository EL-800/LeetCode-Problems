#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> arrayTree;

    int MakeTree(vector<int>& arr, int left, int right, int treeInd = 1) {
        if (left == right)
            return arrayTree[treeInd] = arr[left];
        int mid = (left + right) / 2;
        return arrayTree[treeInd] = max(MakeTree(arr, left, mid, treeInd * 2), MakeTree(arr, mid + 1, right, treeInd * 2 + 1));
    }

    int GetInd(int obj, int left, int right, int treeInd = 1) {
        if (left == right)
            return left;
        int mid = (left + right) / 2;
        if (arrayTree[treeInd * 2] < obj)
            return GetInd(obj, mid + 1, right, treeInd * 2 + 1);        
        return GetInd(obj, left, mid, treeInd * 2);
    }

    void UpdatInd(int ind, int left, int right, int treeInd = 1) {
        if (left == right) {
            arrayTree[treeInd] = 0;
            return;
        }
        int mid = (left + right) / 2;
        if (ind >= left && ind <= mid)
            UpdatInd(ind, left, mid, treeInd * 2);
        else
            UpdatInd(ind, mid + 1, right, treeInd * 2 + 1);
        arrayTree[treeInd] = max(arrayTree[treeInd * 2], arrayTree[treeInd * 2 + 1]);
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        arrayTree.assign(4 * n + 2, 0);
        MakeTree(arr, 0, n - 1);        
    }

    int GetLowestIndGreater(int obj) {
        if (arrayTree[1] < obj)
            return -1;
        int ans = GetInd(obj, 0, n - 1);
        UpdatInd(ans, 0, n - 1);
        return ans;
    }
    
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree segmentTree(baskets);
        int ans = 0;
        for (int fruit : fruits) 
            ans += segmentTree.GetLowestIndGreater(fruit) == -1;                            
        return ans;
    }
};

int main() {
    return 0;
}