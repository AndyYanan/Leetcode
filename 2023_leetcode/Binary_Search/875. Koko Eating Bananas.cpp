class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int total = 0;
            for (int i = 0; i < piles.size(); ++i) {
                total += (piles[i] + mid - 1) / mid;
            }
            if (total > h) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
};