#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    set<char> bucket;
    vector <string> arr;

    bool Validate(string add) {        
        for (char i : add) {
            if (bucket.find(i) != bucket.end())
                return false;
        }        
        return true;
    }    

    int FindMax(int i = 0) {
        if (i == n)
            return 0;
        int left = 0;
        if (Validate(arr[i])) {
            for (char i : arr[i])
                bucket.insert(i);
            left = FindMax(i + 1) + arr[i].size();
            for (char i : arr[i])
                bucket.erase(i);
        }
        int right = FindMax(i + 1);
        return max(left, right);
    }

public:
    int maxLength(vector<string>& arr) {               
        vector<string> modified;
        for (string i : arr) {
            int m = i.size();
            sort(i.begin(), i.end());
            i.erase(unique(i.begin(), i.end()), i.end());
            if (m == i.size())
                modified.push_back(i);                
        }
        this->arr = modified;
        n = modified.size();
        return FindMax();
    }
};

int main(){
    return 0;
}