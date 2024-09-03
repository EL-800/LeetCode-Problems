#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string number;
        for(auto i : s) {
            int add = i - 'a' + 1;
            number += to_string(add);
        }             
        while(k-- && number.length() > 9) {
            int aux = 0;
            for (auto i : number)
                aux += i - '0';                                            
            number = to_string(aux);
        }
        return stoi(number);
    }
};

int main() {
    return 0;
}