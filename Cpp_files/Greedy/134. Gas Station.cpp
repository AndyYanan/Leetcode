class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_surplus = 0, curr_surplus = 0;
        int start = 0;
        for(int i = 0; i < n; ++i){
            curr_surplus += gas[i] - cost[i];
            total_surplus += gas[i] - cost[i];
            if(curr_surplus < 0){
                start = i + 1;
                curr_surplus = 0;
            }
        }
        return total_surplus >= 0 ? start : -1;
#if 0 //TLE
        int remainGas = 0;
        int road = gas.size(); //5
        int state = 0;
        for(int i = 0; i < road; ++i){
            int cnt = i;
            while(cnt < road){
                remainGas += gas[cnt];
                remainGas = remainGas - cost[cnt];
                if(remainGas < 0){
                    break;
                }
                cnt = (cnt+1) % road;
 
                if(++state == road){
                    return i;
                }
            }
            remainGas = 0;
            state = 0;
        }
        return -1;
#endif
    }
}; 