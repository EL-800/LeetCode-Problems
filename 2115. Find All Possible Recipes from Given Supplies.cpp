#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        unordered_map<string, vector<string>> recipeIngredients;
        unordered_map<string, int> canMakeRecipe;        

        bool IsPossible(string curr) {
            if (canMakeRecipe.count(curr))
                return canMakeRecipe[curr]; 
            if (!recipeIngredients.count(curr))
                return 0;        
            canMakeRecipe[curr] = 0;         
            for (auto ingredient : recipeIngredients[curr]) {                
                if (ingredient == curr || !IsPossible(ingredient))
                    return canMakeRecipe[curr];
            }
            return canMakeRecipe[curr] = 1;
        }

    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            for (int i = 0; i < recipes.size(); i++) 
                recipeIngredients[recipes[i]] = ingredients[i];            
            for (int i = 0; i < supplies.size(); i++)
                canMakeRecipe[supplies[i]] = 1;
            vector<string> ans;
            for (auto recipe : recipes) {
                if (IsPossible(recipe))
                    ans.push_back(recipe);
            }
            return ans;
        }
    };

int main() {
    return 0;
}