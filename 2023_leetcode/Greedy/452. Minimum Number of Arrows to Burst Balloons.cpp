class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int lastIdx = 0, res = 1;
        lastIdx = points[0][1];
        for(int i = 1; i < points.size(); ++i){
            if(points[i][0] <= lastIdx){
                lastIdx = min(lastIdx, points[i][1]);
            }else{
                res++;
                lastIdx = points[i][1];
            }
        }
        return res;

    }
};