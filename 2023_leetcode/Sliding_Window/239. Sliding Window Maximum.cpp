class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i + 1 >= k){
                res.push_back(nums[dq.front()]);
            }
            if(dq.front() <= i - k + 1){
                dq.pop_front();
            }
        }
        return res;
    }
};