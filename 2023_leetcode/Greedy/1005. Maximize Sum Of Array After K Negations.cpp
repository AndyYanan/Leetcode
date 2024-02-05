class Solution {
public:
    /*
    static bool cmp(int a, int b){
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 1. Sort the array in decreasing order based on the absolute values
        // 2. Traverse from the beginning to the end of the array, 
        //    if a negative number is encountered, make it positive and decrement K
        // 3. If K is still greater than 0, make the smallest positive value negative
        // 4. Sum
        sort(nums.begin(), nums.end(), cmp);

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < 0 && k > 0){
               nums[i] *= (-1);
               k--; 
            }
        }
        if(k % 2 == 1) nums[nums.size()-1] *= -1;
        int res = 0;
        for(int &num:nums){
            res += num;
        }
        return res;
    }
    */
    /*
    int largestSumAfterKNegations(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int res = 0;
        for(int i = 0; i < A.size(); ++i){
            if(A[i] < 0 && k > 0){
                k--;
                A[i] = -A[i];
            }
        }
        int minVal = INT_MAX;
        for(int &num:A){
            res += num;
            minVal = min(minVal, num);
        }
        return res - (k%2)*2*(minVal);
    }
    */
        int largestSumAfterKNegations(vector<int>& A, int k) {
            priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
            while(k--){
                int tmpEle = pq.top();
                pq.pop();
                pq.push(-1 * tmpEle);
            }
            int res = 0;
            while(!pq.empty()){
                res += pq.top();
                pq.pop();
            }
            return res;
        }
};