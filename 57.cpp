class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& B) {
        int len = A.size();
        int idx = 0;
        vector<vector<int>> res;
        vector<int> ins;
        while(idx < len){
            if(B[0]<A[i][1]){
                ins.push_back(A[i][0]);
            }else if(B[1]<=A[i][1]){
                ins.push_back(A[i][0]);
            }
            else{
                res.push_back(A[i]);
            }
            idx++;
        }
    }
};