class Solution {
public:
    int climbStairs(int n) {
        /*
        if(n == 1) return 1;
        if(n == 2) return 2;
        return climbStairs(n-1) + climbStairs(n-2);
        */
        /*
        int dp[n+1];
        dp[1] = 1; dp[0] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        */
        if(n == 1) return 1;
        if(n == 2) return 2;
        int sum = 0;
        int two_before = 1, one_before = 2;
        for(int i = 3; i <= n; i++){
            sum = two_before + one_before;
            two_before = one_before;
            one_before = sum;
        }
        return sum;
    }
}; 