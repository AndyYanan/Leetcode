class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int cLen = matrix[0].size(), rLen = matrix.size();
       int col0_is_zero = 0;
        for(int row = 0; row < rLen; row++){
            if(matrix[row][0] == 0){
                col0_is_zero = 1;
            }
            for(int col = 1; col < cLen; col++){
                if(matrix[row][col] == 0){
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }
        for(int row = rLen-1; row >= 0; row--){
            for(int col = cLen-1; col >= 1 ; col--){
                if(matrix[0][col] == 0 || matrix[row][0] == 0){
                    matrix[row][col] = 0;
                }
            }
            if(col0_is_zero == 1){
                matrix[row][0] = 0;
            }
        }
    }
};
