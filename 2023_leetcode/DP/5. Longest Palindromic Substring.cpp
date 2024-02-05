class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0, lenString = 1, start = 0;
        int len = s.size();
        for(int i = 0; i < len; ++i){
            right = i;
            while(right < len && s[i] == s[right]){
                right++;
            }
            left = i-1;
            while(left >= 0 && right < len && s[right] == s[left]){
                right++;
                left--;
            }
            left++;
            right--;
            if(lenString < (right-left+1)){
                lenString = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, lenString);
    }
};

