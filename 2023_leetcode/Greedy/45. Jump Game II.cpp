class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int coverPosition = 0, nextCoverPosition = 0;
        int res = 0;
        for(int i = 0; i <= coverPosition; i++){
            nextCoverPosition = max(nextCoverPosition, i + nums[i]);
            if(i == coverPosition){
                res++;
                coverPosition = nextCoverPosition;
                if(coverPosition >= nums.size()-1){
                    break;
                }
            }
        }
        return res;
    }
};
