#include <bits/stdc++.h>

using namespace std;

class MovieRentingSystem {
private:
    unordered_map<long long, vector<int>> shopPrices;
    unordered_map<int, set<vector<int>>> moviePrices;

    unordered_map<long long, vector<int>> clientPrices;
    set<vector<int>> lowerPricesClients;

    long long Encode(int shop, int movie) {
        return ((long long)shop << 20) | (long long)movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            long long encodeVal = Encode(shop, movie);            
            shopPrices[encodeVal].push_back(price);
            moviePrices[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        int maxSearch = 5;
        vector<int> shops;
        auto &pricesForMovie = moviePrices[movie];
        auto it = pricesForMovie.begin();
        while(maxSearch-- && it != pricesForMovie.end()) {
            shops.push_back(it->at(1));
            it++;
        }
        return shops;
    }
    
    void rent(int shop, int movie) {
        long long encodedVal = Encode(shop, movie);
        int price = shopPrices[encodedVal].back();

        shopPrices[encodedVal].pop_back();
        moviePrices[movie].erase({price, shop});
        
        clientPrices[encodedVal].push_back(price);
        lowerPricesClients.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        long long encodedVal = Encode(shop, movie);
        int price = clientPrices[encodedVal].back();

        clientPrices[encodedVal].pop_back();
        lowerPricesClients.erase({price, shop, movie});

        shopPrices[encodedVal].push_back(price);
        moviePrices[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        int maxSearch = 5;
        vector<vector<int>> rentedReport;
        auto it = lowerPricesClients.begin();
        while (maxSearch-- && it != lowerPricesClients.end()) {
            int shop = it->at(1), movie = it->at(2);
            rentedReport.push_back({shop, movie});
            it++;
        }
        return rentedReport;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

int main() {
    return 0;
}