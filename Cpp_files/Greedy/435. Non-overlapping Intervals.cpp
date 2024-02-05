class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& A) {
        int res = 0;
        sort(A.begin(), A.end());
        int lastIdx = A[0][1];
        
        for(int i = 1; i < A.size(); ++i){
            if(lastIdx > A[i][0]){
                res++;
                lastIdx = min(lastIdx, A[i][1]);
            }else{
                lastIdx = A[i][1];
            }
        }
        return res;
    }
};