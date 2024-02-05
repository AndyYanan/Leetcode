class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        int res;
        int oneStep = cost[1], twoStep = cost[0];
        for(int i = 2 ; i < len; ++i){
            res = min(oneStep, twoStep) + cost[i];
            twoStep = oneStep;
            oneStep = res;
        }
        return min(oneStep, twoStep);
        /*
        int len = cost.size();
        int dp[len];
        dp[1] = cost[1], dp[0] = cost[0];
        for(int i = 2 ; i < len; ++i){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp[len-1], dp[len-2]);
        */
    }
};