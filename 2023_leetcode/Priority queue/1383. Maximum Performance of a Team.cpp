class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> table;
        int len = speed.size();
        for(int i = 0; i < len; i++){
            table[i] = make_pair(efficiency[i], speed[i]);
        }
        sort(table.begin(), table.end());
        reverse(table.begin(), table.end());

        int sum_speed = 0, res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& [e, s] : table){
            pq.push(s);
            sum_speed += s;
            if(pq.size() > k){
                sum_speed -= pq.top();
                pq.pop();
            }
            res = max(res, e * sum_speed);
        }
        return res;
    }
};