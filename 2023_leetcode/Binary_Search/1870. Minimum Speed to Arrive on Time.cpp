class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 1e9;
        int len = dist.size();
        if(hour <= len-1) return -1;
        while(left < right){
            int mid = left + (right - left)/2;
            double h = 0;
            for(int i = 0; i < len-1; ++i){
                h += (dist[i]+mid-1)/mid;
            }
            h += (double)dist[len-1]/mid;
            if(h > hour){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return right;
    }
};