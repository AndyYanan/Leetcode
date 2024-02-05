class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = n, i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                //cout << "peak = " << peak << endl;
                res += peak;
                i++;
                if(i == n) return res;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                //cout << "valley = " << valley << endl;
                res += valley;
                i++;
            }
            res -= min(peak, valley); //Keep only the higher peak
        }
        return res;
    }
}; 
/*
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> num(n, 1);

        for(int i = 1; i < n; ++i){
            if(ratings[i-1] < ratings[i]){
                num[i] = num[i-1] + 1;
            }
        }
        for(int i = n-1; i >= 1; --i){
            if(ratings[i] < ratings[i-1]){
                num[i-1] = max(num[i] + 1, num[i-1]);
            }
        }
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += num[i];
        }
        return sum;
    }
};
*/