class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dic;
        for(int i = 0; i < nums.size(); ++i){
            if(dic[nums[i]]){return true;}
            dic[nums[i]]++;
        }
        return false;

        /*
        unordered_set<int> setNum;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            setNum.insert(nums[i]);
            cnt++;
            if(setNum.size() < cnt) return true;
        }
        return false;
        */
    }
};