class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // Compute how many minutes each monster needs to reach the city
        for(int i = 0; i < dist.size(); i++){
            dist[i] = (dist[i] - 1) / speed[i];
        }
        // sort by arrival time;
        sort(dist.begin(), dist.end());
        for(int i = 0; i < dist.size(); i++){
            // we shoot the monster, until a monster arrives earlier than we can make our next shot
            if(i > dist[i]){
                return i;
            }
        }
        return dist.size();
    }
};