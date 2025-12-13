#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool IsValidCode(string &code) {
        if (!code.size())
            return false;
        for (char c : code) {
            if (c >= 'A' && c <= 'Z')
                continue;
            if (c >= 'a' && c <= 'z')
                continue;
            if (c >= '0' && c <= '9')
                continue;
            if (c == '_')
                continue;
            return false;
        }
        return true;
    }

public:
    vector<string> validateCoupons(vector<string>& codes, vector<string>& businessLine, vector<bool>& isActive) {
        int n = codes.size();
        unordered_map<string, int> validBusiness({{"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}});
        vector<pair<int, string>> valids;
        for (int i = 0; i < n; i++) {
            if (!IsValidCode(codes[i]))
                continue;
            if (!validBusiness.count(businessLine[i]))
                continue;
            if (!isActive[i])
                continue;
            valids.push_back({validBusiness[businessLine[i]], codes[i]});
        }

        sort(valids.begin(), valids.end());
        vector<string> ans;
        for (auto [line, code] : valids) 
            ans.push_back(code);        

        return ans;
    }
};

int main() {
    return 0;
}