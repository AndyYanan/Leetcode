class Solution {
public:
    int countHomogenous(string s) {
        // a b b c c  c  a  a
        //                  ↑
        // 1 1 2 1 2  3  1  2
        // 1 2 4 5 7 10 11 13
        int res = 0, cnt = 0;// cnt: track the length of current homogenuous substring
        int len = s.size();
        for(int i = 0; i < len; i++){
            // check whether it is the same as previous one
            // If yes, it means the current character is a continuation of 
            // a homogeneous substring, so cnt is incremented
            if(i > 0 && s[i-1] == s[i]){
                cnt++;
            }else{ // If not the same, cnt is reset to 1, indicating the start of a new homogenous substring
                cnt = 1;
            }
            // the length of the current homogenouis substring is added to the overall count res
            res = (res + cnt) % (int)(1e9 + 7);
        }
        return res;
    }
};