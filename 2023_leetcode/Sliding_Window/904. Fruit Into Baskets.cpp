class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        /*
        // Time: O(n), space: O(1)
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        for(; r < fruits.size(); r++){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                if(--mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
        }
        return r - l;
        */

        unordered_map<int, int> mp;
        int l = 0, r = 0, res = 0;
        while(r < fruits.size()){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                if(--mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};