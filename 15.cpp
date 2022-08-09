class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int tar = 0;
        int l = 0, r = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; ++i){
            if(i>0 && nums[i] == nums[i-1]) continue;
            l = i + 1;
            r = nums.size()-1;
            tar = -nums[i];
            while(l < r){
                if((nums[l]+nums[r])<tar){
                    l++;
                }else if((nums[l]+nums[r])>tar){
                    r--;
                }else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1]){ l++;}
                    while(l<r && nums[r]==nums[r-1]){ r--;}
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};