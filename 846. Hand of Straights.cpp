#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> cards;
        for (int card : hand)
            cards[card]++; 
        auto ind = cards.begin();                   
        while (ind != cards.end()) {   
            auto [card, quantity] = *ind;         
            if (quantity){
                int currGroup = 0, currCard = card;
                while (currGroup < groupSize && cards.count(currCard) && cards[currCard]){
                    cards[currCard]--;                                            
                    currCard++; 
                    currGroup++;                                     
                }
                if (currGroup != groupSize)
                    return false;
            }
            else
                ind++;            
        }
        return true;
    }
};

int main(){
    vector<int> c = {1,1,2,2,3,3};
    Solution s;
    s.isNStraightHand(c, 3);
    return 0;
}