class Solution {
private:
    void dfs_erase(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        dfs_erase(grid, i+1, j);
        dfs_erase(grid, i-1, j);
        dfs_erase(grid, i, j+1);
        dfs_erase(grid, i, j-1);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int island = 0;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(grid[i][j] == '1'){
                    island++;
                    dfs_erase(grid, i, j);
                }
            }
        }
        return island;
    }
};