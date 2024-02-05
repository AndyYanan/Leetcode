class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            for(int &coin:coins){
                if(i-coin >= 0){
                    dp[i] = min(dp[i], 1+dp[i-coin]);
                }
            }
        }
        return dp[amount]!=(INT_MAX-1) ? dp[amount]:-1;
        */
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(int c : coins){
            for(int j = c ; j <= amount; j++){
                dp[j] = min(dp[j], 1+dp[j - c]);
            }
        }
        return dp[amount]!=(INT_MAX-1) ? dp[amount]:-1;
    }
};
