class Solution {
public:
    string dfs(string &s, int &pos){
        string res = "", word = "";
        int cnt = 0;
        for(; pos < s.size(); ++pos){
            if(s[pos] == '['){
                word = dfs(s, ++pos);
                for(; cnt > 0; cnt--){
                    res += word;
                }
            }else if(s[pos] == ']'){
                return res;
            }else if(s[pos] >= '0' && s[pos] <= '9'){
                cnt = cnt*10 + s[pos]-'0';
            }else{
                res += s[pos];
            }
        }
        return res; 
    }
    string decodeString(string s) {
        int pos = 0;
        return dfs(s, pos);    
    }
};