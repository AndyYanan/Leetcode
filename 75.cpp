class Solution {
public:
    final int NUM = 3;
    void sortColors(vector<int>& nums) {
        int *dic = new int[MAX];
        int cnt = 0;
        for(auto n:nums){
            dic[n]++;
        }      
        for(int i = 0; i < NUM; ++i){
            for(int j = 0; j < dic[i]; ++j){
                nums[cnt++] = i;
            }
        }
    }
};