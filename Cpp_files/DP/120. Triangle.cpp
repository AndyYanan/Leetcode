class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        vector<int> dp(triangle[len-1]);
        for(int i = len-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

int dfs(int i, int j, int n, vector<vector<int>>& tri, vector<vector<int>> memo){
    if(i == n) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    int leftMin = dfs(i, j, n, tri, memo);
    int rightMin = dfs(i, j+1, n, tri, memo);
    memo[i][j] = min(leftMin, rightMin);
    return momo[i][j];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        dfs(0, 0, n, triangle, memo);
        return memo[0][0];
    } 