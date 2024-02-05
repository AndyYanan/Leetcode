class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int len = nums.size();
        int prefix[len];
        int res = 0;
        prefix[0] = nums[0];
        for(int i = 1; i < len; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < len; i++){
            if(prefix[i] == goal) res++;
            if(mp.count(prefix[i] - goal)) res += mp[prefix[i] - goal];
            mp[prefix[i]]++;
        }
        return res;
      
       /* int sum = 0, res = 0, tar = 0;
        unordered_map<int, int> mp;
        for(auto num:nums){
            sum += num;
            tar = sum - goal;
            if(tar == 0) res++;
            if(mp.count(tar)) res += mp[tar];
            mp[sum]++;
        }
        return res;
        */
    }
};