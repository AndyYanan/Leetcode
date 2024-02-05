class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //Here, M is the size of routes, and KKK is the maximum size of routes[i].
        //Time complexity: O(M2∗K)O(M^2 * K)O(M^2∗K) Space complexity: O(M⋅K)O(M \cdot K)O(M⋅K)
        // routes = [[1,2,7],[3,6,7]], source = 1, target = 6
        unordered_map<int, vector<int>> to_routes; // stop->bus
        for(int i = 0; i < routes.size(); i++){
            for(int j : routes[i]){
                to_routes[j].push_back(i); // {1: [0], 2: [0], 7: [0, 1], 3: [1], 6: [1]}
            }
        }
        
        queue<pair<int, int>> bfs;
        bfs.push(make_pair(source, 0));
        unordered_set<int> seen = {source};
        while(!bfs.empty()){
            int stop = bfs.front().first, bus = bfs.front().second;
            bfs.pop();
            if(stop == target) return bus;
            for(int i : to_routes[stop]){
                for(int j : routes[i]){
                    if(seen.find(j) == seen.end()){
                        seen.insert(j);
                        bfs.push(make_pair(j, bus+1));
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};