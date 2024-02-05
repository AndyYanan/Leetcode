class Solution {
public:
    long maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> table(n);
        int len = speed.size();
        // Create a Vector of pair to store pair of efficiency and speed for each engineer
        for(int i = 0; i < len; i++){
            table[i] = make_pair(efficiency[i], speed[i]);
        }
        // the table vector is sorted in ascending order
        sort(table.begin(), table.end());
        // reserse the sorted vector so that the engineers with the highest efficienct are at the beginning of the vector
        reverse(table.begin(), table.end());

        // Calculate the maximun performance
        long sum_speed = 0, res = 0; //sum_speed will track the cumulative speed

        // pq is used to keep track of the k maximun speeds encountered so far
        // pq is a minHeap, so the smallest speed is at the top
        priority_queue<int, vector<int>, greater<int>> pq;
        // Iterate the table
        for(auto& [e, s] : table){
            pq.push(s);
            sum_speed += s;
            // If the size of the pq exceed k, the engineer with smallest speed is removed from the queue and sum_speed is adjusted
            if(pq.size() > k){
                sum_speed -= pq.top();
                pq.pop();
            }
            res = max(res, e * sum_speed);
        }
        return res % (int)(1e9+7);;
    }
};