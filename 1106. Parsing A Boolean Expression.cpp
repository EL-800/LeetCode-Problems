#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool CalculateExpr(const string &expression, int &i) {        
        char c = expression[i++];
        if (c == 't' || c == 'f')
            return c == 't';
        if (c == '!') {
            i++;
            bool aux = CalculateExpr(expression, i);
            i++;
            return aux;
        }
        vector<bool> exps;
        i++;
        while (expression[i] != ')') {
            if (expression[i] == ',')
                i++;        
            else     
                exps.push_back(CalculateExpr(expression, i));
        }
        if (c == '|')
            return any_of(exps.begin(), exps.end(), [](bool e) {return e;});
        if (c == '&')
            return all_of(exps.begin(), exps.end(), [](bool e) {return e;});         
        return false;
    }

public:
    bool parseBoolExpr(string expression) {
        int i = 0;
        return CalculateExpr(expression, i);
    }
};

int main() {
    return 0;
}