class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        int idx = 0;
        for(int i = 0; i < g.size(); i++){
            if(g[i] <= s[idx]){
                idx++;
                res++;
            }
        }
        return res;
    }
};