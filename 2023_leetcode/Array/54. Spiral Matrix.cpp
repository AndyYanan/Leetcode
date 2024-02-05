class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> step{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        int r = matrix.size(), c = matrix[0].size();
        if(r == 0 || c == 0){return res;}
        vector<int> n_step{c, r-1};
        int dir = 0;
        int ir = 0, ic = -1;
        while(n_step[dir%2]){
            for(int i = 0; i < n_step[dir%2]; i++){
                ir+=step[dir][0]; ic+=step[dir][1];
                res.push_back(matrix[ir][ic]);
            }
            n_step[dir%2]--;
            dir = (dir+1)%4;
        }
        return res;
        
        /*
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (true) {
            for (int j = left; j <= right; ++j) res.push_back(matrix[up][j]);
            if (++up > down) break;
            for (int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int j = right; j >= left; --j) res.push_back(matrix[down][j]);
            if (--down < up) break;
            for (int i = down; i >= up; --i) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
        */
    }
};