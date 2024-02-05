/*
string build(string s){
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#') c=max(0,--c);
            else s[c++]=s[i];
        }
        return s.substr(0,c);
    }
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }
*/
class Solution {
public:
    string getNewString(string & str){
        int cntr = 0;
        string res = "";
        for(int i = str.size()-1; i>=0; i--){
            if(str[i] == '#'){
                ++cntr;
            }else{
                if(cntr > 0){
                    --cntr;
                }else{
                    res += str[i];
                }
            }
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        return getNewString(s) == getNewString(t);
        /*
        int s_right = s.size();
        int t_right = t.size();
        while(true){
            int back = 0;
            while(s_right >= 0 && (back > 0 || s[s_right] == '#')){
                back = back + (s[s_right] == '#' ? 1 : -1);
                s_right--;
            }
            back = 0;
            while(t_right >= 0 && (back > 0 || t[t_right] == '#')){
                back = back + (t[t_right] == '#' ? 1 : -1);
                t_right--;
            }
            if(s_right >= 0 && t_right >= 0 && (s[s_right]==t[t_right])){
                s_right--;
                t_right--;
            }else{
                break;
            }
        }
        return t_right==-1 && s_right==-1;
        */
    }
};
