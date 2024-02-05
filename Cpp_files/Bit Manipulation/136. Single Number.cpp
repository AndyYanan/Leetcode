class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
        int i = 1;
        for(i = 1; i < nums.size(); ++i){
            nums[i] = nums[i] ^ nums[i-1];
        }
        return nums[i-1];
       /*
        unordered_set<int> numSet;
        long long sum = 0, sumSet = 0;
        for(int& n : nums){
            numSet.insert(n);
            sum += n;
        }
        for(auto& n : numSet){
            sumSet += n;
        }
        return sumSet*2-sum;
        */
    }
};