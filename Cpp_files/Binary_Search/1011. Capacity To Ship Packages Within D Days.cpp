class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for(int w:weights){
            left = max(left, w); 
            right += w;
        }    
        while(left < right){
            int mid = left + (right-left)/2;
            int needDay = 1, cur = 0;
            for(int w:weights){
                if(cur+w>mid){
                    cur = w;
                    needDay++;
                }else{
                    cur += w;
                }
            }
            if(needDay > days){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
