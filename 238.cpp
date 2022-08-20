class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //nums = [1,2,3,4]
        vector<int> res(nums.size(), 1);
        int post_mul = 1;
        for(int i = 1; i < nums.size(); ++i){
            //res = [1,1,2,6]
            res[i] = res[i-1] * nums[i-1];
        }
        for(int i = nums.size()-1; i >= 0; --i){
            res[i] *= post_mul;
            //post_mul = 1 4 12 24
            // res = [24,12,8,6]
            post_mul *= nums[i];
        }
        return res;
    }
};
