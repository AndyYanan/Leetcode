class Graph {
public:
    // Time: O(V + ElogE)
    // Space: O(V + E)
    vector<vector<pair<int, int>>> adjList;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for(auto& e : edges){
            adjList[e[0]].push_back(make_pair(e[1], e[2]));
        }        
    }
    
    void addEdge(vector<int> e) {
        adjList[e[0]].push_back(make_pair(e[1], e[2]));
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }

    int dijkstra(int start, int end){
        int n = adjList.size();
        vector<int> distance(n, INT_MAX);
        distance[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, start));
        
        while(!pq.empty()){
            int cur_node = pq.top().second;
            int cur_cost = pq.top().first;
            pq.pop();
            if(cur_cost > distance[cur_node]) continue;
            if(cur_node == end) return cur_cost; // because we use a proprity queue, if we reach end, the first cur_cost must be the minimun value
            for(auto& nei : adjList[cur_node]){
                int nei_node = nei.first, nei_cost = nei.second;
                int new_cost = nei_cost + distance[cur_node]; 
                if(new_cost < distance[nei_node]){
                    distance[nei_node] = new_cost;
                    pq.push(make_pair(new_cost, nei_node));
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */