class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for(auto &n : t){
            map[n]++;
        }
        int cntr = t.size(), head = 0, begin = 0, end = 0, dis = INT_MAX;

        while(end < s.size()){
            if(map[s[end]] > 0) cntr--;
            map[s[end++]]--;
            while(cntr == 0){
                if(end - begin < dis){
                    dis = end - begin;
                    head = begin;
                }
                if(map[s[begin]] == 0) cntr++;
                map[s[begin++]]++;
            }
        }
        return dis != INT_MAX ? s.substr(head, dis):"";
    }
};
