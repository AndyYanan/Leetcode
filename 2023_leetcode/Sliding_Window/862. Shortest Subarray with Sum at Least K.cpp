typedef long long ll;
class Solution {
public:
    int shortestSubarray(vector<int>& A, int k) {
        deque<ll> dq;
        ll N = A.size(), res = N + 1;
        for(ll i = 0; i < N; i++){
            if(i > 0) A[i] += (ll)A[i-1];
            if(A[i] >= k) res = min(res, i + 1);
            while(!dq.empty() && (ll)A[i] - (ll)k >= A[dq.front()]){
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            // if A[i] <= A[dq.back()] && i > dq.back();
            // if A[future_i] - A[dq.back()] >= k
            // if A[future_i] - A[i] must be >= k 
            // i will be the better choise
            while(!dq.empty() && A[i] <= A[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res <= N ? res : -1;
    }
};