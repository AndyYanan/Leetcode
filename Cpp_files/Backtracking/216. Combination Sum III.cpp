// This class Solution implements a backtracking algorithm to find all combinations of 'k' numbers that add up to 'n'.

class Solution {
public:
    vector<vector<int>> res;    // Stores the resulting combinations.
    vector<int> tmpVec;          // Temporary vector to hold a combination during backtracking.
    
    // Function to find all combinations of 'k' numbers that add up to 'n'.
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrackSum(k, n, 0, 1); // Start backtracking with initial values.
        return res;               // Return the resulting combinations.
    }
    
    // Backtracking function to explore combinations.
    void backtrackSum(int k, int tar, int sum, int startIdx){
        // Base case: if 'k' numbers are selected and their sum is equal to 'n', add the combination to the result.
        if(k == 0){
            if(tar == sum){
                res.push_back(tmpVec);
                return;
            }   
        }
        
        // Explore all possibilities for the next number in the combination.
        for(int i = startIdx; i <= 9; i++){
            sum += i;
            tmpVec.push_back(i); // Include the current number in the combination.

            if(sum > tar){
                sum -= i;
                tmpVec.pop_back();  
                return;  
            }
            
            // Recursively call backtracking to explore further possibilities.
            backtrackSum(k - 1, tar, sum, i + 1);
            
            // Remove the last number to backtrack and try other combinations.
            sum -= i;
            tmpVec.pop_back();
        }
    }
};
