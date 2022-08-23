class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         /* 
        vector<int> arr(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            nums[(i+k)%nums.size()]= arr[i];
        }        
        */
        k %=nums.size();
        // 1 2 3 4 5 6 7, k=3
        reverse(nums.begin(), nums.end());
        // 7 6 5 4 3 2 1
        reverse(nums.begin(), nums.begin()+k);
        // 5 6 7 4 3 2 1
        reverse(nums.begin()+k, nums.end());
        // 5 6 7 1 2 3 4

    }
};
