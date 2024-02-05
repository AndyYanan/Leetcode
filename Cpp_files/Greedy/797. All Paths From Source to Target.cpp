class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmpRes;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        tmpRes.push_back(0);
        dfs(graph, 0);
        return res; 
    }
    void dfs(vector<vector<int>> & graph, int startIdx){
        if(startIdx == graph.size()-1){
            res.push_back(tmpRes);
            return;
        }
        for(int i = 0; i < graph[startIdx].size(); i++){
            tmpRes.push_back(graph[startIdx][i]);
            dfs(graph, graph[startIdx][i]);
            tmpRes.pop_back();
        }
        return;
    }
};
