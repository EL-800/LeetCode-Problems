#include <bits/stdc++.h>

using namespace std;

class Fancy {
private:
    const int mod = 1000000007;
    vector<long> fancyList;
    long add = 0, mul = 1;    

public:
    Fancy() {
        fancyList = vector<long>();
    }
    
    void append(long val) {
        long addedVal = ((val - add) % mod + mod);
        addedVal = (addedVal * fastExp(mul, mod-2)) % mod;
        fancyList.push_back(addedVal);
    }
    
    void addAll(long val) {
        add = (add + val) % mod;
    }
    
    void multAll(long val) {
        mul = (mul * val) % mod;
        add = (add * val) % mod;
    }
    
    int getIndex(int ind) {
        if(ind >= fancyList.size())
            return -1;
        long val = fancyList[ind];
        return int((val * mul + add) % mod);
    }

    int fastExp(long base, long exp){
        long result = 1;
        while(exp > 0){
            if((exp & 1) == 1){
                result= (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy obj = new Fancy();
 * obj.append(val);
 * obj.addAll(inc);
 * obj.multAll(m);
 * int param_4 = obj.getIndex(idx);
 */

int main() {
    return 0;
}