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

/*
class Solution {
private:
    int max_len, start_idx;
    void findLongest_Palid(string s, int left, int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        left++;
        right--;
        if(max_len < (right-left+1)){
            max_len = right-left+1;
            start_idx = left;
        }
    }
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len < 2){
            return s;
        }
        for(int i = 0; i < len-1; ++i){
            findLongest_Palid(s ,i ,i);//center is one char
            findLongest_Palid(s ,i ,i+1);//center is two same char
        }
        return s.substr(start_idx, max_len);
    }

};
*/
