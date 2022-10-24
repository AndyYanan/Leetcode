class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1;
        int left = 0, right = 0, start = 0;
        for(int i = 0; i < s.size(); ++i){
            right = i;
            while(right<s.size() && s[i]==s[right]){
                right++;
            }
            left = i-1;    
            while(left>=0 && (right<s.size()) && s[left]==s[right]){
                right++;
                left--;
            }
            if((right-left-1) > len){
                len = (right-left-1);
                start = left+1;
            }
        }
        return s.substr(start, len);
    }
};