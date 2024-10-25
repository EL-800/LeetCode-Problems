#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool IsSubstring(string &a, string &b) {
        stringstream sa(a);        
        stringstream sb(b);
        string folder;
        vector<string> foldersA, foldersB;
        while (getline(sa, folder, '/')) 
            foldersA.push_back(folder);  
        while (getline(sb, folder, '/')) 
            foldersB.push_back(folder); 
        if (foldersA.size() >= foldersB.size())
            return false;
        for (int i = 0; i < foldersA.size(); i++) {
            if (foldersA[i] != foldersB[i])
                return false;            
        }
        return true;       
    }

public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        string currFolder = "A";
        for (auto path : folder) {
            if (!IsSubstring(currFolder, path)) {
                currFolder = path;
                ans.push_back(currFolder);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}