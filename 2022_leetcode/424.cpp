class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        int res = 0, left = 0, max_L;
        unordered_map<int, int> cntr;
        for(int i = 0; i < len; ++i){
            max_L = max(max_L, ++cntr[s[i]]);
            if(i-left-max_L < k){
                res++;
            }else{
                --cntr[s[left]];
                left++;
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, max_L = 0;
        unordered_map<int, int> cntr;
        for(int j = 0; j < s.size(); j++){
            max_L = max(max_L, ++cntr[s[j]]);
            if(res - max_L < k){
                res++;
            }else{
                cntr[s[j-res]]--;
            }
        }
        return res;
        
        int left = 0;
        vector<int> cntr(26.0);
        int max_L = 0, i = 0;
        for(int j = 0; j < s.size(); j++){
            max_L = max(max_L, ++cntr[s[j] - 'A']);
            if((j-left+1-max_L) > k){
                --cntr[s[left] - 'A'];
                left++;
            }
        }
        return s.size()-left;
        
    }
};

 */
