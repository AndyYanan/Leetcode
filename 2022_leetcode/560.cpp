class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dic;
        int sum = 0, ans = 0, tar = 0;
        dic[0] = 1;
        for(auto n:nums){
            sum += n;
            tar = sum - k;
            if(dic.find(tar) != dic.end()){
                ans += dic[tar];
            }
            dic[sum]++; //num of ways to get sum
        }   
        return ans;
    }
};