class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int x = 0, y = 0;
        while(pq.size()>1){
            y = pq.top();
            pq.pop();
            x = pq.top();
            pq.pop();
            if(y>x) pq.push(y-x);
        }
        return pq.empty()?0:pq.top();

    }
};