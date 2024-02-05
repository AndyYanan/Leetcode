class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& B) {
        vector<vector<int>> res;
        int idx = 0;
        while((idx < A.size()) && B[0]>A[idx][1]){
            res.push_back(A[idx]);
            idx++;            
        }
        while((idx < A.size()) && B[1]>=A[idx][0]){
            B[0] = min(B[0], A[idx][0]);
            B[1] = max(B[1], A[idx][1]);
            idx++;            
        }
        res.push_back(B);
        while(idx < A.size()){
            res.push_back(A[idx]);
            idx++;
        }
        return res;
    }
};