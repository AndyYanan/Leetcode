
class Solution {
public:
    // DP, O(n)
    int numDecodings(string s) {
      if(s.empty()) return 0;
        int n = s.size();
          /*int curPlusOne = 1, curPlusTwo = 0, cur = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                cur = 0;
            } else{
                cur = curPlusOne;
                if(i < n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')){
                    cur += curPlusTwo;
                }
            }
            curPlusTwo = curPlusOne;
            curPlusOne = cur;
        }
        return curPlusOne;*/

        vector<int> dp(n+1);
        dp[n] = 1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
            } else{
                dp[i] = dp[i+1];
                if(i < n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')){
                    dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];

    }
};
/*
class Solution {
public:
    // Memoization O(n)
    int numDecodings(string s) {
        if(s.empty()) return 0;
        vector<int> mem(s.size()+1, -1);
        mem[s.size()] = 1;
        return dfs(0, s, mem);  
    }
    int dfs(int idx, string& s, vector<int>& mem){
        if(mem[idx] > -1) return mem[idx];
        if(s[idx] == '0') {
            mem[idx] = 0;
            return 0;
        }
        int res = dfs(idx+1, s, mem);
        if(idx < (s.size()-1) && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] < '7'))){
            res += dfs(idx+2,s, mem);
        }
        mem[idx] = res;
        return res;
    }
};

class Solution {
public:

    // recursive. TLE, O(2^n)
    int numDecodings(string s) {
        if(s.empty()) return 0;
        return dfs(0, s);  
    }
    int dfs(int idx, string& s){
        if(s[idx] == 0) return 0;
        if(idx == s.size()) return 1;
        int res = dfs(idx+1, s);
        if(idx < (s.size()-1) && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] < '7'))){
            res += dfs(idx+2,s);
        }
        return res;
    }
};
*/