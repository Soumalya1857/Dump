
class RandomizedSet {
private:

    unordered_map<int, unordered_map<int, bool>> mp; // val , {index, true}
    vector<int> vals;



public:
    RandomizedSet() {
        srand(100);
    }

    void swap(int i, int j){
        int temp = vals[i];
        vals[i] = vals[j];
        vals[j] = temp;
    }

    bool insert(int val) {
        // insert in mp
        if(mp[val].size() > 0) return false;

        vals.push_back(val);
        mp[val][vals.size()-1] = true; // store the index for that particular value

        return true;
    }

    bool remove(int val) {

        // dont remove it from array
        // instead swap with last element => pop and update the index of the latest element

        if(mp[val].size() == 0) return false;

        unordered_map<int,bool> :: iterator it = mp[val].begin();
        int index = it->first;

        if(vals.size() > 1){
            // swap index with last element in vals
            swap(index, vals.size()-1);

            mp[val].erase(index); // delete val from it's own thing

            // update index of swapped index val
            int newVal = vals[index];

            mp[newVal].erase(vals.size()-1);
            mp[newVal][index] = true;

            vals.pop_back(); // element removed
        }else{
            // size is 1
            mp[val].erase(index);
            vals.pop_back();
        }

        return true;
    }

    int getRandom() {

        int randIndex = rand() % vals.size();
        return vals[randIndex];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

 // https://leetcode.com/problems/insert-delete-getrandom-o1/solutions/85401/java-solution-using-a-hashmap-and-an-arraylist-along-with-a-follow-up-131-ms/
 // https://leetcode.com/problems/insert-delete-getrandom-o1/




