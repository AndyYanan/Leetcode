class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len));
        int cnt = 0;
        for(int i = len-1; i >= 0; i--){
            for(int j = i; j < len; j++){
                if(i == j){
                    dp[i][j] = 1;
                }else if(i == (j-1)){
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                }else{
                    dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : 0;
                }
                cnt += dp[i][j];
            }
        }
        return cnt;
        /*
        int len = s.size();
        int left = 0, right = 0, cnt = 0;
        for(int i = 0; i < len; ++i){
            //even
            left = i;
            right = i;
            while(left >= 0 && right < len && s[left] == s[right]){
                cnt++; left--; right++;
            }
            //odd
            left = i;
            right = i+1;
            while(left >= 0 && right < len && s[left] == s[right]){
                cnt++; left--; right++;
            }
        }
        return cnt;
        */

    }
};