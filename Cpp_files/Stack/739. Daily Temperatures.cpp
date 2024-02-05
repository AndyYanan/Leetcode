class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int len = temp.size();
        vector<int> res(len, 0);
        stack<int> st_tempIdx{};
        for(int i = len-1; i >= 0; --i){
            while(!st_tempIdx.empty() && temp[i] >= temp[st_tempIdx.top()]){
                st_tempIdx.pop();
            }
            if(!st_tempIdx.empty())
                res[i] = st_tempIdx.top() - i;
            st_tempIdx.push(i);
        }
        return res;
    }
};