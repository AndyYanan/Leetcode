class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // Create an unordered_map to store the frequency of edges encountered
        unordered_map<int, int> edge_num;
        
        // Initialize a variable to keep track of the maximum frequency of edges
        int max_freq = 0;
        
        // Loop through each row (layer) of the wall
        for (int row = 0; row < wall.size(); row++) {
            // Initialize the edge position to 0 at the beginning of each row
            int edge = 0;
            
            // Loop through each brick in the current row, excluding the last brick (as the last brick's edge is not counted)
            for (int brick = 0; brick < wall[row].size() - 1; brick++) {
                // Get the length of the current brick
                int cur_brick_len = wall[row][brick];
                
                // Increment the edge position by the current brick's length
                edge = edge + cur_brick_len;
                
                // Update the frequency of the current edge in the map
                edge_num[edge]++;
                
                // Update the maximum frequency of edges seen so far
                max_freq = max(max_freq, edge_num[edge]);
            }
        }
        
        // The result will be the number of rows (layers) of the wall minus the maximum frequency of edges
        return wall.size() - max_freq;
    }
};
