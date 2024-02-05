class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dic[128] = {0};
        int p_left = 0, res = 0;
        for(int i = 0; i < s.size(); ++i){
            dic[s[i]]++;
            while(dic[s[i]] > 1){
                dic[s[p_left++]]--;
            }
            res = max(res, i-p_left+1);
        }
        return res;
/*
        vector<int> dic(256, -1);
        int start = -1, res = 0;
        for(int i = 0; i < s.size(); ++i){
            if(dic[s[i]] > start){
                start = dic[s[i]];
            }
            dic[s[i]] = i;
            res = max(res, i-start);
        }
        return res;
*/

/*
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
*/
    }
};
