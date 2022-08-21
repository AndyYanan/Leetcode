class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int> dic;
        for(auto n:nums){
            if(++dic[n] > n/2){
                return n;
            }
        }
        return 0;
    }
};