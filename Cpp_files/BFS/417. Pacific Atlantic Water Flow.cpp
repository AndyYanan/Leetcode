class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& hei) {
        int colNum = hei[0].size(), rowNum = hei.size();
        vector<vector<int>> res;
        vector<vector<bool>> pac(rowNum, vector<bool>(colNum, false)), atl(rowNum, vector<bool>(colNum, false));
        if(!hei.size()) return res;
        for(int i = 0; i < rowNum; i++){
            bfsCheck(hei, i, 0, pac);
            bfsCheck(hei, i, colNum-1, atl);
        }
        for(int i = 0; i < colNum; i++){
            bfsCheck(hei, 0, i, pac);
            bfsCheck(hei, rowNum-1, i, atl);
        }
        for(int i = 0; i < rowNum; i++){
            for(int j = 0; j < colNum; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void bfsCheck(vector<vector<int>>& hei, int i, int j, vector<vector<bool>> &ocean){
        q.push({i, j});
        while(!q.empty()){
            int a = q.front().first, b = q.front().second;
            q.pop();
            if(ocean[a][b]) continue;
            ocean[a][b] = true;
            for(int d = 0; d < 4; d++){
                int x = a + dir[d];
                int y = b + dir[d+1];
                if(x >= 0 && y >= 0 && x < hei.size() && y < hei[0].size()){
                    if(hei[a][b] <= hei[x][y]){
                        q.push({x, y});
                    }
                }
            }
        }
    }
};