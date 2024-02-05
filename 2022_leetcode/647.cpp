class Solution {
    int count = 1;
public:
    int countSubstrings(string s) {
        if(s.size() == 0) return 0;
        // aabaa
        for(int i = 0; i < s.size()-1; ++i){
             isPalindromic(s, i, i); //odd
             isPalindromic(s, i, i+1); // even
        }
        return count;
    }

    void isPalindromic(string s, int i, int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
    }
};