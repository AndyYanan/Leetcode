class Solution {
public:
    string minWindow(string s, string t) {
        //Input: s = "ADOBECODEBANC", t = "ABC"
        //Output: "BANC"
        int p_fast = 0, p_slow = 0, start = 0;
        int tar_len = t.size(), min = INT_MAX;
        vector<int> vec(128,0);
        for(auto c:t) {vec[c]++;}
        while(p_slow < s.size() && p_fast <= s.size()){
            if(tar_len > 0){
                if(p_fast == s.size()) break;
                if(--vec[s[p_fast++]] >= 0){
                   tar_len--;
                }  
            }else{
                if((p_fast - p_slow) < min){
                    min = p_fast-p_slow;
                    start = p_slow;
                }
                if(++vec[s[p_slow++]] > 0){
                    tar_len++;
                }
            }
        }
       return min == INT_MAX ? "" : s.substr(start, min);
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        //Input: s = "ADOBECODEBANC", t = "ABC"
        //Output: "BANC"
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
