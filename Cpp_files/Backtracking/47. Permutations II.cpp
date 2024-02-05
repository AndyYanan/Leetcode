class Solution {
public:
/*
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0 ,res);        
        return res;
    }
    void dfs(vector<int>& nums, int begin, vector<vector<int>>& res){
        if(begin == nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int> numsSet;
        for(int i = begin; i < nums.size(); ++i){
            if(numsSet.count(nums[i])){
                continue;
            }
            numsSet.insert(nums[i]);
            swap(nums[i], nums[begin]); 
            dfs(nums, begin+1, res);    
            swap(nums[i], nums[begin]); 
        }
    }
*/

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0 ,res);        
        return res;
    }
    void dfs(vector<int> nums, int begin, vector<vector<int>>& res){
        if(begin == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); ++i){
            if(i != begin && nums[i] == nums[begin]){
                continue;
            }
            swap(nums[i], nums[begin]); 
            dfs(nums, begin+1, res);    
            //swap(nums[i], nums[begin]); 
        }
    }

};