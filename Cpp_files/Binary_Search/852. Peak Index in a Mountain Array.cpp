class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size()-1, mid;
        while(l < r){
            mid = l + (r-l)/2;
            if(arr[mid] < arr[mid+1]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return r;
        /*for(int i = 0; i < arr.size()-1; ++i){
            if(arr[i] > arr[i+1]){
                return i;
            }
        }
        return 0;*/
    }
};