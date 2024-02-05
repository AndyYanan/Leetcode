class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> hash;
        for(int i = 0; i < s.size(); ++i){
            hash[s[i]] = i;
        }
        vector<int> res;
        int left = 0; 
        int right = 0;
        for(int i = 0; i < s.size(); ++i){
            right = max(right, hash[s[i]]);
            if(right == i){
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};