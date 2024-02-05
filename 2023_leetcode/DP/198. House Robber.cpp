class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        int dp[len];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < len; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[len-1];
        */
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int maxNum = 0;
        int pre = 0, cur = 0;
        for(int i = 0; i < nums.size(); ++i){
            maxNum = max(pre + nums[i], cur);
            pre = cur;
            cur = maxNum;
        }
           return maxNum;
    }
};
 