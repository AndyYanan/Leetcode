class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
/*
     	int p_slow = 0;
     	for(int p_fast = 0; p_fast < nums.size(); p_fast++){
     		if(nums[p_fast] != 0){
     			swap(nums[p_fast], nums[p_slow]);
     			p_slow++;
     		}
     	}
/*


/*
        int p_non_zero = 0 ;
        if(nums.size()==1) return;
        for(int i = 0; i < nums.size(); ++i){
        	if(nums[i] == 0){
        		++p_non_zero;
        	}else if(p_non_zero != 0){
        		int tmp = nums[i];
        		nums[i] = 0;
        		nums[i-p_non_zero] = tmp;
        	}
        }
*/
    }
};