class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deq_num;
        for(int i = 0; i < nums.size(); ++i){
            while(!deq_num.empty() && nums[i]>=nums[deq_num.back()]){
                deq_num.pop_back();
            }
            deq_num.push_back(i);
            if(i-k+1 >= 0){
                res.push_back(nums[deq_num.front()]);
            }
            if(deq_num.front() <= i-k+1) deq_num.pop_front();
        }
        return res;
    }
};