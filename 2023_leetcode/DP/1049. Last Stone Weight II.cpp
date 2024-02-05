class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(1501, 0);
        int n = stones.size();
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += stones[i];
        }

        int tar = sum/2;
        for(int i = 0; i < n; ++i){
            for(int j = tar; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
               // cout << dp[j] << "       j =" << j << "      j - stones[i] = " << j - stones[i] << endl;
            }
        }
        //cout << sum << " " << tar << endl;
        return (sum - dp[tar]) - dp[tar];
    }
};