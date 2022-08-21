class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_surplus = 0, surplus = 0, start = 0;
        for(int i = 0; i < n; ++i){
            surplus += gas[i] - cost[i];
            if(surplus < 0){
                total_surplus += surplus;
                surplus = 0;
                start = i+1;
            }
        }
        return (total_surplus+surplus)>=0?start:-1;


        /* TLE
        int ret = 0, sum = 0;
        int len = gas.size();
        for(int start = 0; start < len; ++start){
            sum = gas[start];
            for(int traval = 0; traval < len; ++traval){
                sum -= cost[(traval+start)%len];
                if(sum < 0) break;
                sum += gas[(traval+start)%len];
                if(traval == (len-1)) return start;
            }
            sum = 0;
        }
        return -1;
        */
    }
};