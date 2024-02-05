class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0, tar = 0, ans = 0;
        unordered_map<int, int> mp; // Hashmap to store the count of prefix sums;
        for (int i = 0; i < len; ++i) {
            sum += nums[i]; // Incrementally calculate the prefix sum

            tar = sum - k; // Calculate the target value needed to achieve the sum of k

            if (tar == 0) {
                ans++; // If the current sum equals k, increment the answer count
            }

            // Check if there exists a previous prefix sum that satisfies the condition (sum - prevSum = k),
            // where prevSum represents the prefix sum up to some earlier index.
            if (mp.count(tar)) {
                ans += mp[tar]; // Increment the answer count by the number of valid subarrays found so far
            }

            mp[sum]++; // Store the current prefix sum in the hashmap along with its count
        }
        retuen ans;
       /* int len = nums.size();
        int prefix[len]; // Array to store the prefix sum of elements
        prefix[0] = nums[0];
        
        // Step 1: Calculate the prefix sum of elements
        for (int i = 1; i < len; ++i){
            prefix[i] = nums[i] + prefix[i - 1];
        }
        
        int ans = 0; // Initialize the count of subarrays with sum equals k
        unordered_map<int, int> mp; // Unordered map to store the count of prefix sums
        
        // Step 2: Traverse through the prefix sums and find subarrays with sum equals k
        for (int i = 0; i < len; ++i){
            if (prefix[i] == k){ // If the prefix sum itself equals k, increment the count
                ans++;
            }
            
            // Check if there exists a previous prefix sum that satisfies the condition (prefix[i] - prefix[j] = k),
            // where j < i.
            if (mp.find(prefix[i] - k) != mp.end()){
                ans += mp[prefix[i] - k]; // Increment the count by the number of valid subarrays found so far
            }
            
            mp[prefix[i]]++; // Add the current prefix sum to the map
        }
        
        return ans; // Return the total count of subarrays with sum equals k
        */
    }
};
