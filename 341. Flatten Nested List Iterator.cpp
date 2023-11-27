#include <bits/stdc++.h>

using namespace std;

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
   const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    int ind = 0;
    vector<int> flattedList;

    void MakeFlat(const vector<NestedInteger> &nestedList){
        for (NestedInteger curr : nestedList){
            if (curr.isInteger())
                flattedList.push_back(curr.getInteger());
            else
                MakeFlat(curr.getList());
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {        
        MakeFlat(nestedList);
    }
    
    int next() {    
        return flattedList[ind++];
    }
    
    bool hasNext() {
        return ind < flattedList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */