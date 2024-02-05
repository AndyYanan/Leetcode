class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<double> dist(n, INT_MIN);
        dist[start] = 1.00;
        queue<pair<int, double>> q; //node -> probabilities
        q.push({start, 1.00});
        while(!q.empty()){
            int node = q.front().first;
            double prob = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                int newNode = it.first;
                double newProb = it.second;
                if(dist[newNode] < newProb * prob){
                    dist[newNode] = newProb * prob;
                    q.push({newNode, dist[newNode]});
                }
            }
        }
        return dist[end] == INT_MIN ? 0.00 : dist[end];
        /*
        
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int s, int e) {
        vector<double> dist(n);
        dist[s] = 1;
        for(int i = 0; i < n - 1; ++i){
            int updated = false;
            for(int j = 0; j < edges.size(); ++j)
            {  
                int u = edges[j][0], v = edges[j][1];
                if(dist[u] * prob[j] > dist[v]){
                    dist[v] = dist[u] * prob[j];
                    updated = 1;
                }
                if(dist[v] * prob[j] > dist[u]){
                    dist[u] = dist[v] * prob[j];
                    updated = 1;
                }
            }
            if(!updated)
                break;
        }
        return dist[e];
    }
};
    }
};

        */
    }
};