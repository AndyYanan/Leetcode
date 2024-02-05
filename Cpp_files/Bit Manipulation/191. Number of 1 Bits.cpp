class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        /*
        while(n){
            if(n & 0x1){
                sum++;
            }
            n = n>>1;
        }
        return sum;
        */
        while(n){
            n = n & (n-1); // remove the rightmost "1"
            sum++;
        }
        return sum;
    }
};