#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator() (pair<int, string> a, pair<int, string> b) const {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

class FoodRatings {
private:
    unordered_map<string, set<pair<int, string>, cmp>::iterator> foodsIterators;
    unordered_map<string, set<pair<int, string>, cmp>> cuisineRates;
    unordered_map<string, string> foodCuisines;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodsIterators[foods[i]] = cuisineRates[cuisines[i]].insert({ratings[i], foods[i]}).first;    
            foodCuisines[foods[i]] = cuisines[i];     
        }
    }
    
    void changeRating(string food, int newRating) {
        string foodCuisine = foodCuisines[food];
        cuisineRates[foodCuisine].erase(foodsIterators[food]);
        foodsIterators[food] = cuisineRates[foodCuisine].insert({newRating, food}).first;
    }
    
    string highestRated(string cuisine) {
        return cuisineRates[cuisine].rbegin()->second;
    }
};

int main(){
    return 0;
}