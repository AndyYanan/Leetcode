class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq; // for frequency of characters
        priority_queue<pair<int, char>> pq;
        string res = "";
        for (char c : s) {
            freq[c]++;
        }
        for (auto [ch, cnt] : freq) {
            pq.push({cnt, ch});
        }
        while (!pq.empty()) {
            res += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return res;

        /*
        unordered_map<char, int> tb;
        for (char c : s) {
            tb[c]++;
        }
        int n = s.size();
        vector<vector<char>> bucket(n + 1);
        for (auto [ch, cnt] : tb) {
            bucket[cnt].push_back(ch);
        }
        string res = "";
        for (int freq = n; freq > 0; freq--) {
            for (char c : bucket[freq]) {
                res.append(freq, c);
            }
        }
        return res;
        */
    }
};