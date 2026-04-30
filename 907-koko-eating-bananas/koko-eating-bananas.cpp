class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        long long sum = 0;
        int max = INT_MIN;
        int ans = 0;

        for (int i = 0; i < n; i++){
            sum = sum + piles[i];
            if (piles[i] > max) max = piles[i];
        }

        if (n == h) return max;

        int left = 1;
        int right = max;

        while (left <= right) {

            int mid = left + (right - left) / 2;
            long long total_hours_req = 0;

            // (dividend + divisor - 1) / divisor
            // piles[i] + mid - 1 / mid

            for (int i = 0; i < n; i++) {
                int hours_per_tile = (piles[i] + mid - 1) / mid;
                total_hours_req = total_hours_req + hours_per_tile;
            }

            if (total_hours_req > h) left = mid + 1;
            else if (total_hours_req <= h){
                ans = mid;
                right = mid - 1;
            } 
        }
        return ans;
    }
};