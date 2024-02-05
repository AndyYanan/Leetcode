class RandomizedSet {
    // Time: O(1), Space: O(N)
private: 
    vector<int> arr; // array vector to store the insert value
    unordered_map<int, int> table; // record the index of the value, so the searching. insertion, deletion of element can be in O(1) time
public:
    RandomizedSet() {
        // No need to initialize arr and table because they are initialized to 0 automatically
    }
    
    bool insert(int val) {
       if(table.count(val)){
        // If val is not already present in the map
           return false;
       }else{
           arr.push_back(val); // insert the value at the end of the array
           table[val] = arr.size()-1; /// store the array element and its index as key
           return true;
       }
    }
    
    bool remove(int val) {
        if(table.count(val)){
            int idx = table[val]; // index of value in the arr vector
            int last_val = arr[arr.size()-1]; // last element of the arr
            arr[idx] = last_val; //copy the last element to the val location
            table[last_val] = idx; // update the index of last_val 
            table.erase(val); // delete the val entry from table
            arr.pop_back();// delete the last element of the arr
            return true;
        }else{
            // val not present in the array vector
            return false;
        }
    }
    
    int getRandom() {
        return arr[rand() % (arr.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */