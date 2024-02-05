class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        //int dp[100][100] = {0};
        vector<vector<int>> dp(row, vector<int>(col, 0));
        if (obstacleGrid[row - 1][col - 1] == 1 || obstacleGrid[0][0] == 1) 
            return 0;
        for(int i = 0; i < row && obstacleGrid[i][0] == 0; ++i){
            dp[i][0] = 1;
        }
        for(int i = 0; i < col && obstacleGrid[0][i] == 0; ++i){
            dp[0][i] = 1;
        }
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; j++){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[row-1][col-1];
    }
};