class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // O(n)
        // input = [1, 1, 1, 2, 2, 2, 3, 3], k =2
        unordered_map<int, int> mp;
        // 1.store the count of each number in the input vector
        // mp[1] = 3, ,mp[2] = 3, mp[3] = 2
        for(int num:nums){
            mp[num]++;
        }

        // Create buckets to store numbers with the same frequency
        // 2. buckets[2] = [3], buckets[3] = [2, 1]
        vector<vector<int>> buckets(nums.size() + 1); 
        for(auto in: mp){
            buckets[in.second].push_back(in.first);
        }
        vector<int> res;
        // Extract the top k frequent numbers from the buckets in descending order of frequency
        // 3. res = [2, 1]
        for(int i = buckets.size()-1; i >= 0; --i){
            for(auto num: buckets[i]){
                res.push_back(num);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};