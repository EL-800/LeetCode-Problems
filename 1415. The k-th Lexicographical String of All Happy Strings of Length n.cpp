#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        int n;
        string letters = "abc", ans;

        void Search(int &k, string &curr) {            
            if (curr.length() == n) {
                k--;
                if (!k)
                    ans = curr;
                return;
            }          
            for (auto let : letters) {     
                if (!k)
                    break;           
                if (!curr.empty() && curr.back() == let)
                    continue;
                curr.push_back(let);                
                Search(k, curr);
                curr.pop_back();
            }      
        }

    public:
        string getHappyString(int n, int k) {
            this->n = n;
            string curr;
            Search(k, curr);
            return ans;
        }
    };

int main() {
    return 0;
}