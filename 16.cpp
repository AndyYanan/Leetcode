class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int res = nums[0] + nums[1] + nums[len-1];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len-2; ++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int start = i+1, end = len-1;
            while(start < end){
                int tmp_sum = nums[i]+nums[start]+nums[end];
                if(tmp_sum > target) end--;
                else if(tmp_sum < target) start++;
                else{
                    res = tmp_sum;
                    i = len-2;
                    break;
                }
                if(std::abs(tmp_sum-target) < std::abs(res-target)){
                    res = tmp_sum;
                }
            }
        }
        return res;
    }
};