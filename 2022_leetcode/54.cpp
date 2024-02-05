class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
        if(row==0 || col==0) return res;
        int up = 0, dw = row-1, r = col-1, l = 0;
        while(true)){
            for(int i = l; i <= r; i++){
                res.push_back(matrix[up][i]);
            }
            if(++up > dw) break;
            for(int i = up; i <=dw; i++){
                res.push_back(matrix[i][r]);
            }
            if(--r<l) break;
            for(int i =r; i >=l; i--){
                res.push_back(matrix[dw][i]);
            }
            if(--dw<up) break;
            for(int i =l; i >=up; i--){
                res.push_back(matrix[i][l]);
            }
            if(++l>r) break;
        }
        return res;
    }
};