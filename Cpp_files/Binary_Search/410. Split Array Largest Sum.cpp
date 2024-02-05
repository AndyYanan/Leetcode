class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for(auto n : nums){
            l = max(l, n);
            r += n;
        }

        while(r > l){
            int m = l + (r-l)/2;
            int cur = 0, split = 1;
            for(int i = 0; i < nums.size(); ++i){
                if(cur + nums[i] > m){
                    cur = nums[i];
                    split++;
                }else{
                    cur += nums[i];
                }
            }
            if(split > k){
                l = m + 1;
            }else{
                r = m;
            }
        }
        return r;
    }
};