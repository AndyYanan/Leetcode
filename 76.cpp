class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0, cntr = t.size();
        int minStart = 0, minLen = INT_MAX;
        vector<int> dic(128, 0);
        for(auto c:t) {
            dic[c]++;
        }
        while(end < s.size()){
            if(dic[s[end]] > 0){
                cntr--;
            }
            dic[s[end]]--;
            end++;
            while(cntr == 0){
                if(end-start < minLen){
                    minStart = start;
                    minLen = end-start;
                }
                dic[s[start]]++;
                if(dic[s[start]]>0){
                    cntr++;
                }
                start++;
            }
        }
        return minLen!=INT_MAX ? s.substr(minStart, minLen):"";

    }
};