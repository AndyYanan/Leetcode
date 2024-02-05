class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0";
        if(k == 0) return num;

        stack<char> st;
        string res = "";
        st.push(num[0]);

        for(int i = 1; i < num.size(); ++i){
            while(st.size() > 0 && k > 0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size() == 1 && num[i] == '0'){
                st.pop();
            }
        } 
        while(k && !st.empty()){
            st.pop();
            k--;
        }

        int n = st.size();
        while(!st.empty()){
            //res = st.top() + res; // Memory Limit exceed;.
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        if(res.length() == 0)
            return "0";
        
        return res;

    }
};