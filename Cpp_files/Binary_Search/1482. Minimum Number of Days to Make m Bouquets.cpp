class Solution {
public:
    int minDays(vector<int>& A, long m, long k) {
        auto p = minmax_element(A.begin(),A.end());
        int  right = *p.second, left =*p.first;
        //left = 1, right = 1e9;
        if (m * k > A.size()) return -1;
        while (left < right) {
            long mid = left + (right - left) / 2;
            long res = 0, adj = 0;
            for (int i = 0; i < A.size(); ++i) {
                if (A[i] > mid) {
                    adj = 0;
                }
                else if (++adj >= k) {
                    res++;
                    adj = 0;
                }
            }
            if (res < m) {
                left = mid + 1;
            }
            else { // include ans, find number of min days
                right = mid;
            }
        }
        return right;
    }
};