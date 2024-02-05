class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int len = asteroids.size();
        stack<int> st;
        for(int ast: asteroids){
            if(st.empty() || ast > 0){
                st.push(ast);
            }else{
                while(!st.empty() && st.top() > 0 && st.top() < -ast){
                    st.pop();
                }
                if(!st.empty() && st.top() == -ast){
                    st.pop();
                }else if(st.empty() || st.top() < 0){
                    st.push(ast);
                }
            }
        }
        vector<int> res(st.size());
        for(int i = (int)st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
      /*  vector<int> res;
        int len = asteroids.size();
        for(int ast:asteroids){
            while(!res.empty() && res.back() > 0 && res.back < -ast){
                res.pop_back();
            }
            if(res.empty() || ast > 0 || res.back() < 0){
                res.push_back(ast);
            }else if(ast < 0 && res.back() == -ast){
                res.pop_back();
            }
        }
        return res;*/
    }
};