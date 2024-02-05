class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            // Check for overflow or underflow
            if(res > INT_MAX/10 || res < INT_MIN/10){
                return 0;
            }
            res = res * 10 + x % 10; // Add the last digit to the result
            x /= 10; // Move to the next digit
        }      
        return res;
    }
};