class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid = 0;
        while(l < r){
            mid = l + (r-l)/2;
            int cur_num = ((nums[mid]<nums[0]) == (target<nums[0])) 
                        ?nums[mid]
                        :(target>=nums[0])?INT_MAX:INT_MIN ;
            if(target > cur_num){
                l = mid+1;
            }else if(target < cur_num) {
                r = mid;
            }else{
                return mid;
            }
        }
        return -1;
       /* int len = nums.size();
        int l = 0, r = len-1, mid = 0;
        while(l <= r){
            mid = l + (r-l)/2;
            //cout << l << " ,  " << r << "\n";
            if(nums[mid] == target) return mid;
            if(nums[l] <= nums[mid]){
                if(nums[l] <= target && nums[mid] > target){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                if(target > nums[mid] && target <= nums[r]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        return -1;
        */
    }
};