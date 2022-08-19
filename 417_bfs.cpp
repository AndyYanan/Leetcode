class Solution {
    vector<int> dir = {0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        vector<vector<int>> res;
        vector<vector<bool>> pac, atl;
        if(!mat.size()) return res;
        int r = mat.size(), c = mat[0].size();
        pac = atl = vector<vector<bool>>(r, vector<bool>(c, false));
        for(int i = 0; i < r; ++i){
            bfs_check(mat, i, 0, pac);
            bfs_check(mat, i, c-1, atl);
        }
        for(int j = 0; j < c; ++j){
            bfs_check(mat, 0, j, pac);
            bfs_check(mat, r-1, j, atl);
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
    void bfs_check(vector<vector<int>> &heights, int i, int j, vector<vector<bool>>& ocean){

        q.push({i,j});
        while(!q.empty()){
            int a = q.front().first, b = q.front().second;
            q.pop();
            if(ocean[a][b]) continue;
            ocean[a][b] = true;
            for(int d = 0; d < 4; ++d){
                int x = a + dir[d];
                int y = b + dir[d+1];
                if(x<0 || y<0 || x>=heights.size() || y>=heights[0].size() || heights[x][y]<heights[a][b]){
                    continue;
                }
                q.push({x,y});
            }
        }
    }
}; 