class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return dfs(s, pos);
    }
    string dfs(string &s, int& pos){
        string res = "", word = "";
        int len = 0;
        for(; pos < s.size(); ++pos){
            if(s[pos] == '['){
                word = dfs(s, ++pos);
                while(len > 0){
                    res = res + word;
                    len--;
                }
            }else if(s[pos] == ']'){
                return res;
            }else if(s[pos] >= '0' && s[pos] <= '9'){
                len = len*10 + s[pos] - '0';
            }else{
                res += s[pos];
                
            }
        }
        return res;
    }
};;