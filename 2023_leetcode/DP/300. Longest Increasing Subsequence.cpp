class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
#if 0
        vector<int> sub;
        sub.push_back(nums[0]);
        for(int i = 1; i < n; ++i){
            if(sub[sub.size()-1] < nums[i]){
                sub.push_back(nums[i]);
            }else{
                auto it = lower_bound(sub.begin(), sub.end(), nums[i]);
                *it = nums[i];
            }
        }
        return sub.size();
#endif 
#if 1
        int res = 1;
        vector<int> dp(n,1);
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j] && dp[i] < dp[j]+1)
                    dp[i] = dp[j] + 1;
                    res = max(res, dp[i]);
            }
        }
        return res;
#endif
    }
};