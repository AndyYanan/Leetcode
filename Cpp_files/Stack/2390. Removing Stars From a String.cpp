class Solution {
public:
    string removeStars(string s) {
        int lenOfString = s.size();
        stack<char> st;

        for(int i = 0; i < lenOfString; ++i){
            if(s[i] == '*'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

        string res = "";
        int len = st.size();
        for(int i = 0; i < len; ++i){
            res = res + st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};