#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    map<string, unsigned> CountAtoms(string& formula, int &ind) {
        map<string, unsigned> atoms;
        while (formula[ind] != ')') {
            if (isupper(formula[ind])) {
                string element = "";
                element += formula[ind];
                ind++;
                while (islower(formula[ind])) {
                    element += formula[ind];
                    ind++;
                }
                unsigned num = 0;
                while (isdigit(formula[ind])) {
                    num *= 10;
                    num += formula[ind] - '0';
                    ind++;
                }
                num = max(num, (unsigned)1);
                atoms[element] += num;
            }
            else if (formula[ind] == '(') {
                ind++;
                auto attachAtoms = CountAtoms(formula, ind);
                ind++;
                unsigned num = 0;
                while (isdigit(formula[ind])) {
                    num *= 10;
                    num += formula[ind] - '0';
                    ind++;
                }
                num = max(num, (unsigned)1);
                for (auto atom : attachAtoms) 
                    atoms[atom.first] += atom.second * num;                                    
            }
        }
        return atoms;
    }

public:
    string countOfAtoms(string formula) {
        int ind = 0;
        formula += ')';
        auto atoms = CountAtoms(formula, ind);
        string ans = "";
        for (auto atom : atoms) {
            ans += atom.first;
            if (atom.second > 1) {
                string val = to_string(atom.second);
                ans += val;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countOfAtoms("Mg(OH)2");
    return 0;
}