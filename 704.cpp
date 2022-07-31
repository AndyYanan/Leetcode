class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len-1, mid = 0;
        while(l <= r){
            mid = l+(r-l)/2;
            if(nums[mid] < target){
                l = mid+1;
            }else if(nums[mid] > target){
                r = mid -1;
            } else{
                return mid;
            }
        }
        return -1;
    }
};