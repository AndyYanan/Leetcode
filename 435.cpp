class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 0;
        
        //method 1
        int cnt = 0;
        auto sort_end = [](const auto &a, const auto &b){return a[1]<b[1];};       
        sort(intervals.begin(), intervals.end(), sort_end);
        vector<int> pre = intervals[0];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0]<pre[1]){
                cnt++;
            }else{
                pre = intervals[i];
            }
        }
        return cnt;

/*
        //method 2
        int cnt = 0;
        auto sort_end = [](const auto &a, const auto &b){return a[1]<b[1];};       
        sort(intervals.begin(), intervals.end(), sort_end);
        vector<int> pre = intervals[0];
        for(int i = 1; i < intervals.size(); ++i){
            if(pre[1] <= intervals[i][0]){
                cnt++;
                pre = intervals[i];
            }
        }
        return intervals.size()-cnt-1;
*/
        
        
/*
        //method 3
        int cnt = 0;
        sort(intervals.begin(), intervals.end());
        vector<int> pre = intervals[0];
       for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0]<pre[1]){
                cnt++;
                if(pre[1] > intervals[i][1]){
                   pre = intervals[i];
                }
            }else{
                pre = intervals[i];
            }
        }
        return cnt;

 */
       
    }
};
