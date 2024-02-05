class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       // O(nlogk)
       // max-heap
       priority_queue<int> pq(nums.begin(), nums.end());
       for(int i = 0; i < k-1; ++i){
           pq.pop();  // 6 5 4 3 2 1, k = 3 -> res = 4 3 2 1
       }
       return pq.top(); //4
       /*
       // min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num:nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
        */
    }
};