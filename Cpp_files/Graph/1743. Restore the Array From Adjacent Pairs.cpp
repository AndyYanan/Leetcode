class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // Time complexity: O(n), Space complexity: O(n)
        // adjacentPairs = [[2,1],[3,4],[3,2]]
        // Create the adjacent candidate list using unordered_map
        unordered_map<int, vector<int>> graph;
        // Fill the graph with adjacent list
        // {2: [1, 3], 1: [2], 3: [4, 2], 4: [3]}
        for(auto& pair : adjacentPairs){
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        vector<int> res;

        // Find numbers that have only on adjacent number, this number should be the start or the end number
        // We can start from one of them
        for(auto& entry : graph){
            if(entry.second.size() == 1){
                // res = [1, 2]
                res.push_back(entry.first);
                res.push_back(entry.second[0]);
                break;
            }
        }
        // res = [1, 2]
        // {2: [1, 3], 1: [2], 3: [4, 2], 4: [3]}
        while(res.size() < adjacentPairs.size() + 1){
            int last = res.back(); // 2
            int prev = res[res.size() - 2]; // 1
            vector<int> candidate = graph[last]; // [1, 3]
            // if candidate[0] == prev that means next adjacent number will be candidate[1]
            //    candidate[0] = 1, prev = 1 -> next adj = 3
            int next = candidate[0] == prev ? candidate[1] : candidate[0];
            res.push_back(next);
        }

        return res;
    }
};