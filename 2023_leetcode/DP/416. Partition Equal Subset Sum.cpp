class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); // input length
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
        }
        if(sum % 2) return false;

        int tar = sum/2;
        vector<int> dp(10001, 0);
        for(int i = 0; i < n; ++i){
            for(int target = tar; target >= nums[i]; target--){
                //Every loop of nums refreshes dp array. We might get dp[i] from dp[i-num] whose index is smaller than i. If we increase the index of sum from 0 to sum, we will get dp[i] from dp[i-num] , while dp[i-num] has been updated in this loop. This dp[i-num] is not the number we got from the previous loop.
                dp[target] = max(dp[target], dp[target - nums[i]] + nums[i]);
                //cout << dp[target] << "    tar =" << target << "    tar-num =" << target - nums[i] << endl;

            }
        }
        //cout << "------------------" << endl;

        //for(int i = 0; i <= tar; ++i)
        //    cout << dp[i] << endl;
        return dp[tar] == tar;

    }
};

/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
        if(totalSum & 1) return false;
        bool dp[halfSum+1]; memset(dp, false, sizeof dp);
        dp[0] = true;                              // 0 sum is always achievable
        for(int num : nums) 
            for(int j = halfSum; j >= num; j--)    // essential to start right to left
                if(dp[j - num])                    // if j - num was previously achievable
                    dp[j] = true;                  // we can add num to it and make j achievable as well
            
        return dp[halfSum];
    }
};
*/
