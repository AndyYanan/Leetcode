class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);

        dp[0] = 1;// Define empty string is always breakable
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < i; j++) {
                if (dp[j]){ // if dp[j] is true, meaning the substring up to index j is breakable
                    // check if the substring from index j to i is in wordDict
                    // If yes, it sets dp[i] to ture and breaks out of the inner loop
                    string tmpStr = s.substr(j, i - j);
                    if (wordSet.find(tmpStr) != wordSet.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};