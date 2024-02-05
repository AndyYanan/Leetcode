class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int p_l = 0, p_r = nums.size()-1;
        for(int i = nums.size()-1; i>=0; --i){
            if(std::abs(nums[p_l]) > std::abs(nums[p_r])){
                res[i] = std::pow(nums[p_l++], 2);
            }else{
                res[i] = std::pow(nums[p_r--], 2);
            }
        }
        return res;
    }
};