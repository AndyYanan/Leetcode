class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Input: nums = [100,4,200,1,3,2]
        //Output: 4
        unordered_set<int> setDic(nums.begin(), nums.end());
        int longest_res = 0;
        int subsec_num = 0;
        for(auto &n:nums){
             if(!setDic.count(n-1)){
                subsec_num = 1;
                //for(int i = 1; setDic.count(n+i); ++i){
                while(setDic.count(n+subsec_num)){  
                    setDic.erase(n+subsec_num);
                    subsec_num++;
                }
                longest_res = max(longest_res, subsec_num);
             }
        }
        return longest_res;

    }
};