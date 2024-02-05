class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Time: O(NlogN), Space: O(1)
        sort(nums.begin(), nums.end());
        long l = 0, r = 0, res = 1, sum = 0;
        for(; r < nums.size(); r++){
            sum += nums[r];
            // Grow the window when it's valid, Shift the window when it's invalid
            // window will not shrink
            if((r - l + 1) * nums[r] - sum > k) sum -= nums[l++];
        }
        return r - l;
        /*
            sort(begin(A), end(A));
            long l = 0, N = nums.size(), ans = 1, sum = 0;
            for(int r = 0; r < N; r++){
                sum += nums[r];
                while((r - l + 1) * nums[r] - sum > k) sum -= nums[l++];
                ans = max(ans, r - l + 1);
            }
            return ans;
        */

    }
};