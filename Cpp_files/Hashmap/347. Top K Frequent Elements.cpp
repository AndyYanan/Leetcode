class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int &n : nums){
            hash[n]++;
        }

        vector<vector<int>> buckets(nums.size()+1); // max appear times will be the length of nums
        for(auto &element : hash){
            buckets[element.second()].push_back(element.first());
        }

        vector<int> res;
        for(int i = buckets.size()-1; i >= 0; i--){
            for(auto & num:buckets[i]){
                res.push_back(num);
                if(res.size() == k){
                    return res;
                }
            }
        }
    }
};