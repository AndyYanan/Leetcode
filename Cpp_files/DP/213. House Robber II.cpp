class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len ? nums[0] : 0;
        return max(robber(nums, 1, len), robber(nums, 0, len-1));
    }
    int robber(vector<int>& nums, int start, int end){
        int twoBefore = 0, oneBefore = 0; 
        int res = 0;
        for(int i = start; i < end; ++i){
            res = max(twoBefore + nums[i], oneBefore);
            twoBefore = oneBefore;
            oneBefore = res;
        }
        return res;
    }
};