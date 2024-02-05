class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt_zero = 0;
        for(; r < nums.size(); r++){
            if(nums[r] == 0){
                cnt_zero++;
            }
            if(cnt_zero > k){
                if(nums[l++] == 0) cnt_zero--;
            }
        }
        return r - l;
    }
};