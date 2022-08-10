class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> dic;
        int len = strs.size();
        if(len == 0) return res;
        for(auto str:strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            dic[tmp].push_back(str);
        }
        for(auto str:dic){
            res.push_back(str.second);
        }
        return res;
    }
};