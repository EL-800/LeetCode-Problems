#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parents(n, -1);
        for (int i = 0; i < leftChild.size(); i++){
            if (leftChild[i] == -1)
                continue;
            if (parents[leftChild[i]] != -1)
                return false;
            int currP = i;
            while (currP != -1){
                if (leftChild[i] == currP) 
                    return false;
                currP = parents[currP];
            }
            parents[leftChild[i]] = i;
        }
        for (int i = 0; i < rightChild.size(); i++){
            if (rightChild[i] == -1)
                continue;
            if (parents[rightChild[i]] != -1)
                return false;
            int currP = i;
            while (currP != -1){
                if (rightChild[i] == currP) 
                    return false;
                currP = parents[currP];
            }
            parents[rightChild[i]] = i;
        }
        return count(parents.begin(), parents.end(), -1) == 1;
    }
};

int main(){
    vector<int> a = {1,0};
    vector<int> b = {-1,-1};
    Solution s;
    s.validateBinaryTreeNodes(2, a, b);
    return 0;
}