class Solution {
public:
    unordered_map<int, int> mp;
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtracking(nums, target, 0, target);        
    }
    void backtracking(vector<int>& nums, int target, int start, int tarSum){
        if(mp.count(tarSum)){
            return mp[tarSum];
        }
        if(start == nums.size()){
            if(tarSum == 0){
                return 1;
            }
            return 0;
        }
        int minWay = backtracking(nums, target, start + 1, tarSum - nums[stack]);
        int addWay = backtracking(nums, target, start + 1, tarSum + nums[stack]);
        int way = minWay + addWay;
        mp[tarSum] = wat;
        return way;
    }
};