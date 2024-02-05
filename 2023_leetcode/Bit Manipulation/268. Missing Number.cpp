class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // solution 1
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            res = res ^ i ^ nums[i];
        }      
        return res ^ nums.size();     

        /*
        // solution 2
        int sum = 0;
        int inputSum = 0;
        for(int i = 0; i < nums.size(); ++i){
            inputSum += nums[i];
            sum += i;
        }
        return sum + nums.size() - inputSum;

        /*
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += (i - nums[i]);
        }
        return sum + nums.size();
        */
        */

        /*
        // solution 3
        int left = 0, right = nums.size();
        sort(nums.begin(), nums.end());
        while(left < right){
            int mid = left + (right-left)/2;
            cout << left << " " << mid << " " << right << endl;
            if(nums[mid] > mid){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
        */

        
    }
};