class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, min_p = INT_MAX;
        for(auto p:prices){
            min_p = min(min_p, p);
            res = max(res, p-min_p);
        }
        return res;
    }
};