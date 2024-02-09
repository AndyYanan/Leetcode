class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = neededTime[0], max_time = neededTime[0];
        for(int i = 1; i < colors.size(); i++){
            if(colors[i] != colors[i-1]){
                sum -= max_time;
                max_time = 0;
            }
            sum += neededTime[i];
            max_time = max(max_time, neededTime[i]);
        }
        return sum - max_time;
        /*
        int res = 0;
        int sum_tmp = neededTime[0], max_tmp = neededTime[0];
        for(int i = 1; i < colors.size(); i++){
            if(colors[i] != colors[i-1]){
                res += sum_tmp - max_tmp;
                sum_tmp = 0;
                max_tmp = 0;
            }
            sum_tmp += neededTime[i];
            max_tmp = max(max_tmp, neededTime[i]);
        }
        res += sum_tmp - max_tmp;
        return res;
        */
    }
};