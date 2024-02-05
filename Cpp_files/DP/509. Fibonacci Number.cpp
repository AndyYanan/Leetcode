class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int oneBeforeCur = 1;
        int twoBeforeCur = 0;
        int cur = 0;
        for(int i = 2; i <= n; ++i){
            cur = oneBeforeCur + twoBeforeCur;
            twoBeforeCur = oneBeforeCur;
            oneBeforeCur = cur;
        }
        return cur;
        /*
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        */
    }
};