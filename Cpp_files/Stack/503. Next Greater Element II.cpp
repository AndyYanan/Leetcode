class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> stack, res(len, -1);
        for(int i = 0; i < len*2; ++i){
            while(!stack.empty() && nums[i % len] > nums[stack.back()]){
                res[stack.back()] = nums[i % len];
                stack.pop_back();
            }
            stack.push_back(i % len);
        }
        return res;
    }
};

/*
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, -1);
        stack<int> s; // index stack
        for (int i = 0; i < n * 2; i++) {
            int num = nums[i % n]; 
            while (!s.empty() && nums[s.top()] < num) {
                next[s.top()] = num;
                s.pop();
            }
            if (i < n) s.push(i);
        }   
        return next;
    }

*/