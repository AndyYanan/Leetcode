class Solution {
public:
    int maxProfit(vector<int>& prices) {
       /* int curHold = INT_MIN, curNotHold = 0;
        for(int &p : prices){
            int preHold = curHold, preNotHold = curNotHold;
            curHold = max(curHold, preNotHold - p);
            curNotHold = max(curNotHold, preHold + p);
        }
        return curNotHold;
        */
        // dp[i][1]第i天持有的最多现金
        // dp[i][0]第i天持有股票后的最多现金
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] -= prices[0]; // 持股票
        for (int i = 1; i < n; i++) {
            // 第i天持股票所剩最多现金 = max(第i-1天持股票所剩现金, 第i-1天持现金-买第i天的股票)
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // 第i天持有最多现金 = max(第i-1天持有的最多现金，第i-1天持有股票的最多现金+第i天卖出股票)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);

        }
        return dp[n - 1][1];
        /*
        int myProfit = 0;
        for(int i = 0; i < prices.size()-1; ++i){
            myProfit += max(0, prices[i+1] - prices[i]);
        }
        return myProfit;
        /*
        /*
        int i = 0, buy, sell, profit = 0, N = prices.length - 1;
        while (i < N) {
            while (i < N && prices[i + 1] <= prices[i]) i++;
            buy = prices[i];

            while (i < N && prices[i + 1] > prices[i]) i++;
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
        */
    }
};