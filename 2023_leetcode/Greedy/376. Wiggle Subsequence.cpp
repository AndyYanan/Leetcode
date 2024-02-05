class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int valley = 1, peak = 1;
        int len = nums.size();
        for(int i = 1; i < len; ++i){
            if(nums[i-1] < nums[i])
                peak = valley + 1;
            else if(nums[i-1] > nums[i])
                valley = peak + 1;
        }
        return max(peal, valley);
    }
};