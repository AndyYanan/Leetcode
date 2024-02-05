class Solution {
public:
    bool isAnagram(string s, string t) {
        int alphabt[26] = {0};
        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0; i < s.size(); ++i){
            alphabt[s[i]]++;
            alphabt[t[i]]--;    
        }
        for(int i = 0; i < 26; ++i){
            if(alphabt[i]) return false;
        }
        return true;
        /*sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return  s == t;
        */
    }
};