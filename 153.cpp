class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid;
        while(nums[l] > nums[r]){
            mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return nums[l];
        /*
        int l = 0, r = nums.size()-1, mid = 0;
        while(r>=l){
            mid = l + (r-l)/2;
            cout << mid << "," << l << "," << r << "\n";
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else if(nums[mid] < nums[r]){
                r = mid;
            }else{
                return nums[mid];
            }
        } 
        return -1;
        */
    }
};