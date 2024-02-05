class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int last = nums.size()-1;
        for(int i = last-1; i >= 0; --i){
            if(i + nums[i] >= last){
                last = i;
            }
        }
        return last == 0;
        /*
        int n = nums.size();
        int reach = 0;
        for(int i = n-2; i >= 0; i--){
            reach++;
            if(nums[i]>=reach){
                reach = 0;
            }
        }
        if(reach == 0) return true;
        else return false;
        
        int n = nums.size();
        int idx = 0;
        for(int i = 0; i < idx; i++){
            if(i>idx){
                return false;
            }
            idx = max(idx, i+nums[i]);
            if(idx >= n-1){
                return true;
            }
        }
        return false;
        */
    }
};