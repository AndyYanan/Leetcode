class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numHash;
        for(int i = 0; i < nums.size(); ++i){
            if(numHash.find(nums[i]) != numHash.end()){
                return {numHash[nums[i]], i};
            }else{
                numHash[target - nums[i]] = i; 
            }
        }
        return {-1,-1};
    }
};