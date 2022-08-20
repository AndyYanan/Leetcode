class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> dic;
        for(int i = 0; i < nums.size(); ++i){
            if(dic.find(nums[i]) != dic.end()){
                res.push_back(dic[nums[i]]);
                res.push_back(i);
                return res;
            }else{
                dic[target-nums[i]] = i;
            }
        }
        return res;
    }
};