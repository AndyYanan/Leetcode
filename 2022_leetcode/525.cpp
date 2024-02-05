class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; mp[0]=-1;
        int sum = 0,longest_subarray = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += (nums[i] == 0) ? - 1 : 1;    
            if(mp.find(sum) != mp.end()){
                longest_subarray = max(longest_subarray, i - mp[sum]);
            }
            else{ // only first i of sum will be update to mp
                mp[sum] = i;
            }
        }
        return longest_subarray;

        /*int max_len = 0;
        int num_zero = 0, num_one = 0;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i; j < nums.size(); ++j){
                if(nums[j] == 0){
                    num_zero++;
                }else{
                    num_one++;
                }
                if(num_one == num_zero){
                    max_len = max(max_len, j-i+1);
                }
            }
            num_one = num_zero = 0;
        }
        return max_len;*/
    }
};