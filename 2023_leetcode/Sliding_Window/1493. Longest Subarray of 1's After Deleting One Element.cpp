class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, len = nums.size(), l = 0, r = 0;
        int cntZero = 0;
        for(; r < len; r++){
            if(nums[r] == 0) cntZero++;
            if(cntZero > 1){
                if(nums[l] == 0) cntZero--;
                l++;
            }
        }
        return r - l - 1;

    }
};/*
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, zero = 0;
        int res = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0){
                zero++;
            }
            while(zero > 1){
                if(nums[l] == 0){
                    zero--;
                }
                l++;
            }
            res = max(res, r-l);
        }
        return res;
    }
};*/