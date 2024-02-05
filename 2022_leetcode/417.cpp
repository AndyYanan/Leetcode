class Solution {
    vector<int> dir = {0, 1, 0, -1, 0};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<bool>> pac, atl;   
        if(!heights.size())return res;
        int r = heights.size(), c = heights[0].size();
        pac = atl = vector<vector<bool>> (r, vector<bool>(c, false));
        for(int i = 0; i < r; ++i){
            dfs_check(heights, i, 0, pac);
            dfs_check(heights, i, c-1, atl);
        }
        for(int j = 0; j < c; ++j){
            dfs_check(heights, 0, j, pac);
            dfs_check(heights, r-1, j, atl);
        }
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(pac[i][j]*atl[i][j]){
                    res.push_back(vector<int>{i, j});
                }
            }
        }
        return res;

    }
    void dfs_check(vector<vector<int>> &heights, int i, int j, vector<vector<bool>>& ocean){
        if(ocean[i][j]){return;}
        ocean[i][j] = true;
        for(int d = 0; d < 4; ++d){
            int x = i + dir[d];
            int y = j + dir[d+1];
            if(x<0 || y<0 || x>=heights.size() || y>=heights[0].size() || heights[x][y]<heights[i][j]){
                continue;
            }
            dfs_check(heights, x, y, ocean);
        }
    }
};