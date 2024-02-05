class Solution {
public:
    int atmostk(vector<int> nums, int k){
        int res = 0, r = 0, l = 0;
        unordered_map<int, int> cnt;
        for(; r < nums.size(); r++){
            cnt[nums[r]]++;
            while(cnt.size() > k){
                cnt[nums[l]]--;
                if(cnt[nums[l]] == 0){
                    cnt.erase(nums[l]);
                }
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums, k) - atmostk(nums, k-1);
    }
};