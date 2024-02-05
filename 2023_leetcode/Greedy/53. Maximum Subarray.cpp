class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, smax = INT_MIN;
        for(auto num:nums){
            sum  = max(num, num+sum);
            smax = max(sum, smax);
        }
        return smax;
    }
};
