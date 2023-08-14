#include <iostream>
#include <vector>

using namespace std;

class RandomizedSet
{

private:
    vector<int> set;
    unordered_map<int, int> randomizedSet;

public:
    RandomizedSet()
    {

        // Unnecessary: RandomizedSet *randomizedSet = new RandomizedSet();
        // Explanation:
        // No need to initialize 'set' & 'randomizedSet' as they are initialized
        // automatically, initially to 0 and later to their respective sizes
        // when/if their containers increase.
    }

    bool insert(int val)
    {
        if (randomizedSet.count(val) == 0)
        {
            // place element 'val' in the last position of the vector 'set'
            set.push_back(val);

            // New pair in 'unordered_map<int, int> randomizedSet'
            // val = new value to insert
            // index = size-1 of 'set'
            // val: index
            randomizedSet[val] = set.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (randomizedSet.count(val) == 0)
            return false;

        // lastElement = last element in vector 'set'
        int lastElement = set.back();

        // index requiring removal = unordered_map[val to be removed]
        int indexReqRemoval = randomizedSet[val];

        // setting last element in set to set[unordered_map[val to be removed]]
        set[indexReqRemoval] = lastElement;

        // remove the last element in set (current duplicate)
        set.pop_back();

        // the last element in vector 'set' within the 'randomizedSet' replaced with
        // the index requiring removal
        randomizedSet[lastElement] = indexReqRemoval;

        // erasing the val element in 'randomizedSet'
        randomizedSet.erase(val);

        return true;
    }

    int getRandom()
    {

        // returns the element in 'set' at the index of
        // randomly generated number % size of 'set'
        return set[rand() % set.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */