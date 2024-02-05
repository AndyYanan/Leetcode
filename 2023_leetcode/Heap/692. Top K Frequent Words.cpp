struct cmp {
    bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
        if(a.first != b.first) {
            return a.first > b.first; // Sort by freq. in ascending order
        }
        else {
            return a.second < b.second; // Sort lexicographically in decending order
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        // use a hashmap to record the freq. of each word
        unordered_map<string, int> freq;
        for(auto word : words){
            freq[word]++;
        }

        // min heap to sort the freq. from low to high
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for(auto it : freq){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> res(k);
        int idx = k - 1;
        while(!pq.empty()){
            // Fill the result vector from the highest freq. to the lowest freq.
            res[idx--] = pq.top().second;
            pq.pop();
        }
        return res;
        

    }
};