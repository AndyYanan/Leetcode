class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int tar = 0, front = 0, end = 0, sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            tar = -nums[i];
            front = i+1;
            end = nums.size()-1;
            while(front<end){
                sum = nums[front] + nums[end];
                if(sum < tar) front++;
                else if(sum > tar) end--;
                else{
                    vector<int> tmp = {-tar, nums[front], nums[end]};
                    res.push_back(tmp);
                    while(front < end && nums[front]==tmp[1]) front++;
                    while(front < end && nums[end]==tmp[2]) end--;
                }
            }
            while(((i+1) < nums.size()) && nums[i] == nums[i+1]){
                ++i;
            }
        }
        return res;
    }
};

/*
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
*/
