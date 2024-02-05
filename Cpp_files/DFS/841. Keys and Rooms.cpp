class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int room, vector<bool> &vis){
        vis[room] = true;
        for(int i = 0; i < rooms[room].size(); i++){
            if(!vis[rooms[room][i]]){
                dfs(rooms, rooms[room][i], vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size();
        vector<bool> vis(len, false);
        dfs(rooms, 0, vis);
        
        for(int i = 0; i < len; ++i){
            if(!vis[i]){
                return false;
            }
        }
        return true;
        /*stack<int> st;
        unordered_set<int> visited = {0};
        st.push(0);
        while(!st.empty()){
            int room = st.top();
            st.pop();
            for(int key : rooms[room]){
                if(visited.count(key) == 0){
                    visited.insert(key);
                    st.push(key);
                    if(visited.size() == rooms.size()){
                        return true;
                    }
                }
            }
        }
        return visited.size() == rooms.size();*/
    }
};