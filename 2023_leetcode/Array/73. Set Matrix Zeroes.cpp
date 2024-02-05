class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int cnum = m[0].size(), rnum = m.size();
        int colIsZero = 0;
        for(int r = 0; r < rnum; r++){
            if(m[r][0] == 0){
                colIsZero = 1;
            }
            for(int c = 1; c < cnum; c++){
                if(m[r][c] == 0){
                    m[r][0] = 0;
                    m[0][c] = 0;
                }
            }
        }
        for(int r = rnum-1; r >= 0; r--){
            for(int c = cnum-1; c > 0; c--){
                if(m[r][0] == 0 || m[0][c] == 0){
                    m[r][c] = 0;
                }
            }
            if(colIsZero == 1) m[r][0] = 0;
        }
    }
};