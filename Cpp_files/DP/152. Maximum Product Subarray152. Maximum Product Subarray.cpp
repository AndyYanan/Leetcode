class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int dpMax = nums[0], dpMin = nums[0];
        int res = nums[0];
        for(int i = 1; i < n; i++){
            int preMax = dpMax, preMin = dpMin;
            dpMax = max(nums[i], nums[i]*(nums[i] >= 0 ? preMax : preMin));
            dpMin = min(nums[i], nums[i]*(nums[i] >= 0 ? preMin : preMax));
            cout << dpMax << "  " << dpMin << endl;
            res = max(res, dpMax);
        }
        return res;


        /*
        if(nums.empty()) return 0;
        int max_v = 1, min_v = 1;
        int res = INT_MIN;
        for(int n:nums){
            if(n<0){
                swap(max_v, min_v);
            }

            max_v = max(max_v*n, n);
            min_v = min(min_v*n, n);
            res = max(res, max_v);
        }
        return res;
        */

        /*
        int left_v = 1, right_v = 1;
        int max_v = nums[0], len = nums.size();
        for(int i = 0; i < len; ++i){
            left_v = (left_v?left_v:1) * (nums[i]);
            right_v = (right_v?right_v:1) * (nums[len-i-1]);
            max_v = max(max_v, max(left_v, right_v));
        }   
        return max_v;
        */

        /*
        int res = INT_MIN;
        int maxP = INT_MIN, tmp = 1;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i; j < nums.size(); ++j){
                tmp *= nums[j];
                maxP = max(maxP, tmp);
            }
            res = max(res, maxP);
            maxP = INT_MIN;
            tmp = 1;
        }
        return res;
        */
    }
};