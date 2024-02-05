class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int numIslands(vector<vector<char>>& grid) {
        int resNumOfIsland = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    visited[i][j] = true;
                    resNumOfIsland++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        
        return resNumOfIsland;
    }

    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited) {
        for (int dir = 0; dir < 4; dir++) {
            int xDir = x + dirs[dir][0];
            int yDir = y + dirs[dir][1];
            if (xDir >= 0 && yDir >= 0 && xDir < grid.size() && yDir < grid[0].size()) {
                if (!visited[xDir][yDir] && grid[xDir][yDir] == '1') {
                    visited[xDir][yDir] = true;
                    dfs(grid, xDir, yDir, visited);
                }
            }
        }
    }
};

/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int resNumOfI = 0;
        queue<char> que;
        que.push(grid[0][0]);
        int row = grid.size(), col = grid[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == '1'){
                    resNumOfI++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> que;
                    que.push({i, j});
                    while(!que.empty()){
                        pair<int, int> island = que.front();
                        que.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int x = island.first + dirs[dir];
                            int y = island.second + dirs[dir+1];
                            if(x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == '1'){
                                grid[x][y] = '0';
                                que.push({x, y});
                            }
                        }
                    }
                }
            }
        }
        return resNumOfI;
    }
};
*/