#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
    private:
    vector<int> products;

    public:
        ProductOfNumbers() {
            products.reserve(4e4);
            products.push_back(1);
        }
        
        void add(int num) {
            if (!num) {
                products.clear();
                products.push_back(1);
                return;
            }                
            products.push_back(num * products.back());
        }
        
        int getProduct(int k) {            
            int n = products.size();
            if (k >= n)
                return 0;
            return products.back() / products[n - k - 1];
        }
    };

int main() {
    return 0;
}