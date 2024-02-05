class KthLargest {
private:
    int kth; // The value of k for the kth largest element
    priority_queue<int, vector<int>, greater<int>> pq; // Min heap to store the k largest elements
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->kth = k; // Initialize the value of k
        for (int n : nums) {
            this->add(n); // Add each element from nums to the min heap
        }
    }
    
    int add(int val) {
        pq.push(val); // Add the new value to the min heap
        
        // If the size of the min heap exceeds k, remove the smallest element
        if (pq.size() > this->kth) {
            pq.pop();
        }
        
        // The top of the min heap will always be the kth largest element
        return pq.top();
    }
};
