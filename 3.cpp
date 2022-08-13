class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ch[128] = {0};
        int cntr = 0;
        int l = 0, r = 0;
        while(r < s.size()){
            ch[s[r]]++;
            while(ch[s[r]] > 1){
                ch[s[l++]]--;
            }
            cntr = max(cntr, r-l+1);
            r++;
        }
        return cntr;
    }
};