class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        /* // sol 1
        for(int i = 0; i <= n; ++i){
            int cnt = 0;
            int num = i;
            while(num){
                cnt++;
                num = num & (num-1);
            }
            res[i] = cnt;
        }
        */
        /* // sol 1
        for(int i = 1; i <= n; ++i){
            res[i] = res[i >> 1] + i % 2;
        }
        */
        int offset = 1;
        for(int i = 1; i <= n; i++){
            if(offset*2 == i){
                offset = i;
            }
            res[i] = 1 + res[i-offset];
        }
        return res;
    }
};