class Solution {
public:
    vector<vector<string>> res;
    vector<string> tmpVec;
    vector<vector<string>> partition(string s) {
        if(s.empty()) return res;
        findPalindrome(s, 0);
        return res;
    }
    void findPalindrome(string s, int startIdx){
        if(s.size() == startIdx){
            res.push_back(tmpVec);
            return;
        }
        for(int i = startIdx; i < s.size(); ++i){
            if(isPalindrome(s, startIdx, i)){
                tmpVec.push_back(s.substr(startIdx, i - startIdx + 1));
                findPalindrome(s, i+1);
                tmpVec.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int left, int right){
        while(left <= right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
};