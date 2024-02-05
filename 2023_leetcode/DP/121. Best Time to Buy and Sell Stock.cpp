class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* //Greedy
        int res = 0;
        int curMin = INT_MAX;
        for(int &price: prices){
            curMin = min(curMin, price);
            res = max(res, price - curMin);
        }
        return res;
        */

        // DP
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = -prices[0]; // day 0 hold stock -> must buy
        dp[0][1] = 0;
        for(int i = 1; i < len; ++i){
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return dp[len-1][1];
    }
};

   