class Solution {
    unordered_map<int,int> closePos;
private:
    string dfs_decode(string &s, int l, int r){
        string res = "";
        int num = 0;
        while(l <= r){
            char c = s[l];
            if(isdigit(c)){
                num = num*10 + c-'0';
            }else if(c =='['){
                string sub = dfs_decode(s, l+1, closePos[l] -1);
                for(int i = 0; i < num; ++i){
                    res += sub;
                }
                num = 0;
                l = closePos[l];
            }else{
                res+=c;
            }
            ++l;
        }
        return res;
    }
public:
    string decodeString(string s) {
        //s = "3[a2[c]] = accacccacc"
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '['){
                st.push(i);
            }else if(s[i] ==']'){
                closePos[st.top()]= i;
                st.pop();
            }
        }
        return dfs_decode(s, 0, s.size()-1);
    }
};
/*
class Solution {
private:
    string dfs_decode(int &pos, string &s){
        int s_len = s.size();
        string res = "", word = "";
        int cnt = 0;
        for(; pos < (s_len); ++pos){
            if(s[pos] == '['){
                word = dfs_decode(++pos, s);
                for(;cnt > 0; --cnt){
                    res+=word;
                }
            }else if(s[pos] >= '0' && s[pos] <='9'){
               cnt = cnt*10 + (s[pos] - '0');// *10, for example, 12a[666[b]]
            }else if(s[pos] == ']'){
                return res;
            }else{
                res+=s[pos];
            }
        }
        return res;
    }
public:
    string decodeString(string s) {
        //s = "3[a2[c]] = accacccacc"
        int pos = 0;
        return dfs_decode(pos, s);
    }
}; */